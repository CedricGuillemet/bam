file(GLOB_RECURSE SRC_FILES
    Source/*.h
    Source/*.cpp
)

if (EMSCRIPTEN)
    SET(EXE_NAME "index")
else()
    SET(EXE_NAME "App")
endif()

ADD_EXECUTABLE(${EXE_NAME} ${SRC_FILES})

set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/bin )
set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/bin )
set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${CMAKE_SOURCE_DIR}/bin )
set_target_properties(${EXE_NAME} PROPERTIES DEBUG_POSTFIX "_d")
set_target_properties(${EXE_NAME} PROPERTIES RELWITHDEBINFO_POSTFIX "RelWithDebInfo")
set_target_properties(${EXE_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

target_link_libraries(${EXE_NAME} bx)
target_link_libraries(${EXE_NAME} bimg)
target_link_libraries(${EXE_NAME} bgfx)
target_link_libraries(${EXE_NAME} example-common)
target_link_libraries(${EXE_NAME} Shaders)

if(MSVC)
    set_target_properties(${EXE_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
    set_target_properties(${EXE_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
    set_target_properties(${EXE_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS")

    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

if (EMSCRIPTEN)
    set_target_properties(${EXE_NAME} PROPERTIES LINK_FLAGS "-s USE_WEBGL2=1 -s WASM=1 -s FULL_ES3=1 -s ALLOW_MEMORY_GROWTH=1 --shell-file ${CMAKE_CURRENT_SOURCE_DIR}/Source/index.html")
    add_definitions(-D_X86_)
    SET(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_definitions(-DENTRY_CONFIG_IMPLEMENT_MAIN=1)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})