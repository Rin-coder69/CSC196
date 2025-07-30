#include "SpaceGame.h"
#include "Framework/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Render/Model.h"
#include "Render/Renderer.h"
#include "Input/InputSystem.h"
#include "Engine.h"
#include "Player.h"
#include "Enemy.h"
#include "../gamedata.h"

#include <vector>

bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<gaia::Scene>();

    return true;
}

void SpaceGame::Update(float dt)
{
    switch (m_gameState)
    {
    case SpaceGame::GameState::Initialize:
        m_gameState = GameState::Title;
        break;

    case SpaceGame::GameState::Title:
        if (gaia::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_SPACE)) {
            m_gameState = GameState::StartGame;
        }
        break;

    case SpaceGame::GameState::StartGame:
    {
        std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model>(GameData::shipPoints, gaia::vec3{ 0.0f, 0.4f, 1.0f });
        gaia::Transform transform{ gaia::vec2{ gaia::GetEngine().GetRenderer().GetWidth() * 0.5f, gaia::GetEngine().GetRenderer().GetHeight() * 0.5f }, 0, 5 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        player->speed = 1500.0f;
        player->rotationspeed = 180.0f;
        player->damping = 1.5f;
        player->name = "player";
        player->tag = "player";

        m_scene->AddActor(std::move(player));
    }
        m_score = 0;
        m_lives = 3;
        m_gameState = GameState::StartRound;
        break;

    case SpaceGame::GameState::StartRound:
    {
        // create player
        
        m_gameState = GameState::Game;
    }
    break;
    case SpaceGame::GameState::Game:
        m_enemySpawnTimer -= dt;
        if (m_enemySpawnTimer <= 0) {
            m_enemySpawnTimer = 4;

            // create enemies
            std::shared_ptr<gaia::Model> enemyModel = std::make_shared<gaia::Model>(GameData::enemyPoints, gaia::vec3{ 0.0f, 0.4f, 1.0f });
            gaia::Transform transform{ gaia::vec2{ gaia::Random::getReal() * gaia::GetEngine().GetRenderer().GetWidth() * 0.5f, gaia::Random::getReal() * gaia::GetEngine().GetRenderer().GetHeight() }, 0, 10 };
            std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
            enemy->damping = 0.2f;
            enemy->speed = (gaia::Random::getReal() * 800) + 500;
            enemy->tag = "enemy";
            m_scene->AddActor(std::move(enemy));
        }

        break;
    case SpaceGame::GameState::PlayerDead:
        m_lives--;
        if (m_lives == 0) m_gameState = GameState::GameOver;
        else {
            m_gameState = GameState::StartRound;
        }
        break;
    case SpaceGame::GameState::GameOver:
        break;
    default:
        break;
    }

    m_scene->Update(gaia::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw()
{
    m_scene->Draw(gaia::GetEngine().GetRenderer());
}

void SpaceGame::ShutDown()
{
    //
}

