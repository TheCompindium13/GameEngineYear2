#include "TestScene.h"
#include "Engine/Entity.h"
#include "Graphics/ShapeComponent.h"
#include "Engine/TransformComponent.h"
#include "chrono"
void TestScene::onStart()
{


	m_entity = new GameEngine::Entity();
	m_entity->getTransform()->setLocalScale({ 100,100 });
	m_entity->getTransform()->setLocalPosition({ 400,400 });
	Graphics::ShapeComponent* shapeComponent = new Graphics::ShapeComponent();
	shapeComponent->setShapeType(Graphics::ShapeType::CIRCLE);
	
	m_entity->addComponent(shapeComponent);

	addEntity(m_entity);
}

void TestScene::onUpdate(double deltaTime)
{
	float currentTime = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
	float circleRadius = 100;
	GameMath::Vector2 newPosition = { (float)sin(currentTime) *  circleRadius + 400, (float)cos(currentTime) * circleRadius + 400 };
	m_entity->getTransform()->setLocalPosition(newPosition);
}
