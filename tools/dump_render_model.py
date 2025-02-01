#!/usr/bin/env python3

import sys
import openvr
import os
import json
import array
import numpy as np

if len(sys.argv) != 3:
    print("Usage: [model_name] [outdir]")
    exit(1)

def require_directory(dir):
    try:
        os.mkdir(dir)
    except FileExistsError as error:
        pass

model_name = sys.argv[1]
outdir = sys.argv[2]
require_directory(outdir)

openvr.init(openvr.VRApplication_Scene)
i_render_models = openvr.IVRRenderModels()

print("Building model definition")

model_definition = {}
model_definition['name'] = model_name
model_definition['components'] = []

component_count = i_render_models.getComponentCount(model_name)
component_model_names = {}
print(f"  Model has {component_count} components")
for i in range(component_count):
    component_name = i_render_models.getComponentName(model_name, i)
    component_model_name = i_render_models.getComponentRenderModelName(model_name, component_name)

    button_mask = i_render_models.getComponentButtonMask(model_name, component_name)
    button_mask_list = []
    if button_mask & (1 << openvr.k_EButton_System) != 0:
        button_mask_list.append('system')
    if button_mask & (1 << openvr.k_EButton_ApplicationMenu) != 0:
        button_mask_list.append('menu')
    if button_mask & (1 << openvr.k_EButton_Grip) != 0:
        button_mask_list.append('grip')
    if button_mask & (1 << openvr.k_EButton_DPad_Left) != 0:
        button_mask_list.append('dpad_left')
    if button_mask & (1 << openvr.k_EButton_DPad_Up) != 0:
        button_mask_list.append('dpad_up')
    if button_mask & (1 << openvr.k_EButton_DPad_Right) != 0:
        button_mask_list.append('dpad_right')
    if button_mask & (1 << openvr.k_EButton_DPad_Down) != 0:
        button_mask_list.append('dpad_down')
    if button_mask & (1 << openvr.k_EButton_A) != 0:
        button_mask_list.append('button_a')
    if button_mask & (1 << openvr.k_EButton_Axis0) != 0:
        button_mask_list.append('axis0')
    if button_mask & (1 << openvr.k_EButton_Axis1) != 0:
        button_mask_list.append('axis1')
    if button_mask & (1 << openvr.k_EButton_Axis2) != 0:
        button_mask_list.append('axis2')
    if button_mask & (1 << openvr.k_EButton_Axis3) != 0:
        button_mask_list.append('axis3')
    if button_mask & (1 << openvr.k_EButton_Axis4) != 0:
        button_mask_list.append('axis4')

    controller_mode = openvr.RenderModel_ControllerMode_State_t()
    controller_mode.bScrollWheelVisible = False
    controller_state = openvr.VRControllerState_t()
    controller_state.ulButtonsTouched = 0
    controller_state.ulButtonsPressed = 0
    for j in range(5):
        controller_state.rAxis[j].x = 0.0
        controller_state.rAxis[j].y = 0.0
    (success, component_state) = i_render_models.getComponentState(model_name, component_name, controller_state, controller_mode)
    assert success

    static = (component_state.uProperties & openvr.VRComponentProperty_IsStatic) != 0
    visible = (component_state.uProperties & openvr.VRComponentProperty_IsVisible) != 0
    renderTransform = np.array(component_state.mTrackingToComponentRenderModel.m)
    localSpaceTransform = np.array(component_state.mTrackingToComponentLocal.m)

    print(f"  Got component {component_name} (static: {static}, visible: {visible})")

    model_definition['components'].append({"name": component_name, "has_model": None, "static": static, "visible": visible, "buttons": button_mask_list, "transform": {"render": renderTransform.tolist(), "local_space": localSpaceTransform.tolist()}})
    component_model_names[component_name] = component_model_name

def dump_model(model_name, file_path):
    while True:
        try:
            model = i_render_models.loadRenderModel_Async(model_name)
            break
        except openvr.error_code.RenderModelError_Loading as error:
            continue

    ia = array.array('I')
    fa = array.array('f')
    sa = array.array('H')
    with open(file_path, 'wb') as file:
        ia.clear()
        ia.append(model.unVertexCount)
        ia.tofile(file)
        for i in range(model.unVertexCount):
            vertex = model.rVertexData[i]
            fa.clear()
            fa.append(vertex.vPosition[0])
            fa.append(vertex.vPosition[1])
            fa.append(vertex.vPosition[2])
            fa.append(vertex.vNormal[0])
            fa.append(vertex.vNormal[1])
            fa.append(vertex.vNormal[2])
            fa.append(vertex.rfTextureCoord[0])
            fa.append(vertex.rfTextureCoord[1])
            fa.tofile(file)
        ia.clear()
        ia.append(model.unTriangleCount)
        ia.tofile(file)
        for i in range(model.unTriangleCount):
            sa.clear()
            sa.append(model.rIndexData[i * 3 + 0])
            sa.append(model.rIndexData[i * 3 + 1])
            sa.append(model.rIndexData[i * 3 + 2])
            sa.tofile(file)

print("Dumping models")
print("  Dumping base model")
dump_model(model_name, f"{outdir}/{model_name}.bin")
for component in model_definition['components']:
    component_name = component['name']
    component_model_name = component_model_names[component_name]
    if component_model_name != "":
        print(f"  Dumping component model {component_name} ({component_model_name})")
        component['has_model'] = True
        require_directory(f"{outdir}/{model_name}")
        dump_model(component_model_name, f"{outdir}/{model_name}/{component_name}.bin")
    else:
        print(f"  Component {component_name} does not have a model")
        component['has_model'] = False

print("Saving model definition")

with open(f"{outdir}/{model_name}.json", 'wt') as file:
    json.dump(model_definition, file)
