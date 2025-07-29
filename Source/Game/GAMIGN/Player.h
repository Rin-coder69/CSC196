#pragma once
#include "Framework/Actor.h"

class Player : public gaia::Actor {

public:
	float speed = 200;
	float rotationspeed = 100.0f;
	float fireTime = 0.2f;
	float fireTimer = 0.0f;
public:
	Player() = default;
	Player(const gaia::Transform& transform, std::shared_ptr<class gaia::Model> model) :
		gaia::Actor{ transform, model }
	{}

	void Update(float deltaTime) override;


private:


	// Inherited via Actor
	void OnCollision(Actor* other) override;

};