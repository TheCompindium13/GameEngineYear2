#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"
#include "Physics/RigidBodyComponent.h"
#include "chrono"
void TestScene::onStart()
{
	// Set up circle 1
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 40,40 });
	m_circle1->getTransform()->setLocalPosition({ 100,100 });
	m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_circle1->addComponent(new GamePhysics::AABBColliderComponent(50,50));
	//m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	//m_circle1->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle1->addComponent(new GamePhysics::RigidBodyComponent());

	addEntity(m_circle1);

	// Set up circle 2
	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 40,40 });
	m_circle2->getTransform()->setLocalPosition({ 600,100 });
	m_circle2->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50));
	m_circle2->addComponent(new GamePhysics::RigidBodyComponent());
	addEntity(m_circle2);

	m_floor = new GameEngine::Entity();
	m_floor->getTransform()->setLocalScale({ 1000,100 });
	m_floor->getTransform()->setLocalPosition({ 400,750 });
	m_floor->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_floor->addComponent(new GamePhysics::AABBColliderComponent(1000, 125));

	addEntity(m_floor);

}

void TestScene::onUpdate(double deltaTime)
{
	
}
