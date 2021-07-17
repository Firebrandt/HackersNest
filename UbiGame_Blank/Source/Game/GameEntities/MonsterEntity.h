#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/MonsterMovementComponent.h"

namespace Game
{

	class MonsterEntity : public GameEngine::Entity
	{
	public:
		MonsterEntity();
		~MonsterEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		MonsterMovementComponent* m_monsterMovementComponent;
	};
}

