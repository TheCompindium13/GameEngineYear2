#pragma once
#include "ColliderComponent.h"
#include "Engine/TransformComponent.h"

namespace GamePhysics
{
	class AABBColliderComponent : public ColliderComponent
	{
		AABBColliderComponent(float width, float height) : ColliderComponent() { m_width = width, m_height = height; }
		/// <summary>
        /// The width of the collider
        /// </summary>
		float getWidth() { return m_width; }
		/// <summary>
		/// The height of the collider
		/// </summary>
		float getHeight() { return m_height; }

		/// <summary>
		/// The position of the left side of the collider
		/// </summary>
		float getLeft();

		/// <summary>
		/// The position of the right side of the collider
		/// </summary>
		float getRight();

		/// <summary>
		/// The position of the top of the collider
		/// </summary>
		float getTop();

		/// <summary>
		/// The position of the bottom of the collider
		/// </summary>
		float getBottom();


		GamePhysics::Collision* checkCollisionCircle(CircleColliderComponent* other) override;
		GamePhysics::Collision* checkCollisionAABB(AABBColliderComponent* other) override;


	private:
		float m_width;
		float m_height;
	};
}