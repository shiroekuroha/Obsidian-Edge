project(sandbox VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES "SandBox.cpp")

add_executable(sandbox ${SOURCE_FILES})

target_link_libraries(sandbox obsidian-edge)


target_include_directories(sandbox PRIVATE
	${CMAKE_SOURCE_DIR}/source/ObsidianEdge/include
)
