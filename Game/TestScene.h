#pragma once
#include "Engine/Scene.h"

class GameEngine::Entity;

class TestScene : public GameEngine::Scene
{
public:
	void onStart() override;
	void onUpdate(double deltaTime) override;

private:
	GameEngine::Entity* m_circle1;
	GameEngine::Entity* m_circle2;
	GameEngine::Entity* m_floor;
	GameEngine::Entity* m_roof;
	GameEngine::Entity* m_leftWall;
	GameEngine::Entity* m_rightWall;
	GameEngine::Entity* m_Center;
	GameEngine::Entity* m_Corner1;
	GameEngine::Entity* m_Corner2;
	GameEngine::Entity* m_Corner3;
	GameEngine::Entity* m_Corner4;


	float m_accumulatedTime = 0;
};