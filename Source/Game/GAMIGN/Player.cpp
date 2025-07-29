#include "Player.h"
#include "../engine/Engine.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Math/math.h"
#include "Math/vector3.h"
#include "Render/Model.h"


void Player::Update(float deltaTime) {

    //rotation
    float thrust = 0;
    float rotate = 0;

    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_D)) rotate = +1;


    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_W)) thrust = -1;
    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_S)) thrust = +1;



    transform.rotation += (rotate * rotationspeed) * deltaTime;
    gaia::vec2 direction{ 1,0 };
    gaia::vec2 force = direction.Rotate(gaia::math::degToRad(transform.rotation)) * thrust * speed;
    velocity += force * deltaTime;


    transform.position.x = gaia::math::wrap(transform.position.x, 0.0f, (float)gaia::GetEngine);
    transform.position.x = gaia::math::wrap(transform.position.x, 0.0f, (float)gaia::GetEngine);

    fireTimer -= deltaTime;
        if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {
            std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model(gamedata)
    }

    Actor::Update(deltaTime);
}

void Player::OnCollision(Actor* other)
{
    if (other->tag != tag) {
        destroyed = true;
}
  

