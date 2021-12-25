#pragma once

#include <string>
#include <memory>
#include <functional>

#include <glm/glm.hpp>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{
	/**
	 * Compiles shaders into a program and manages access to that program
	 */
	class Shader : public NonCopyable
	{
	public:
		/**
		 * @brief Create a new shader program from source
		 * 
		 * @param vertexShader   Source code of the vertex shader
		 * @param fragmentShader Source code of the fragment shader
		 */
		Shader(const std::string& vertexShader, const std::string& fragmentShader);
		~Shader();

		/**
		 * @brief Status of the program creation
		 * 
		 * @returns `true` if shader was successfully created
		 */
		inline bool Good() { return id != 0; }

		/**
		 * @brief Bind this shader program
		 */
		void Bind();
		void Unbind();

		/**
		 * Set a float uniform
		 *
		 * @param name  Name of the uniform
		 * @param value Value of the uniform
		 */
		void SetUniform(const std::string& name, float value);

		/**
		 * Set a 4x4 matrix uniform
		 * 
		 * @param name  Name of the uniform
		 * @param value Value of the uniform
		 */
		void SetUniform(const std::string& name, const glm::mat4& value);

		/**
		 * Set a 4 component vector uniform
		 *
		 * @param name  Name of the uniform
		 * @param value Value of the uniform
		 */
		void SetUniform(const std::string& name, const glm::vec4& value);

	private:
		unsigned int id;
	};

	typedef ObjectManager<Shader> ShaderManager;
}