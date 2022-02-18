################################################################
### BGFX

set(BGFX_BUILD_EXAMPLES OFF CACHE BOOL "")
set(BGFX_USE_DEBUG_SUFFIX OFF CACHE BOOL "Add 'd' suffix to debug output targets")

add_subdirectory(bgfx.cmake EXCLUDE_FROM_ALL)

target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_DEBUG_UNIFORM=0)
target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_MAX_VERTEX_STREAMS=30)
target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_MAX_COMMAND_BUFFER_SIZE=12582912)

if (NOT EMSCRIPTEN)
    target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_MULTITHREADED=1)
    if(APPLE)
        # no Vulkan on Apple but Metal
        target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_RENDERER_VULKAN=0)
        target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_RENDERER_METAL=1)
        target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_WAIT_FOR_FLIP=1)
    elseif(UNIX)
        target_compile_definitions(bgfx PRIVATE BGFX_CONFIG_RENDERER_OPENGL=33)
    endif()
endif()

################################################################
### IMGUI

file(GLOB IMGUI_SRC_FILES
    imgui/*.h
    imgui/*.cpp
)

add_library(imgui ${IMGUI_SRC_FILES})

target_include_directories(imgui
            PUBLIC "imgui"
            )

################################################################
### IMGUIZMO

file(GLOB IMGUIZMO_SRC_FILES
    ImGuizmo/*.h
    ImGuizmo/*.cpp
)

add_library(ImGuizmo ${IMGUIZMO_SRC_FILES})
target_link_libraries(ImGuizmo imgui)
target_include_directories(ImGuizmo
            PUBLIC "ImGuizmo"
            )