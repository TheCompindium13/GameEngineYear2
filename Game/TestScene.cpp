#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"
#include "Physics/RigidBodyComponent.h"
#include "chrono"
#include "iostream"

void TestScene::onStart()
{
	// Set up floor
	m_floor = new GameEngine::Entity();
	m_floor->getTransform()->setLocalScale({ 1000,100 });
	m_floor->getTransform()->setLocalPosition({ 400,750 });
	m_floor->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_floor->addComponent(new GamePhysics::AABBColliderComponent(1000, 125))->setRigidBody(new GamePhysics::RigidBodyComponent);
	// Set up roof
	m_roof = new GameEngine::Entity();
	m_roof->getTransform()->setLocalScale({ 1000,100 });
	m_roof->getTransform()->setLocalPosition({ 400,0 });
	m_roof->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_roof->addComponent(new GamePhysics::AABBColliderComponent(1000, 125))->setRigidBody(new GamePhysics::RigidBodyComponent);
	// Set up left wall
	m_leftWall = new GameEngine::Entity();
	m_leftWall->getTransform()->setLocalScale({ 100,1000 });
	m_leftWall->getTransform()->setLocalPosition({ 0,375 });
	m_leftWall->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_leftWall->addComponent(new GamePhysics::AABBColliderComponent(125, 625))->setRigidBody(new GamePhysics::RigidBodyComponent);
	// Set up right wall
	m_rightWall = new GameEngine::Entity();
	m_rightWall->getTransform()->setLocalScale({ 100,1000 });
	m_rightWall->getTransform()->setLocalPosition({ 800,375 });
	m_rightWall->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	m_rightWall->addComponent(new GamePhysics::AABBColliderComponent(125, 625))->setRigidBody(new GamePhysics::RigidBodyComponent);
	// Set up circle 1
	m_circle1 = new GameEngine::Entity();
	m_circle1->getTransform()->setLocalScale({ 40,40 });
	m_circle1->getTransform()->setLocalPosition({ 100,160 });
	m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::BOX);
	GamePhysics::RigidBodyComponent* circle1RigidBody = new GamePhysics::RigidBodyComponent();
	m_circle1->addComponent(circle1RigidBody);
	m_circle1->addComponent(new GamePhysics::AABBColliderComponent(50,50))->setRigidBody(circle1RigidBody);
	//m_circle1->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	//m_circle1->addComponent(new GamePhysics::CircleColliderComponent(50));
	circle1RigidBody->setEnabled(true);
	circle1RigidBody->setMass(1);
	circle1RigidBody->setGravity(9.81f);

	// Set up circle 2
	m_circle2 = new GameEngine::Entity();
	m_circle2->getTransform()->setLocalScale({ 40,40 });
	m_circle2->getTransform()->setLocalPosition({ 600,160 });
	m_circle2->addComponent<Graphics::ShapeComponent>()->setShapeType(Graphics::CIRCLE);
	GamePhysics::RigidBodyComponent* circle2RigidBody = new GamePhysics::RigidBodyComponent();
	m_circle2->addComponent(circle2RigidBody);
	m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50))->setRigidBody(circle2RigidBody);
	circle2RigidBody->setEnabled(true);
	circle2RigidBody->setMass(1);
	circle2RigidBody->setGravity(9.81f);

	
	
	addEntity(m_circle2);

	addEntity(m_circle1);
	addEntity(m_floor);
	addEntity(m_roof);
	addEntity(m_leftWall);
	addEntity(m_rightWall);

}

void TestScene::onUpdate(double deltaTime)
{
	GameMath::Vector2 Colliding = m_circle1->getTransform()->getLocalPosition();
	std::cout << "x:" << Colliding.x << std::endl;
	std::cout << "y:" << Colliding.y << std::endl;
}
