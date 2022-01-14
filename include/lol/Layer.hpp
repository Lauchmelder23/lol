#pragma once

#include <string>

namespace lol
{
	class CameraBase;

	class Layer
	{
	public:
		Layer(const std::string& debugName);
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}

		virtual void OnUpdate() {}
		virtual void OnRender(CameraBase& camera) {}

		inline const std::string& GetDebugName() { return debugName; }

	private:
		std::string debugName;
	};

}