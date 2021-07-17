#include "GameBoard.h"


#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/LollipopEntity.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace Game;
std::vector<LollipopEntity*> m_lollipops(8);

GameBoard::GameBoard()
	: m_player(nullptr)
	, m_backGround(nullptr)
	, m_isGameOver(false)
{
	m_player = new PlayerEntity();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
	m_player->SetPos(sf::Vector2f(50.f, 50.f));
	m_player->SetSize(sf::Vector2f(40.f, 40.f));

	for (int i = 0; i < Game::PlayerEntity::lollipopsToCollect; i++) {
		m_lollipops[i] = new LollipopEntity();
		int lollipopSize = 20;
		//render randomly - small placement restriction to make sure image isn't too cut off
		int randX = rand() % ((int)GameEngine::GameEngineMain::getWindowWidth()- lollipopSize);
		int randY = rand() % ((int)GameEngine::GameEngineMain::getWindowHeight()- lollipopSize);
		m_lollipops[i]->SetPos(sf::Vector2f(randX, randY));
		m_lollipops[i]->SetSize(sf::Vector2f(lollipopSize, lollipopSize));
		GameEngine::GameEngineMain::GetInstance()->AddEntity(m_lollipops[i]);
		std::cout << i+1 << "\n";
	}

	CreateBackGround();
}

void remove_Lollipop() { //constantly kill off collected lollipops
	for(int i = 0; i < Game::PlayerEntity::lollipopsToCollect; i++){
		if (m_lollipops[i]->lollipop_alive == false) {
			GameEngine::GameEngineMain::GetInstance()->RemoveEntity(m_lollipops[i]);
		}
	}
}

GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!m_isGameOver)
	{
		remove_Lollipop();
		if (m_player->collectedLollipops == m_player->lollipopsToCollect) {
			std::cout << "You win!" << "\n";
			m_isGameOver = true;
		}
	}
}





void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(500.f, 500.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	m_backGround = bgEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!m_backGround || !m_player)
		return;

	m_backGround->SetPos(m_player->GetPos());
}