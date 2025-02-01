#!/usr/bin/env python3

import sys
import openvr
import ctypes
import struct
import json

known_properties = {
    1000: 'string',
    1001: 'string',
    1002: 'string',
    1003: 'string',
    1004: 'boolean',
    1005: 'string',
    1006: 'string',
    1007: 'string',
    1008: 'string',
    1009: 'string',
    1010: 'boolean',
    1011: 'boolean',
    1012: 'float',
    1013: 'matrix34',
    1014: 'boolean',
    1015: 'boolean',
    1016: 'string',
    1017: 'uint64',
    1018: 'uint64',
    1019: 'uint64',
    1020: 'uint64',
    1021: 'uint64',
    1022: 'uint64',
    1023: 'boolean',
    1024: 'boolean',
    1025: 'boolean',
    1026: 'boolean',
    1027: 'boolean',
    1028: 'string',
    1029: 'int32',
    1030: 'boolean',
    1031: 'string',
    1032: 'boolean',
    1033: 'boolean',
    1034: 'uint64',
    1035: 'string',
    1036: 'string',
    1037: 'string',
    1038: 'boolean',
    1039: 'int32',
    1040: 'int32',
    1041: 'int32',
    1042: 'string',
    1043: 'boolean',
    1044: 'uint64',
    1045: 'string',
    1046: 'string',
    1047: 'boolean',
    1048: 'uint64',
    1049: 'string',
    1050: 'string',
    1051: 'int32',
    1052: 'float',
    1053: 'boolean',
    1054: 'string',

    2000: 'boolean',
    2001: 'float',
    2002: 'float',
    2003: 'float',
    2004: 'uint64',
    2005: 'uint64',
    2006: 'uint64',
    2007: 'boolean',
    2008: 'int32',
    2009: 'float',
    2010: 'float',
    2011: 'int32',
    2012: 'string',
    2013: 'string',
    2014: 'float',
    2015: 'int32',
    2016: 'matrix34',
    2017: 'int32',
    2018: 'float',
    2019: 'float',
    2020: 'float',
    2021: 'string',
    2022: 'float',
    2023: 'float',
    2024: 'float',
    2025: 'float',
    2026: 'float',
    2027: 'uint64',
    2028: 'string',
    2029: 'uint64',
    2030: 'uint64',
    2031: 'uint64',
    2032: 'uint64',
    2033: 'int32',
    2034: 'float',
    2035: 'float',
    2036: 'boolean',
    2037: 'boolean',
    2038: 'int32',
    2039: 'int32',
    2040: 'int32',
    2041: 'binary',
    2042: 'float',
    2043: 'boolean',
    2044: 'boolean',
    2045: 'uint64',
    2048: 'string',
    2049: 'int32',
    2050: 'int32',
    2051: 'string',
    2052: 'string',
    2053: 'string',
    2054: 'boolean',
    2055: 'array matrix34',
    2056: 'int32',
    2057: 'boolean',
    2058: 'boolean',
    2059: 'boolean',
    2060: 'float',
    2061: 'uint64',
    2062: 'uint64',
    2063: 'matrix34',
    2064: 'vector3',
    2065: 'vector3',
    2066: 'vector3',
    2067: 'vector3',
    2069: 'boolean',
    2070: 'uint64',
    2071: 'array vector4',
    2072: 'array int32',
    2073: 'array float',
    2074: 'string',
    2075: 'int32',
    2076: 'boolean',
    2077: 'string',
    2078: 'boolean',
    2079: 'boolean',
    2080: 'array float',
    2081: 'boolean',
    2082: 'vector3',
    2083: 'vector3',
    2084: 'boolean',
    2085: 'boolean',
    2086: 'float',
    2087: 'float',
    2088: 'float',
    2089: 'float',
    2090: 'string',
    2091: 'float',
    2092: 'string',
    2093: 'boolean',
    2094: 'boolean',
    2095: 'string',
    2096: 'boolean',
    2100: 'float',
    2101: 'float',
    2102: 'boolean',
    2103: 'boolean',
    2104: 'boolean',
    2105: 'boolean',
    2106: 'boolean',
    2107: 'boolean',
    2108: 'boolean',
    2110: 'int32',
    2111: 'int32',
    2112: 'int32',
    2113: 'int32',
    2114: 'int32',
    2115: 'boolean',
    2200: 'int32',
    2201: 'int32',
    2202: 'int32',
    2203: 'int32',
    2204: 'int32',
    2205: 'int32',
    2206: 'int32',
    2207: 'int32',
    2208: 'int32',
    2300: 'string',
    2301: 'string',
    2302: 'float',
    2303: 'boolean',
    2304: 'boolean',
    2305: 'float',
    2306: 'boolean',
    2307: 'boolean',
    2308: 'float',
    2309: 'boolean',

    3000: 'string',
    3001: 'uint64',
    3002: 'int32',
    3003: 'int32',
    3004: 'int32',
    3005: 'int32',
    3006: 'int32',
    3007: 'int32'
}

if len(sys.argv) != 3:
    print("Usage: [device_index] [outfile]")
    exit(1)

openvr.init(openvr.VRApplication_Scene)
i_system = openvr.IVRSystem()

device_index = int(sys.argv[1])

properties = []
for id, type in known_properties.items():
    try:
        if type == 'boolean':
            value = i_system.getBoolTrackedDeviceProperty(device_index, id) != 0
        elif type == 'float':
            value = i_system.getFloatTrackedDeviceProperty(device_index, id)
        elif type == 'int32':
            value = i_system.getInt32TrackedDeviceProperty(device_index, id)
        elif type == 'uint64':
            value = i_system.getUint64TrackedDeviceProperty(device_index, id)
        elif type == 'string':
            value = i_system.getStringTrackedDeviceProperty(device_index, id)
        elif type == 'matrix34':
            value = i_system.getMatrix34TrackedDeviceProperty(device_index, id)
        elif type.startswith('array '):
            element_type = type[len('array '):]
            type = 'array'
            if element_type == 'boolean':
                property_type = openvr.k_unBoolPropertyTag
            elif element_type == 'float':
                property_type = openvr.k_unFloatPropertyTag
            elif element_type == 'int32':
                property_type = openvr.k_unInt32PropertyTag
            elif element_type == 'uint64':
                property_type = openvr.k_unUint64PropertyTag
            elif element_type == 'string':
                property_type = openvr.k_unStringPropertyTag
            elif element_type == 'double':
                property_type = openvr.k_unDoublePropertyTag
            elif element_type == 'matrix34':
                property_type = openvr.k_unHmdMatrix34PropertyTag
            elif element_type == 'matrix44':
                property_type = openvr.k_unHmdMatrix44PropertyTag
            elif element_type == 'vector2':
                property_type = openvr.k_unHmdVector2PropertyTag
            elif element_type == 'vector3':
                property_type = openvr.k_unHmdVector3PropertyTag
            elif element_type == 'vector4':
                property_type = openvr.k_unHmdVector4PropertyTag
            else:
                property_type = None
            if property_type != None:
                size = i_system.getArrayTrackedDeviceProperty(device_index, id, property_type, None, 0)
                array = (ctypes.c_uint8 * size)(*([0] * size))
                i_system.getArrayTrackedDeviceProperty(device_index, id, property_type, array, size)
                value_bytes = bytes(array)
                if element_type == 'boolean':
                    value = [i[0] for i in struct.iter_unpack('=?', value_bytes)]
                elif element_type == 'float':
                    value = [i[0] for i in struct.iter_unpack('=f', value_bytes)]
                elif element_type == 'int32':
                    value = [i[0] for i in struct.iter_unpack('=i', value_bytes)]
                elif element_type == 'uint64':
                    value = [i[0] for i in struct.iter_unpack('=Q', value_bytes)]
                elif element_type == 'string':
                    value = []
                    v = ""
                    for b in value_bytes:
                        if b != 0:
                            v += chr(b)
                        else:
                            value.append(v)
                elif element_type == 'double':
                    value = [i[0] for i in struct.iter_unpack('=d', value_bytes)]
                elif element_type == 'matrix34':
                    value = [[[i[0], i[1], i[2], i[3]], [i[4], i[5], i[6], i[7]], [i[8], i[9], i[10], i[11]]] for i in struct.iter_unpack('=ffffffffffff', value_bytes)]
                elif element_type == 'matrix44':
                    value = [[[i[0], i[1], i[2], i[3]], [i[4], i[5], i[6], i[7]], [i[8], i[9], i[10], i[11]], [i[12], i[13], i[14], i[15]]] for i in struct.iter_unpack('=ffffffffffffffff', value_bytes)]
                elif element_type == 'vector2':
                    value = [[i[0], i[1]] for i in struct.iter_unpack('=ff', value_bytes)]
                elif element_type == 'vector3':
                    value = [[i[0], i[1], i[2]] for i in struct.iter_unpack('=fff', value_bytes)]
                elif element_type == 'vector4':
                    value = [[i[0], i[1], i[2], i[3]] for i in struct.iter_unpack('=ffff', value_bytes)]
                else:
                    value = None
            else:
                value = None
        else:
            value = None

        if value != None:
            if type == 'array':
                property = {
                    'id': id,
                    'type': type,
                    'element_type': element_type,
                    'value': value
                }
            else:
                property = {
                    'id': id,
                    'type': type,
                    'value': value
                }
            properties.append(property)
    except openvr.error_code.TrackedPropertyError as error:
        print(f"{id} {error.error_value}")

with open(sys.argv[2], 'wt') as file:
    json.dump(properties, file)
