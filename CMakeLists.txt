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
	"src/Texture.cpp"  
	"src/Buffer.cpp" 
	"src/buffers/VertexBuffer.cpp" 
	"src/buffers/ElementBuffer.cpp"
	"src/Image.cpp"
	"src/ObjectManager.cpp" 
	"src/Layer.cpp" 
)

target_include_directories(lol PUBLIC 
	${GLM_INCLUDE_DIRS}
	vendor/glad/include
	vendor/stbi
	include 
)

target_link_libraries(lol PUBLIC
	${GLM_LIBRARIES}
)