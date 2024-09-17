#include "CircleColliderComponent.h"
#include "AABBColliderComponent.h"
#include "Engine/TransformComponent.h"
#include "Math/Vector2.h"
#include "Engine/Entity.h"
#include <raylib.h>

GamePhysics::CircleColliderComponent::CircleColliderComponent(float radius) : ColliderComponent()
{
    setColliderType(CIRCLE);
    m_radius = radius;
}

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
    if (other->getOwner() == getOwner())
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();

    // Get the positions
    GameMath::Vector2 circlePos = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 aabbPos = other->getOwner()->getTransform()->getGlobalPosition();

    // Get the direction from the circle to the AABB
    GameMath::Vector2 direction = circlePos - aabbPos;

    // Clamp the direction vector to be within the bounds of the AABB
    float halfWidth = other->getWidth() / 2;
    float halfHeight = other->getHeight() / 2;

    if (direction.x < -halfWidth)
        direction.x = -halfWidth;
    else if (direction.x > halfWidth)
        direction.x = halfWidth;

    if (direction.y < -halfHeight)
        direction.y = -halfHeight;
    else if (direction.y > halfHeight)
        direction.y = halfHeight;

    // Calculate the closest point on the AABB
    GameMath::Vector2 closestPoint = aabbPos + direction;

    // Get the distance between the circle and the closest point found
    float distanceFromClosestPoint = (circlePos - closestPoint).getMagnitude();

    // Check for collision
    float circleRadius = getRadius();
    if (distanceFromClosestPoint <= circleRadius)
    {
        // Set collision data
        
        collisionData->normal = (closestPoint - circlePos).normalize();  // Normal pointing from circle to AABB
        collisionData->penetrationDistance = circleRadius - distanceFromClosestPoint;  // Depth of penetration
        collisionData->collider = other;
        // You might also want to set additional data such as the collision point
        collisionData->contactPoint = closestPoint;
    }
    else
    {
        // No collision
        delete collisionData;  // Clean up unused collision data
        return nullptr;
    }

    return collisionData;
}

void GamePhysics::CircleColliderComponent::draw()
{
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();
    
    RAYLIB_H::DrawCircleLines(position.x, position.y, getRadius(), GetColor(getColor()));

    
}
