#include "MonsterMovementComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/TextureManager.h"
#include "Game/GameEntities/PlayerEntity.h"
#include <iostream>
#include <SFML/Window/Keyboard.hpp>

using namespace Game;

float monsterVelocity = 100;


MonsterMovementComponent::MonsterMovementComponent()
{

}

MonsterMovementComponent::~MonsterMovementComponent()
{

}

void MonsterMovementComponent::OnAddToWorld()
{

}


void MonsterMovementComponent::Update()
{
	Component::Update();

	if (GameEngine::GameEngineMain::GetInstance()->IsGameOver())
	{
		return;
	}
	sf::Vector2f playerPos = m_player->GetPos();
	sf::Vector2f monsterPos = GetEntity()->GetPos();
	
	if (abs(playerPos.x - monsterPos.x) >= abs(playerPos.y - monsterPos.y)) {
		if (playerPos.x > monsterPos.x) {
			GetEntity()->SetPos(monsterPos + sf::Vector2f(0.04, 0));
		}
		else if (playerPos.x < monsterPos.x) {
			GetEntity()->SetPos(monsterPos - sf::Vector2f(0.04, 0));
		}
	}
	else {
		if (playerPos.y > monsterPos.y) {
			GetEntity()->SetPos(monsterPos + sf::Vector2f(0, 0.04));
		}
		else if (playerPos.y < monsterPos.y) {
			GetEntity()->SetPos(monsterPos - sf::Vector2f(0, 0.04));
		}
	}



}