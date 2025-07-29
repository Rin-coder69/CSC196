#include "Rocket.h"	
#include "Engine.h"
#include "Framework/Scene.h"
#include "Render/Renderer.h"
#include "Player.h"


void Rocket::Update(float dt)
{
	gaia::vec2 force = gaia::vec2{ 1,0 }.Rotate(gaia::math::degToRad(transform.rotation)) * velocity += force * dt;

	transform.position.x = gaia::math::wrap(transform.position.x, 0.0f, (float)gaia::GetEngine);

		Actor::Update(dt);
}


void Rocket::OnCollision(Actor* other)
{
	if (other->tag != tag) {
		destroyed = true;

	}
}
