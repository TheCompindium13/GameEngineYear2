#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    GameMath::Vector2 otherPosition = other->getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 direction = otherPosition - position;
    float distance = direction.getMagnitude();

    if (distance > other->m_radius + m_radius)
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();
    collisionData->collider = other;
    collisionData->normal = direction.getNormalized();
    collisionData->contactPoint = position + direction.getNormalized() * getRadius();
    collisionData->penetrationDistance = other->m_radius + m_radius - distance;


    return collisionData;
}

GamePhysics::Collision* GamePhysics::CircleColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    //Get the direction from this collider to the AABB
    GameMath::Vector2 direction = getOwner()->getTransform()->getGlobalPosition() - other->getOwner()->getTransform()->getGlobalPosition();

    //Clamp the direction vector to be within the bounds of the AABB
    if (direction.x < -other->getOwner()->getWidth() / 2)
        direction.x = -other->getWidth() / 2;
    else if (direction.x > other->getWidth() / 2)
        direction.x = other->getWidth() / 2;

    if (direction.y < -other->getHeight() / 2)
        direction.y = -other->getHeight() / 2;
    else if (direction.y > other->getHeight() / 2)
        direction.y = other->getHeight() / 2;

    //Add the direction vector to the AABB center to get the closest point to the circle
    GameMath::Vector2 closestPoint = other->getOwner()->getTransform()->getGlobalPosition() + direction;

    //Get the distance between the circle and the closest point found
    float distanceFromClosestPoint = (getOwner()->getTransform()->getGlobalPosition() - closestPoint).getMagnitude();

    setCollisionNormal((other->getOwner()->getTransform()->getGlobalPosition() - closestPoint).getNormalized());
}

void GamePhysics::CircleColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    
    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius(), GetColor(getColor()));

}
