project(obsidian-edge VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES
	${PROJECT_SOURCE_DIR}/source/Engine/Application.cpp
	${PROJECT_SOURCE_DIR}/source/Logger/Logger.cpp
)

add_library(obsidian-edge SHARED ${SOURCE_FILES})

target_include_directories(obsidian-edge PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/source/vendor/glfw/include
	${CMAKE_SOURCE_DIR}/source/vendor/spdlog/include
)

target_compile_definitions(obsidian-edge PUBLIC OE_LIB_EXPORT $<$<CONFIG:Debug>:DEBUG> $<$<CONFIG:Release>:>)

find_package(GLEW REQUIRED)
target_link_libraries(obsidian-edge glfw spdlog GLEW::GLEW)