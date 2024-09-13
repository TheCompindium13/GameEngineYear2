#include "RigidBodyComponent.h"
#include "Engine/TransformComponent.h"
#include "Engine/Entity.h"
#include "Physics/ColliderComponent.h"

GamePhysics::RigidBodyComponent::RigidBodyComponent() : GameEngine::Component()
{
    
}
void GamePhysics::RigidBodyComponent::applyForce(GameMath::Vector2 force)
{
	m_velocity = m_velocity + force / getMass();
}

void GamePhysics::RigidBodyComponent::applyForceToEntity(RigidBodyComponent* rigidbody, GameMath::Vector2 force)
{
	applyForce(force * -1);
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
    // Check if collisiondata and collider are valid
    //if (!collisiondata || !collisiondata->collider) return;

    // Get the colliding rigid body from the other entity
    RigidBodyComponent* otherBody = collisiondata->collider->getRigidBody();

    // Check if otherBody is valid
    if (!otherBody) return; // No collision resolution if the other body is not dynamic

    // Get the masses of both bodies
    float mass1 = getMass();
    float mass2 = otherBody->getMass();

    // If both masses are zero, both bodies are static; no resolution needed
    if (mass1 == 0 && mass2 == 0) return;

    // Compute relative velocity
    GameMath::Vector2 relativeVelocity = getVelocity() - otherBody->getVelocity();
    GameMath::Vector2 normal = collisiondata->normal;

    if (mass1 == 0 || mass2 == 0) {
        // Handle the case where one of the bodies is static
        if (mass1 == 0) 
        {
            // This body is static; apply impulse to the other body
            float j = 2 * GameMath::Vector2::dotProduct(relativeVelocity, normal);
            GameMath::Vector2 impulse = normal * j;
            applyForceToEntity(otherBody, impulse);
        }
        else {
            // Other body is static; apply impulse to this body
            float j = 2 * GameMath::Vector2::dotProduct(relativeVelocity, normal);
            GameMath::Vector2 impulse = normal * j;
            applyForceToEntity(otherBody, impulse); // Apply negative impulse to the static body
        }
    }
    else {
        // Both bodies are dynamic
        float normalVelocity = GameMath::Vector2::dotProduct(relativeVelocity, normal);
        float massSumInverse = 1.0f / mass1 + 1.0f / mass2;
        float j = 2 * normalVelocity / massSumInverse;

        GameMath::Vector2 impulse = normal * j;

        // Apply impulse to both bodies
        applyForceToEntity(otherBody, impulse); // Apply impulse to the other body
        applyForceToEntity(otherBody, impulse); // Apply negative impulse to this body
    }
}
