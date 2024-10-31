
#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/Shape.h"
#include "Engine/TransformComponent.h"
#include "Physics/CircleColliderComponent.h"
#include "Physics/AABBColliderComponent.h"
#include "Physics/RigidBodyComponent.h"
#include <chrono>
#include <iostream>

void TestScene::onStart()
{
    float positions[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    // Set up floor
    m_floor = new GameEngine::Entity();
    m_floor->getTransform()->setLocalScale({ 1000,100 });
    m_floor->getTransform()->setLocalPosition({ 400,750 });

    // Create and initialize the shape directly
    Graphics::Shape* floorShape = new Graphics::Shape("floor", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_floor->addComponent(floorShape);
    m_floor->addComponent(new GamePhysics::AABBColliderComponent(1000, 125))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Set up roof
    //m_roof = new GameEngine::Entity();
    //m_roof->getTransform()->setLocalScale({ 1000,100 });
    //m_roof->getTransform()->setLocalPosition({ 400,0 });

    //Graphics::Shape* roofShape = new Graphics::Shape("roof", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_roof->addComponent(roofShape);
    //m_roof->addComponent(new GamePhysics::AABBColliderComponent(1000, 125))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Set up left wall
    //m_leftWall = new GameEngine::Entity();
    //m_leftWall->getTransform()->setLocalScale({ 100,1000 });
    //m_leftWall->getTransform()->setLocalPosition({ 0,375 });

    //Graphics::Shape* leftWallShape = new Graphics::Shape("leftWall", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_leftWall->addComponent(leftWallShape);
    //m_leftWall->addComponent(new GamePhysics::AABBColliderComponent(125, 625))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Set up right wall
    //m_rightWall = new GameEngine::Entity();
    //m_rightWall->getTransform()->setLocalScale({ 100,1000 });
    //m_rightWall->getTransform()->setLocalPosition({ 800,375 });

    //Graphics::Shape* rightWallShape = new Graphics::Shape("rightWall", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_rightWall->addComponent(rightWallShape);
    //m_rightWall->addComponent(new GamePhysics::AABBColliderComponent(125, 625))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Set up circle 1
    //m_circle1 = new GameEngine::Entity();
    //m_circle1->getTransform()->setLocalScale({ 40,40 });
    //m_circle1->getTransform()->setLocalPosition({ 245,160 });

    //Graphics::Shape* circle1Shape = new Graphics::Shape("circle1", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_circle1->addComponent(circle1Shape);
    //GamePhysics::RigidBodyComponent* circle1RigidBody = new GamePhysics::RigidBodyComponent();
    //m_circle1->addComponent(circle1RigidBody);
    //m_circle1->addComponent(new GamePhysics::AABBColliderComponent(70, 50))->setRigidBody(circle1RigidBody);
    //circle1RigidBody->setEnabled(true);
    //circle1RigidBody->setMass(1);
    //circle1RigidBody->setGravity(9.81);

    //// Set up circle 2
    //m_circle2 = new GameEngine::Entity();
    //m_circle2->getTransform()->setLocalScale({ 40,40 });
    //m_circle2->getTransform()->setLocalPosition({ 535,160 });

    //Graphics::Shape* circle2Shape = new Graphics::Shape("circle2", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_circle2->addComponent(circle2Shape);
    //GamePhysics::RigidBodyComponent* circle2RigidBody = new GamePhysics::RigidBodyComponent();
    //m_circle2->addComponent(circle2RigidBody);
    //m_circle2->addComponent(new GamePhysics::CircleColliderComponent(50))->setRigidBody(circle2RigidBody);
    //circle2RigidBody->setEnabled(true);
    //circle2RigidBody->setMass(1);
    //circle2RigidBody->setGravity(9.81f);

    //// Set up center
    //m_Center = new GameEngine::Entity();
    //m_Center->getTransform()->setLocalScale({ 40,40 });
    //m_Center->getTransform()->setLocalPosition({ 400,400 });
    //m_Center->addComponent(new GamePhysics::CircleColliderComponent(125))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Set up corner 1
    //m_Corner1 = new GameEngine::Entity();
    //m_Corner1->getTransform()->setLocalScale({ 20,20 });
    //m_Corner1->getTransform()->setLocalPosition({ 300,200 });

    //Graphics::Shape* corner1Shape = new Graphics::Shape("corner1", positions, indices, 4, 6, "res/textures/Nic.png", "res/shaders/Basic.shader");
    //m_Corner1->addComponent(corner1Shape);
    //m_Corner1->addComponent(new GamePhysics::CircleColliderComponent(25))->setRigidBody(new GamePhysics::RigidBodyComponent);

    //// Add entities to the scene
    //addEntity(m_circle2);
    //addEntity(m_Center);
    //addEntity(m_circle1);
    //addEntity(m_floor);
    //addEntity(m_roof);
    //addEntity(m_leftWall);
    //addEntity(m_rightWall);
}

void TestScene::onUpdate(double deltaTime)
{
    GameMath::Vector2 Colliding = m_circle2->getTransform()->getLocalPosition();
    std::cout << "x:" << Colliding.x << std::endl;
    std::cout << "y:" << Colliding.y << std::endl;
}
