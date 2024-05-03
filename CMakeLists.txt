cmake_minimum_required(VERSION 3.5.0)
project(obsidian-edge VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release")

# * Switch build type
# set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_PROJECT_NAME})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR}/${CMAKE_PROJECT_NAME})

if(WIN32)
    # Windows-specific configuration
    message("Configuring for Windows...")
elseif(APPLE)
    # macOS-specific configuration
    message("Configuring for macOS...")
elseif(UNIX)
    # Unix-like platform (Linux, BSD, etc.) configuration
    message("Configuring for Unix-like platform...")
endif()

add_subdirectory(source/vendor/glfw)
add_subdirectory(source/vendor/spdlog)
add_subdirectory(source/ObsidianEdge)
add_subdirectory(source/SandBox)