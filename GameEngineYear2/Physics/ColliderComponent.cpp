#include "ColliderComponent.h"
#include "Engine/Engine.h"
#include "Engine/Scene.h"

void GamePhysics::ColliderComponent::start()
{
	GameEngine::Engine::getCurrentScene()->addActiveCollider(this);
	
}

GamePhysics::Collision* GamePhysics::ColliderComponent::checkCollision(ColliderComponent* other)
{
	switch (other->getColliderType())
	{
	case CIRCLE:
		return checkCollisionCircle((CircleColliderComponent*)other);
	case AABB:
		return checkCollisionAABB((AABBColliderComponent*)other);
	}

	return nullptr;
}

void GamePhysics::ColliderComponent::onCollisionEnter(GamePhysics::Collision* other)
{
	if (getColliderType() == AABB)
	{
		m_color = 0x00000000;
	}
	else
	{
		m_color = 0xFF0000FF;
	}
}

void GamePhysics::ColliderComponent::update(double deltaTime)
{
	m_color = 0x00FF00FF;
}
