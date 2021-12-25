#include <lol/Drawable.hpp>

namespace lol
{

	void Drawable::Draw(const CameraBase& camera)
	{
		shader->Bind();
		vao->Bind();
		PreRender(camera);

		glDrawElements(NATIVE(type), vao->GetIndexCount(), GL_UNSIGNED_INT, nullptr);
	}

	void Drawable::SetDrawMode(DrawMode type)
	{
		this->type = type;
	}

}