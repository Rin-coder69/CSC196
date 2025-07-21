#pragma once
#include "../Engine/Actor/Actor.h"

class Player : public gaia::Actor {
public:
	Player() = default;
	Player(const gaia::Transform& transform, std::shared_ptr<class gaia::Model> model) :
		gaia::Actor{ transform, model }
	{}

	void Update(float deltaTime) override;


private:

};