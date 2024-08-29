#pragma once
#include "list.h"

namespace GameEngine
{
	class Entity;

	class Scene
	{
	public:
		Scene();

		void start();
		void update(double deltaTime);
		void fixedUpdate(float fixedDeltaTime);
		void draw();
		void end();

		virtual void onStart() {}
		virtual void onUpdate(double deltaTime) {}
		virtual void onFixedUpdate(float fixedDeltaTime) {}
		virtual void onDraw() {}
		virtual void onEnd() {}

		void addEntity(Entity* entity);
		void removeEntity(Entity* entity);

	private:
		List<Entity*> m_entities;
	};
}