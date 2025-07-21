#pragma once
#include "Game/Game.h"

class SpaceGame : public gaia::Game {
public:
	SpaceGame() = default;

	bool Initialize() override;
	void Update() override;
	void ShutDown() override;

private:

};
