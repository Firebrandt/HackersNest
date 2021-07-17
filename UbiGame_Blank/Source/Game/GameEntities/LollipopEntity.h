#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"

namespace Game
{

	class LollipopEntity : public GameEngine::Entity
	{
	public:
		LollipopEntity();
		~LollipopEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		bool alive = true;
		unsigned int itemsGathered = 0;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}

