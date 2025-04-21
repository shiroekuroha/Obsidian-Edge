project(obsidian-edge VERSION 0.1.0 LANGUAGES C CXX OBJC OBJCXX)

set(SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/source/Engine/Core/Application.cpp
    ${PROJECT_SOURCE_DIR}/source/Engine/Core/Logger.cpp

    ${PROJECT_SOURCE_DIR}/source/Engine/Core/Window.cpp
    ${PROJECT_SOURCE_DIR}/source/Engine/Platform/LinuxWindow.cpp
    ${PROJECT_SOURCE_DIR}/source/Engine/Platform/WindowsWindow.cpp
)

string(TOUPPER ${CMAKE_SYSTEM_NAME} OE_PLATFORM_NAME)

add_library(obsidian-edge
    SHARED

    ${SOURCE_FILES}
)

target_precompile_headers(obsidian-edge
    PRIVATE

    ${PROJECT_SOURCE_DIR}/include/Engine/Core/PCH.h
)

target_include_directories(obsidian-edge
    PUBLIC

    ${PROJECT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/source/vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/source/vendor/spdlog/include
)

target_compile_definitions(obsidian-edge
    PUBLIC 

    OE_PLATFORM_${OE_PLATFORM_NAME}
    OE_LIB_EXPORT
    $<$<CONFIG:Debug>:OE_ENABLE_ASSERTS>
    $<$<CONFIG:Debug>:OE_DEBUG>
)

target_compile_options(obsidian-edge 
    PUBLIC

    $<$<CONFIG:Debug>:-Og> 
    $<$<CONFIG:Release>:-O3>
)

find_package(GLEW REQUIRED)
target_link_libraries(obsidian-edge glfw spdlog GLEW::GLEW)
