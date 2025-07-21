#include "Player.h"
#include "../engine/Engine.h"
#include "Input/InputSystem.h"

void Player::Update(float deltaTime) {

    float playerSpeed = 100.0f;

    gaia::vec2 direction{ 0,0 };
    if (InputSystem->GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;//100 * time.GetDeltaTime();
    if (inputSystem->GetKeyDown(SDL_SCANCODE_A)) direction.y = 1; //100 * time.GetDeltaTime();
    if (inputSystem->GetKeyDown(SDL_SCANCODE_S)) direction.x = -1;//100 * time.GetDeltaTime();
    if (inputSystem->GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; //100 * time.GetDeltaTime();

    if (direction.lengthSqr() > 0) {
        direction = direction.Normalized(); // Normalize the direction vector to ensure consistent speed
        transform.position += (direction * playerSpeed) * time.GetDeltaTime();
    }

}