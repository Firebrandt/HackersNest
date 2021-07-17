#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "Game/GameEntities/PlayerEntity.h"

namespace Game
{
	class MonsterMovementComponent : public GameEngine::Component
	{
	public:
		MonsterMovementComponent();
		~MonsterMovementComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;
		void setPlayer(PlayerEntity* passedPlayer) {
			m_player = passedPlayer;
		}
	private:
		PlayerEntity* m_player; 
	};
}


