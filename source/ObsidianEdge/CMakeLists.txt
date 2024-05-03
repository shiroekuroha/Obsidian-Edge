project(obsidian-edge VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES source/Engine/ObsidianEdge.cpp)

add_library(obsidian-edge SHARED ${SOURCE_FILES})

target_include_directories(obsidian-edge PRIVATE 
	include 
	${CMAKE_SOURCE_DIR}/source/vendor/glfw/include
	${CMAKE_SOURCE_DIR}/source/vendor/spdlog/include
)

target_compile_definitions(obsidian-edge PUBLIC LIB_EXPORT $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:>)

find_package(GLEW REQUIRED)
target_link_libraries(obsidian-edge glfw spdlog GLEW::GLEW)