cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_GENERATOR Ninja)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

project(obsidian-edge VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;Dist")

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/int/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}_${CMAKE_SYSTEM_PROCESSOR})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin/${CMAKE_SYSTEM_PROCESSOR}-${CMAKE_SYSTEM_NAME}-${CMAKE_BUILD_TYPE}/${CMAKE_PROJECT_NAME})

# Platform dependant configs

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

# Add submodules

add_subdirectory(source/vendor/glfw)
add_subdirectory(source/vendor/spdlog)
add_subdirectory(source/ObsidianEdge)
add_subdirectory(source/SandBox)

# Testing

enable_testing()

include(GoogleTest)

include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(gtest)

add_executable(testObsidianEdge test/main_test.cpp)

target_link_libraries(testObsidianEdge gtest gtest_main)
target_link_libraries(testObsidianEdge obsidian-edge)

target_include_directories(testObsidianEdge PUBLIC 
    ${PROJECT_SOURCE_DIR}/source/ObsidianEdge/include
)

add_test(NAME testObsidianEdge COMMAND testObsidianEdge)