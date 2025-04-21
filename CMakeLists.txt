cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_GENERATOR Ninja)

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
add_subdirectory(source/vendor/googletest)
add_subdirectory(source/ObsidianEdge)
add_subdirectory(source/SandBox)

# Testing

# Test Main
add_executable(test_main "test/main_test.cpp")

target_link_libraries(test_main gtest gtest_main pthread)

target_include_directories(test_main
    PUBLIC

    ${CMAKE_SOURCE_DIR}/source/ObsidianEdge/include
)

# Test Utility
add_executable(test_utility "test/utility_test.cpp")

target_link_libraries(test_utility gtest gtest_main pthread)

target_include_directories(test_utility
    PUBLIC

    ${CMAKE_SOURCE_DIR}/source/ObsidianEdge/include
)

# Testing Related
enable_testing()

add_test(NAME MainTest COMMAND test_main)
add_test(NAME UtilityTest COMMAND test_utility)

add_test(NAME MainTest_Memcheck
  COMMAND valgrind
    --error-exitcode=1
    --tool=memcheck
    --leak-check=full
    --show-leak-kinds=definite $<TARGET_FILE:test_main>
)

set_tests_properties(MainTest_Memcheck PROPERTIES
    ENVIRONMENT "DEBUGINFOD_URLS=\"https://debuginfod.archlinux.org\";G_SLICE=always-malloc "
)

add_test(NAME UtilityTest_Memcheck
  COMMAND valgrind
    --error-exitcode=1
    --tool=memcheck
    --leak-check=full
    --show-leak-kinds=definite $<TARGET_FILE:test_utility>
)

set_tests_properties(UtilityTest_Memcheck PROPERTIES
    ENVIRONMENT "DEBUGINFOD_URLS=\"https://debuginfod.archlinux.org\";G_SLICE=always-malloc "
)