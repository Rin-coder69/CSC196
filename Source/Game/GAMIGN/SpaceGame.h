#pragma once
#include "Framework/Game.h"
#include "Render/Font.h"
#include "Render/Text.h"
#include <SDL3_ttf/SDL_ttf.h>
class SpaceGame : public gaia::Game {
public:
	enum class GameState {
		Initialize,
		Title,
		StarGame,
		Game,
		PlayerDead,
		GameOver,
	};
	SpaceGame() = default;

	bool Initialize() override;
	void ShutDown() override;

	void Update(float deltaTime) override;
	void Draw() override;

private:
	friend class Text;
	GameState m_gameState = GameState::Initialize;
	float m_enemySpawnTimer{ 0 };

std::unique_ptr<class gaia:Font* m_titleFont;
};
