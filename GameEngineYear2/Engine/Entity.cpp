#include "Entity.h"
#include "TransformComponent.h"
GameEngine::Entity::Entity()
{
	TransformComponent* transform = new TransformComponent();
	addComponent(transform);
	m_transform = transform;
}

void GameEngine::Entity::start()
{
	m_started = true;

	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->start();
	}
	onStart();
}

void GameEngine::Entity::update(double deltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->update(deltaTime);
	}
	onUpdate(deltaTime);
}

void GameEngine::Entity::fixedUpdate(float fixedDeltaTime)
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->fixedUpdate(fixedDeltaTime);
	}
	onFixedUpdate(fixedDeltaTime);
}

void GameEngine::Entity::draw()
{
	for (Component* component : m_components)
	{
		if (component->getEnabled())
			component->draw();
	}
	
}

void GameEngine::Entity::end()
{
	for (Component* component : m_components)
	{
		component->end();
	}
	m_started = false;
	onEnd();
}

void GameEngine::Entity::addComponent(Component* component)
{
	component->setOwner(this);
	m_components.pushFront(component);

}


bool GameEngine::Entity::getEnabled()
{
	return m_enabled;
}

void GameEngine::Entity::setEnabled(bool Enabled)
{
	if (!m_enabled && Enabled)
	{
		onEnable();
	}
	else if (m_enabled && !Enabled)
	{
		onDisable();
	}
	m_enabled = Enabled;
}
