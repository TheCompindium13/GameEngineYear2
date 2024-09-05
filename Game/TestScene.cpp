#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "chrono"
void TestScene::onStart()
{
	// Set up circle 1
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 40,40 });
	m_circle1->getTransform()->setLocalPosition({ 100,100 });
	m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_circle1->addComponent(new GamePhysics::CircleColliderComponent(50));
	addEntity(m_circle1);

	// Set up circle 2
	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 40,40 });
	m_circle2->getTransform()->setLocalPosition({ 600,100 });
	m_circle2->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50));
	addEntity(m_circle2);

}

void TestScene::onUpdate(double deltaTime)
{
	GameMath::Vector2 position = m_circle1->getTransform()->getLocalPosition();
	GameMath::Vector2 deltaPosition = { 80,0 };
	m_circle1->getTransform()->setLocalPosition(position + deltaPosition * deltaTime);
}
