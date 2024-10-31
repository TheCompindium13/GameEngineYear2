#include "AABBColliderComponent.h"
#include "Engine/Entity.h"
#include "CircleColliderComponent.h"
#include <algorithm>

#include <cassert>
#include <iostream>

GamePhysics::AABBColliderComponent::AABBColliderComponent(float width, float height) : ColliderComponent()
{
    setColliderType(AABB);
    assert(width > 0 && height > 0);  // Ensure dimensions are positive
    m_width = width;
    m_height = height;
}

float GamePhysics::AABBColliderComponent::getLeft()
{
    return getOwner()->getTransform()->getGlobalPosition().x - getWidth() / 2;
}

float GamePhysics::AABBColliderComponent::getRight()
{
    return getOwner()->getTransform()->getGlobalPosition().x + getWidth() / 2;
}

float GamePhysics::AABBColliderComponent::getTop()
{
    return getOwner()->getTransform()->getGlobalPosition().y - getHeight() / 2;
}

float GamePhysics::AABBColliderComponent::getBottom()
{
    return getOwner()->getTransform()->getGlobalPosition().y + getHeight() / 2;
}

void GamePhysics::AABBColliderComponent::draw()
{
    // Get the global position of the AABB center
    GameMath::Vector2 position = getOwner()->getTransform()->getGlobalPosition();

    // Calculate the top-left corner of the AABB
    float halfWidth = getWidth() / 2;
    float halfHeight = getHeight() / 2;

    float topLeftX = position.x - halfWidth;
    float topLeftY = position.y - halfHeight;

}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    if (other->getOwner() == getOwner())
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();

    // Get the positions and dimensions
    GameMath::Vector2 aabbPos = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 circlePos = other->getOwner()->getTransform()->getGlobalPosition();

    float aabbHalfWidth = getWidth() / 2;
    float aabbHalfHeight = getHeight() / 2;
    float circleRadius = other->getRadius();

    // Calculate the closest point on the AABB to the circle
    float closestX = std::max(aabbPos.x - aabbHalfWidth, std::min(circlePos.x, aabbPos.x + aabbHalfWidth));
    float closestY = std::max(aabbPos.y - aabbHalfHeight, std::min(circlePos.y, aabbPos.y + aabbHalfHeight));

    // Vector from circle center to closest point
    float deltaX = circlePos.x - closestX;
    float deltaY = circlePos.y - closestY;

    // Check if the circle is colliding with the AABB
    float distanceSquared = deltaX * deltaX + deltaY * deltaY;
    float distance = sqrtf(distanceSquared);

    if (distance < 1e-5f) {
        // Avoid division by zero; set a default normal direction
        collisionData->normal = GameMath::Vector2(1, 0);
    }
    else {
        collisionData->normal = GameMath::Vector2(deltaX / distance, deltaY / distance);
    }

    if (distanceSquared <= circleRadius * circleRadius)
    {
        // Collision detected
        collisionData->penetrationDistance = circleRadius - sqrtf(distanceSquared);
        collisionData->contactPoint = GameMath::Vector2(
            closestX + collisionData->normal.x * circleRadius,
            closestY + collisionData->normal.y * circleRadius
        );
        collisionData->collider = other;
    }
    else
    {
        // No collision
        delete collisionData;  // Clean up unused collision data
        return nullptr;
    }

    return collisionData;
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
    if (other->getOwner() == getOwner())
        return nullptr;

    GamePhysics::Collision* collisionData = new Collision();

    // Get the positions and dimensions of both AABBs
    GameMath::Vector2 pos1 = getOwner()->getTransform()->getGlobalPosition();
    GameMath::Vector2 pos2 = other->getOwner()->getTransform()->getGlobalPosition();

    float halfWidth1 = getWidth() / 2;
    float halfHeight1 = getHeight() / 2;
    float halfWidth2 = other->getWidth() / 2;
    float halfHeight2 = other->getHeight() / 2;

    // Calculate the min and max coordinates of both AABBs
    float left1 = pos1.x - halfWidth1;
    float right1 = pos1.x + halfWidth1;
    float top1 = pos1.y - halfHeight1;
    float bottom1 = pos1.y + halfHeight1;

    float left2 = pos2.x - halfWidth2;
    float right2 = pos2.x + halfWidth2;
    float top2 = pos2.y - halfHeight2;
    float bottom2 = pos2.y + halfHeight2;

    // Calculate the overlap in x and y directions
    float overlapX = ((right1 < right2) ? right1 : right2) - ((left1 > left2) ? left1 : left2);
    float overlapY = ((bottom1 < bottom2) ? bottom1 : bottom2) - ((top1 > top2) ? top1 : top2);

    // Check for overlap
    if (overlapX > 0 && overlapY > 0)
    {
        // Collision detected
        if (overlapX < overlapY)
        {
            if (right1 < right2)
            {
                collisionData->normal = GameMath::Vector2(1, 0);
            }
            else
            {
                collisionData->normal = GameMath::Vector2(-1, 0);
            }
            collisionData->penetrationDistance = overlapX;
        }
        else
        {
            if (bottom1 < bottom2)
            {
                collisionData->normal = GameMath::Vector2(0, 1);
            }
            else
            {
                collisionData->normal = GameMath::Vector2(0, -1);
            }
            collisionData->penetrationDistance = overlapY;
        }

        // Calculate the contact point (simple average of the two AABB positions)
        collisionData->contactPoint = GameMath::Vector2(
            left1 + (collisionData->normal.x * collisionData->penetrationDistance / 2),
            top1 + (collisionData->normal.y * collisionData->penetrationDistance / 2)
        );
        collisionData->collider = other;
    }
    else
    {
        // No collision
        delete collisionData;  // Clean up unused collision data
        return nullptr;
    }

    return collisionData;
}