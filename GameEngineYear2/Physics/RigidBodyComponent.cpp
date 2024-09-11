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
    // Get the colliding rigid body
    RigidBodyComponent* otherBody = collisiondata->collider->getRigidBody();
    if (!otherBody) return;

    // Compute relative velocity
    GameMath::Vector2 relativeVelocity = getVelocity() - otherBody->getVelocity();
    float normalVelocity = relativeVelocity.dotProduct(relativeVelocity, collisiondata->normal);

    // Calculate the coefficient of restitution (bounciness)
    float restitution = 0.5f; // This is an example value; it should be adjustable based on your needs

    // Calculate the impulse scalar
    float massSum = getMass() + otherBody->getMass();
    if (massSum == 0) return; // Avoid division by zero

    float impulseScalar = -(1 + restitution) * normalVelocity / massSum;

    // Calculate impulse vector
    GameMath::Vector2 impulse = impulseScalar * collisiondata->normal;

    // Apply impulse to both bodies
    applyForce(impulse / getMass());
    otherBody->applyForce(impulse / otherBody->getMass());




}
