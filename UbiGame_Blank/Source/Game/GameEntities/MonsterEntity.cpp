#include "MonsterEntity.h"


#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include "GameEngine/EntitySystem/Components/ParticleEmitterComponent.h"

using namespace Game;

MonsterEntity::MonsterEntity()
{
	//Movement
	m_monsterMovementComponent = AddComponent<MonsterMovementComponent>();

	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Monster);
	m_renderComponent->SetZLevel(2);

	//Collisions
	AddComponent<GameEngine::CollidableComponent>();

}


MonsterEntity::~MonsterEntity()
{

}


void MonsterEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();

}


void MonsterEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}
