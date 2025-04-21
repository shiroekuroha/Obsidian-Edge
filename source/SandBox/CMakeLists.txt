project(sandbox VERSION 0.1.0 LANGUAGES C CXX OBJC OBJCXX)

set(SOURCE_FILES "SandBox.cpp")

add_executable(sandbox ${SOURCE_FILES})

target_link_libraries(sandbox obsidian-edge)

target_include_directories(sandbox
    PRIVATE

    ${CMAKE_SOURCE_DIR}/source/ObsidianEdge/include
    ${CMAKE_SOURCE_DIR}/source/SandBox/include
)

target_compile_options(sandbox 
    PUBLIC

    $<$<CONFIG:Debug>:-Og> 
    $<$<CONFIG:Release>:-O3>
)