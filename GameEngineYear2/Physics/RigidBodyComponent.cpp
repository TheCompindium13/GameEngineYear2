#include "RigidBodyComponent.h"
#include "Engine/TransformComponent.h"
#include "Engine/Entity.h"
#include "Math/Vector3.h"
#include "Physics/ColliderComponent.h"
void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector2 force)
{
	m_velocity = m_velocity + force / getMass();
}

void GamePhysics::RigidBodyComponent::applyForceToEntity(RigidBodyComponent* rigidbody, GameMath::Vector2 force)
{
	applyForce(force * -1);
	otherRigidBody = rigidbody;
	rigidbody->applyForce(force );
}

void GamePhysics::RigidBodyComponent::fixedUpdate(float fixedDeltaTime)
{
	GameMath::Vector2 position = getOwner()->getTransform()->getLocalPosition();
	getOwner()->getTransform()->setLocalPosition(position + m_velocity * fixedDeltaTime);

	GameMath::Vector2 gravity = { 0, getGravity() };
	applyForce(gravity * getMass());
}

void GamePhysics::RigidBodyComponent::resolveCollision(GamePhysics::Collision* collisiondata)
{
	GameMath::Vector2 relativeVelocity = getVelocity() - collisiondata->collider->getRigidBody()->getVelocity();
	float normalVelocity = relativeVelocity.dotProduct(relativeVelocity, collisiondata->normal);




}
