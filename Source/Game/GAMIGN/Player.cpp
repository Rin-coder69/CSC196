#include "Player.h"
#include "Rocket.h"
#include "../engine/Engine.h"
#include "Input/InputSystem.h"
#include "Framework/Scene.h"
#include "Math/math.h"
#include "Math/vector3.h"
#include "Render/Model.h"
#include "Render/Renderer.h"
#include "../gamedata.h"


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


    transform.position.x = gaia::math::wrap(transform.position.x, 0.0f, (float)gaia::GetEngine().GetRenderer().GetWidth());
    transform.position.y = gaia::math::wrap(transform.position.y, 0.0f, (float)gaia::GetEngine().GetRenderer().GetHeight());

    fireTimer -= deltaTime;
    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE) && fireTime <= 0 ) {
		fireTimer = fireTime;

        std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model>(GameData::shipPoints, gaia::vec3{ 1.0f,1.4f,1.0f });
        gaia::Transform transform{ this->transform.position, this->transform.rotation, 2 };
        auto rocket = std::make_unique<Rocket>(transform, model);
        rocket->speed = 1500.0f;
		rocket->lifespan = 1.5f;
        rocket->damping = 1.5f;
        rocket->name = "player";
        rocket->tag = "player";
        scene->AddActor(std::move(rocket));
    }

    fireTimer -= deltaTime;
    if (gaia::GetEngine().GetInput().GetKeyDown(SDL_SCANCODE_SPACE)) {
        std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model>(GameData::shipPoints, gaia::vec3{ 1.0f,1.4f,1.0f });
    }

    Actor::Update(deltaTime);
}

void Player::OnCollision(Actor* other)
{   
    if (other->tag != tag) {
                destroyed = true;
				//scene->GetGame()->AddPoints(100);
    }
	std::cout << other->tag << std::endl;
}
  

