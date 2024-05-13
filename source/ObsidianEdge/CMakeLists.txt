project(obsidian-edge VERSION 0.1.0 LANGUAGES C CXX OBJC OBJCXX)

set(SOURCE_FILES
	${PROJECT_SOURCE_DIR}/source/Engine/Application.cpp
	${PROJECT_SOURCE_DIR}/source/Engine/Logger.cpp
	${PROJECT_SOURCE_DIR}/source/Utility/Vector2.cpp
	${PROJECT_SOURCE_DIR}/source/Utility/Vector2i.cpp
)

add_library(obsidian-edge SHARED ${SOURCE_FILES})

target_precompile_headers(obsidian-edge PRIVATE
	${PROJECT_SOURCE_DIR}/include/PCH.h
)

target_include_directories(obsidian-edge PUBLIC 
	${PROJECT_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/source/vendor/glfw/include
	${CMAKE_SOURCE_DIR}/source/vendor/spdlog/include
)

target_compile_definitions(obsidian-edge PUBLIC 
	OE_LIB_EXPORT

	$<$<CONFIG:Debug>:OE_DEBUG>
)

target_compile_options(obsidian-edge PUBLIC
	$<$<CONFIG:Debug>:-Og> 
	$<$<CONFIG:Release>:-O3>
)

find_package(GLEW REQUIRED)
target_link_libraries(obsidian-edge glfw spdlog GLEW::GLEW)