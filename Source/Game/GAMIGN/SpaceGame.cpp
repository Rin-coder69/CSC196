#include "SpaceGame.h"
#include "Math/Vector2.h"
#include "Math/Transform.h"
#include "Core/Random.h"
#include "Framework/Scene.h"
#include "Engine.h"
#include "Enemy.h"
#include "Player.h"
#include <vector>
#include "Input/InputSystem.h"
#include "../gamedata.h"
bool SpaceGame::Initialize()
{
    m_scene = std::make_unique<gaia::Scene>(this);

    std::vector<gaia::vec2> points{
        {-5,-5},
        {-4, -3},
        {-2, 0},
        {-4, 3},
        {5, 0}
    };

    //std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model>(points, gaia::vec3{ 1, 0, 0 });
    ////create player
    // 
    //    


    //    m_scene->AddActor(std::move(player));
    //    //create Enemy
    //    std::shared_ptr<gaia::Model>enemyModel = std::make_shared<gaia::Model>(points, gaia::vec3{1.0f, 1.0f, 0.0f});
    //    for (int i = 0; i < 10; i++) {
    //        gaia::Transform transform{ gaia::vec2{ gaia::Random::getRandomFloat() * 1280, gaia::Random::getRandomFloat() * 1024 }, 0, 10 };
    //        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, enemyModel);
    //        enemy->damping = 1.5f;
    //        enemy->speed = (gaia::Random::getRandomFloat()* 800) + 500;
    //        m_scene->AddActor(std::move(enemy));
    //    }
    

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
        if (gaia::GetEngine().GetInput().GetKeyPressed(SDL_SCANCODE_ESCAPE)) {
            m_gameState = GameState::StarGame;
        }
        break;
    case SpaceGame::GameState::StarGame:
        m_score = 0;
        m_lives = 3;
        m_gamestate
        break;
    case SpaceGame::GameState::Game:
        break;
    case SpaceGame::GameState::PlayerDead:
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
}
