#pragma once

#include <string>
#include <memory>
#include <functional>

#include <glm/glm.hpp>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{
	class UniqueShader;
	typedef std::shared_ptr<UniqueShader> Shader;

	/**
	 * Compiles shaders into a program and manages access to that program
	 */
	class UniqueShader : public NonCopyable
	{
	public:
		/**
		 * @brief Create a new shader program from source
		 * 
		 * @param vertexShader   Source code of the vertex shader
		 * @param fragmentShader Source code of the fragment shader
		 */
		UniqueShader(const std::string& vertexShader, const std::string& fragmentShader);
		~UniqueShader();

		/**
		 * @brief Creates a shareable UniqueShader. Note that they're SHAREable, not COPYable
		 * 
		 * @param vertexShader   Source code of the vertex shader
		 * @param fragmentShader Source code of the fragment shader
		 * 
		 * @returns Shared pointer to a UniqueShader
		 */
		inline static Shader Share(const std::string& vertexShader, const std::string& fragmentShader)
		{
			return std::make_shared<UniqueShader>(vertexShader, fragmentShader);
		}

		/**
		 * @brief Status of the program creation
		 * 
		 * @returns `true` if shader was successfully created
		 */
		inline bool Good() { return id != 0; }

		/**
		 * @brief Bind this shader program
		 */
		void Use();

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

		bool recording = false;
	};

	typedef ObjectManager<Shader> ShaderManager;
}