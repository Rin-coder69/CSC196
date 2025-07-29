#pragma once
#include "Framework/Actor.h"

class Rocket : public gaia::Actor {
	// Inherited via Actor
	void OnCollision(Actor* other) override;
};