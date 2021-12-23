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

	class UniqueShader : public NonCopyable
	{
	public:
		UniqueShader(const std::string& vertexShader, const std::string& fragmentShader);
		~UniqueShader();

		inline static Shader Share(const std::string& vertexShader, const std::string& fragmentShader)
		{
			return std::make_shared<UniqueShader>(vertexShader, fragmentShader);
		}

		inline bool Good() { return id != 0; }
		void Use();

		void SetUniform(const std::string& name, const glm::mat4& value);
		void SetUniform(const std::string& name, const glm::vec4& value);

	private:
		unsigned int id;

		bool recording = false;
	};

	typedef ObjectManager<Shader> ShaderManager;
}