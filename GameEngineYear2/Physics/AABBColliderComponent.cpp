#include "AABBColliderComponent.h"
#include "Engine/Entity.h"
#include "CircleColliderComponent.h"
#include <algorithm>

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

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionCircle(CircleColliderComponent* other)
{
    
	return other->checkCollisionAABB(this);
}

GamePhysics::Collision* GamePhysics::AABBColliderComponent::checkCollisionAABB(AABBColliderComponent* other)
{
	GamePhysics::Collision* collisionData = new Collision();

	if (other->getLeft() <= getRight() &&
		other->getTop() <= getBottom() &&
		getLeft() <= other->getRight() &&
		getTop() <= other->getBottom())
	{

		//find collision normal
		int left = abs(other->getRight() - getLeft());
		int right = abs(other->getLeft() - getRight());
		int top = abs(other->getBottom() - getTop());
		int bottom = abs(getBottom() - other->getTop());
		int arr[] = { left, right, top, bottom };

		std::pair<int*, int*> minMax = std::minmax_element(std::begin(arr), std::end(arr));
		int min = *(minMax.first);
		if (min == left)
			setCollisionNormal({ -1,0 });
		else if (min == right)
			setCollisionNormal({ 1,0 });
		else if (min == top)
			setCollisionNormal({ 0,-1 });
		else if (min == bottom)
			setCollisionNormal({ 0, 1 });


	}
	return collisionData;
}
