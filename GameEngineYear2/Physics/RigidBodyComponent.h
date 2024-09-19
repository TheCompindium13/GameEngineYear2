#pragma once
#include "Engine/Component.h"
#include "Math/Vector2.h"

namespace GamePhysics
{
	class RigidBodyComponent : public GameEngine::Component
	{
	public:
		RigidBodyComponent();
		GameMath::Vector2 getVelocity() { return m_velocity; }
		void setVelocity(GameMath::Vector2 velocity) { m_velocity = velocity; }

		float getMass() { return m_mass; }
		void setMass(float mass) { m_mass = mass; }
		float getMaxSpeed() { return m_maxSpeed; }

		float getGravity() { return m_gravity; }
		void setGravity(float gravity) { m_gravity = gravity; }

		void applyForce(GameMath::Vector2 force);
		void applyForceToEntity(RigidBodyComponent* rigidbody, GameMath::Vector2 force);

		void fixedUpdate(float fixedDeltaTime) override;
		void resolveCollision(GamePhysics::Collision* collisiondata);
	private:
		GameMath::Vector2 m_velocity;
		GameMath::Vector2 m_position;
		float m_mass = 1;
		float m_gravity = 9.81f;
		float m_maxSpeed = 10000;
	};
}