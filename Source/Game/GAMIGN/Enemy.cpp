#include "Enemy.h"
#include "Engine.h"
#include "Render/Renderer.h"
#include "Framework/Scene.h"
#include "../gamedata.h"
#include "Player.h"
void Enemy::Update(float deltaTime)
{

	Player* player = scene->GetActorByName<Player>("player");
	if (player) {
		gaia::vec2 direction{ 0,0 };
		direction = player->transform.position - transform.position;
		direction = direction.Normalized();
		transform.rotation = gaia::math::radToDeg(direction.Angle());
	}
	gaia::vec2 force = gaia::vec2{ 1,0 }.Rotate(gaia::math::degToRad(transform.rotation));
	velocity += force * deltaTime;

	transform.position.x = gaia::math::wrap(transform.position.x, 0.0f, (float));

	Actor::Update(deltaTime);
}

void Enemy::OnCollision(Actor* other)
{
	if (other->tag != tag) {
		destroyed = true;
		scene->GetGame()->AddPoints(100);
	}

