add_library(vrclient MODULE)
set_target_properties(vrclient PROPERTIES OUTPUT_NAME vrclient PREFIX "")

find_package(OpenXR REQUIRED CONFIG)
target_link_libraries(vrclient PRIVATE OpenXR::openxr_loader)

pkg_check_modules(OPENGL REQUIRED opengl)
target_link_libraries(vrclient PRIVATE ${OPENGL_LIBRARIES})
target_include_directories(vrclient PRIVATE ${OPENGL_INCLUDE_DIRS})

find_package(VulkanLoader REQUIRED CONFIG)
target_link_libraries(vrclient PRIVATE Vulkan::Loader)

pkg_check_modules(X11 REQUIRED x11)
pkg_check_modules(GLX REQUIRED glx)
target_link_libraries(vrclient PRIVATE ${X11_LIBRARIES} ${GLX_LIBRARIES})
target_include_directories(vrclient PRIVATE ${X11_INCLUDE_DIRS} ${GLX_INCLUDE_DIRS})

pkg_check_modules(NLOHMANN_JSON REQUIRED nlohmann_json)
target_include_directories(vrclient PRIVATE ${NLOHMANN_JSON_INCLUDE_DIRS})

target_include_directories(vrclient PRIVATE .)
add_subdirectory(openvr)
add_subdirectory(backend)
add_subdirectory(config)

option(VAPOR_LOG_TRACE "Enable trace log output" OFF)
option(VAPOR_LOG_SILENT "Silence all log output" OFF)
if (VAPOR_LOG_TRACE)
    target_compile_definitions(vrclient PRIVATE LOG_TRACE)
endif()
if (VAPOR_LOG_SILENT)
    target_compile_definitions(vrclient PRIVATE LOG_SILENT)
endif()
target_compile_definitions(vrclient PRIVATE VAPOR_SYSTEM_DATA_PATH="${CMAKE_INSTALL_FULL_DATADIR}/VapoR")

install(TARGETS vrclient LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/VapoR/bin/linux64)
