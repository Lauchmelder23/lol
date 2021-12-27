#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace lol
{

	/**
	 * @brief An object with a position, rotation and scale
	 * 
	 * Represents an object in 3D space. This class handles all the
	 * calculations needed to create a model matrix
	 */
	class Transformable
	{
	public:
		/**
		 * @brief Create new object at (0, 0, 0), no rotation and default scaling (1)
		 */
		Transformable();

		virtual ~Transformable() {}

		/**
		 * @brief Get position of the object
		 * 
		 * @return The position of the object
		 */
		const glm::vec3& GetPosition() const;

		/**
		 * @brief Set position of the object
		 *
		 * @param pos The new position of the object
		 */
		void SetPosition(const glm::vec3& pos);

		/**
		 * @brief Move the object
		 *
		 * @param direction Vector to move the object by
		 */
		void Move(const glm::vec3& direction);


		/**
		 * @brief Get rotation of the object in euler angles
		 *
		 * @return The rotation of the object
		 */
		const glm::vec3 GetRotation() const;

		/**
		 * @brief Get the rotation quaternion of the object
		 *
		 * @return The rotation of the object
		 */
		const glm::quat& GetQuaternion() const;

		/**
		 * @brief Set rotation of the object via axis and angle
		 *
		 * @param axis  Axis to rotate the object around
		 * @param angle Angle by which to rotate the object
		 */
		void SetRotation(const glm::vec3& axis, float angle);

		/**
		 * @brief Set rotation of the object via euler angles
		 *
		 * @param eulerAngles  The orientation of the object
		 */
		void SetRotation(const glm::vec3& eulerAngles);

		/**
		 * @brief Rotate object around axis
		 *
		 * @param axis  Axis to rotate the object around
		 * @param angle Angle by which to rotate the object
		 */
		void Rotate(const glm::vec3& axis, float angle);


		/**
		 * @brief Get scale of the object
		 * 
		 * @return Scale of the object
		 */
		const glm::vec3& GetScale() const;

		/**
		 * @brief Set scale of the object
		 *
		 * @param scale New scale of the object
		 */
		void SetScale(const glm::vec3& scale);

		/**
		 * @brief Scale object by some amount
		 *
		 * @param factor By how much to scale the object in all direction
		 */
		void Scale(const glm::vec3& factor);

	private:
		/**
		 * @brief Reconstructs the ultimate transformation matrix
		 */
		void CalculateTransformationMatrix();

	protected:
		glm::mat4 transformation;

		glm::vec3 position, scale;
		glm::quat orientation;
	};

}