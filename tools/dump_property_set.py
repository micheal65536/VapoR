#!/usr/bin/env python3

import sys
import openvr
import json

if len(sys.argv) != 3:
    print("Usage: [device_index] [outfile]")
    exit(1)

openvr.init(openvr.VRApplication_Scene)
i_system = openvr.IVRSystem()

device_index = int(sys.argv[1])

def try_get_property(id, optional=False):
    try:
        return i_system.getStringTrackedDeviceProperty(device_index, id)
    except openvr.error_code.TrackedPropertyError as error:
        if optional:
            if error.error_value == 4 or error.error_value == 2 or error.error_value == 5:
                return None
        print(f"Could not get property {id}, error {error.error_value}")
        return None

properties = {}
properties['system_name'] = try_get_property(1000)
properties['model_name'] = try_get_property(1001)
properties['serial_number'] = try_get_property(1002)
properties['manufacturer_name'] = try_get_property(1005)
properties['registered_device_type'] = try_get_property(1036)
attached_device_id = try_get_property(3000, optional=True)
if attached_device_id != None:
    properties['attached_device_id'] = attached_device_id

with open(sys.argv[2], 'wt') as file:
    json.dump(properties, file)
