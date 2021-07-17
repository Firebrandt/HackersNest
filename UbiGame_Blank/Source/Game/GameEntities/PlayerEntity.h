#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"

namespace Game
{

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		int collectedLollipops = 0; const int lollipopsToCollect = 8;
		bool alive = true;
		unsigned int itemsGathered = 0;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		PlayerMovementComponent* m_playerMovementComponent;
	};
}

