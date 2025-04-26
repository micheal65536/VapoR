target_sources(vrclient PRIVATE
    init.cpp
    client_core.cpp
    system.cpp
    compositor.cpp
    input.cpp
    chaperone.cpp
    rendermodel.cpp
    settings.cpp
    screenshot.cpp
    applications.cpp
    extended_display.cpp
    #fake.cpp
    input/action_manager.cpp
    input/mode.cpp
    input/path_handle_registry.cpp
    render/image_capture_helper.cpp
)
