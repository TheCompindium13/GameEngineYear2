#include "Component.h"
#include "Entity.h"
void GameEngine::Component::setEnabled(bool enabled)
{
	if (!m_enabled && enabled)
		onEnable();
	else if (m_enabled && !enabled)
		onDisable();
	m_enabled = enabled;
}

GameEngine::Entity* GameEngine::Component::getOwner()
{
	return nullptr;
}

void GameEngine::Component::setOwner(Entity* entity)
{
	m_owner = entity;
}
