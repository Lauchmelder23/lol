#pragma once

#include <string>
#include <memory>
#include <functional>

#include <glm/glm.hpp>

#include <lol/NonCopyable.hpp>

namespace lol
{

	class AbstractShader : public NonCopyable
	{
		friend class ShaderFactory;

	public:
		AbstractShader(const std::string& vertexShader, const std::string& fragmentShader);
		~AbstractShader();

		inline bool Good() { return id != 0; }
		void Use();

		void SetUniform(const std::string& name, const glm::mat4& value);
		void SetUniform(const std::string& name, const glm::vec4& value);

	private:
		unsigned int id;

		bool recording = false;
	};

	typedef std::shared_ptr<AbstractShader> Shader;

	class ShaderFactory
	{
	public:
		inline static Shader Produce(const std::string& vertexShader, const std::string& fragmentShader)
		{
			return std::make_shared<AbstractShader>(vertexShader, fragmentShader);
		}
	};

}