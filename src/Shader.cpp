#include <lol/Shader.hpp>

#include <iostream>	

#include <glm/gtc/type_ptr.hpp>
#include <glad/glad.h>	

#define IMPLEMENT_UNIFORM_FUNCTION(type, func) \
inline 

namespace lol
{

	Shader::Shader(const std::string& vertexShader, const std::string& fragmentShader) :
		id(0)
	{
		GLint success;
		GLchar infoLog[512];

		GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
		const char* vertexShaderSource = vertexShader.c_str();
		glShaderSource(vertexShaderID, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShaderID);

		glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
			std::cerr << "Vertex shader creation failed: \n" << infoLog << std::endl;

			glDeleteShader(vertexShaderID);
			return;
		}

		GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fragmentShaderSource = fragmentShader.c_str();
		glShaderSource(fragmentShaderID, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShaderID);

		glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
			std::cerr << "Fragment shader creation failed: \n" << infoLog << std::endl;

			glDeleteShader(fragmentShaderID);
			glDeleteShader(vertexShaderID);
			return;
		}

		id = glCreateProgram();
		glAttachShader(id, vertexShaderID);
		glAttachShader(id, fragmentShaderID);
		glLinkProgram(id);

		glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(fragmentShaderID, 512, NULL, infoLog);
			std::cerr << "Shader program linking failed: \n" << infoLog << std::endl;

			glDeleteShader(fragmentShaderID);
			glDeleteShader(vertexShaderID);

			id = 0;

			return;
		}

		glDeleteShader(fragmentShaderID);
		glDeleteShader(vertexShaderID);
	}

	Shader::~Shader()
	{
		glDeleteProgram(id);
	}

	void Shader::Bind()
	{
		glUseProgram(id);
	}

	void Shader::Unbind()
	{
		glUseProgram(0);
	}

	void Shader::SetUniform(const std::string& name, int value)
	{
		GLint location = glGetUniformLocation(id, name.c_str());
		if (location == -1)
			return;

		glUniform1i(location, value);
	}

	void Shader::SetUniform(const std::string& name, float value)
	{
		GLint location = glGetUniformLocation(id, name.c_str());
		if (location == -1)
			return;

		glUniform1f(location, value);
	}

	void Shader::SetUniform(const std::string& name, const glm::mat4& value)
	{
		GLint location = glGetUniformLocation(id, name.c_str());
		if (location == -1)
			return;

		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}

	void Shader::SetUniform(const std::string& name, const glm::vec2& value)
	{
		GLint location = glGetUniformLocation(id, name.c_str());
		if (location == -1)
			return;

		glUniform2fv(location, 1, glm::value_ptr(value));
	}

	void Shader::SetUniform(const std::string& name, const glm::vec4& value)
	{
		GLint location = glGetUniformLocation(id, name.c_str());
		if (location == -1)
			return;

		glUniform4fv(location, 1, glm::value_ptr(value));
	}

}