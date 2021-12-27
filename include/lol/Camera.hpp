#pragma once

#include <memory>
#include <lol/Transformable.hpp>
#include <lol/Drawable.hpp>

namespace lol
{
	// TODO: Find better name

	/**
	 * @brief A basic camera implementation
	 * 
	 * A base camera object. It hides away part of the interface of a Transformable
	 * (because e.g. scaling doesn't make sense for a camera), and adds some other
	 * transformation functions that are useful for cameras.
	 */
	class CameraBase : public Transformable
	{
	public:
		// "Scaling" doesn't really makes sense for a camera
		void GetScale() = delete;
		void SetScale(const glm::vec3&) = delete;
		void Scale(const glm::vec3&) = delete;

		/**
		 * @brief Makes the camera look at the target position. Only affects rotation.
		 */
		inline void LookAt(const glm::vec3& target)
		{
			transformation = glm::lookAt(position, target, glm::vec3(0.0f, 1.0f, 0.0f));
		}

		/**
		 * @brief Get the cameras view matrix
		 * 
		 * @returns The cameras view matrix
		 */
		inline const glm::mat4& GetView() const
		{
			return transformation;
		}

		/**
		 *@brief Get the cameras projection matrix
		 *
		 * @returns The cameras projection matrix
		 */
		inline const glm::mat4& GetProjection() const
		{
			return projection;
		}

		/**
		 * @brief Alternative rendering syntax
		 * 
		 * @param drawable A Drawable that should be rendered through this camera
		 */
		inline void Draw(Drawable& drawable) const
		{
			drawable.Draw(*this);
		}

	protected:
		glm::mat4 projection;
	};


	/**
	 * @brief A camera using perspective projection
	 */
	class Camera : public CameraBase
	{
	public:
		/**
		 * @brief Constructs a new camera
		 * 
		 * @param fov		FOV of the camera
		 * @param aspect	Aspect ratio of the screen
		 * @param zNear		Near clipping plane
		 * @param zFar		Far clipping plane
		 */
		Camera(float fov = 90.0f, float aspect = 1.0f, float zNear = 0.01f, float zFar = 100.0f)
		{
			projection = glm::perspective(glm::radians(fov), aspect, zNear, zFar);
		}

		/**
		 * @brief Update the camera configuration without affecting its transformation 
		 * 
		 * @param fov		FOV of the camera
		 * @param aspect	Aspect ratio of the screen
		 * @param zNear		Near clipping plane
		 * @param zFar		Far clipping plane
		 */
		inline void Update(float fov, float aspect, float zNear, float zFar)
		{
			projection = glm::perspective(glm::radians(fov), aspect, zNear, zFar);
		}
	};


	/**
	 * @brief A camera using orthographic projection
	 */
	class OrthogonalCamera : public CameraBase
	{
	public:
		/**
		 * @brief Constructs a new camera
		 */
		OrthogonalCamera(float left = -1.0f, float right = 1.0f, float bottom = -1.0f, float top = 1.0f, float zNear = -100.0f, float zFar = 100.0f)
		{
			projection = glm::ortho(left, right, bottom, top, zNear, zFar);
		}

		/**
		 * @brief Update the camera configuration without affecting its transformation
		 */
		inline void Update(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			projection = glm::ortho(left, right, bottom, top, zNear, zFar);
		}
	};

}