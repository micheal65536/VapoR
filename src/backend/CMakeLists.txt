target_sources(vrclient PRIVATE
    backend.cpp
    frame_state.cpp
    frame_queue.cpp
    haptic_queue.cpp
    event_queue.cpp
    legacy_input.cpp
    device_property_set.cpp
    render_model.cpp
    path_handle_registry.cpp
    opengl.cpp
    openxr.cpp
)
add_subdirectory(input)

add_subdirectory(input_profiles)
