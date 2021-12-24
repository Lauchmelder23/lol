cmake_minimum_required (VERSION 3.8)

project("lol")

set(CMAKE_CXX_STANDARD 17)

find_package(GLM)
if(NOT GLM_FOUND)
	message(STATUS "Could not find GLM on system, including from source instead")
	add_subdirectory("vendor/glm")

	set(GLM_INCLUDE_DIRS glm)
	set(GLM_LIBRARIES glm)
endif()

add_library(lol STATIC 
	"src/Drawable.cpp"
	"src/Transformable.cpp"
	"src/Shader.cpp"
	"src/VertexArrayObject.cpp"
	"vendor/glad/src/glad.c"
 "include/lol/Texture.hpp" "src/Texture.cpp"       "include/lol/util/Enums.hpp"  "include/lol/Buffer.hpp" "src/Buffer.cpp" "include/lol/buffers/VertexBuffer.hpp" "src/buffers/VertexBuffer.cpp" "include/lol/buffers/ElementBuffer.hpp" "src/buffers/ElementBuffer.cpp")

target_include_directories(lol PUBLIC 
	${GLM_INCLUDE_DIRS}
	vendor/glad/include
	include 
)

target_link_libraries(lol PUBLIC
	${GLM_LIBRARIES}
)