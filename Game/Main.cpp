#include "Math/Math.h"
#include "Math/Vector3.h"
#include "Renderer/rendeder.h"
#include "core/random.h"
#include "core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Math/Vector2.h"
#include <SDL3/SDL.h>
#include "Actor/Actor.h"
#include "Math/Transform.h"
#include "Renderer/Model.h"
#include <vector>
#include <iostream>
#include <fmod.hpp>
#include <memory>
#include "../engine/Actor/Scene.h"
#include "GAMIGN/Player.h"
#include "Engine/Engine.h"
#include "GAMIGN/SpaceGame.h"

void func() {
	static int i = 5;
    i++;
	std::cout << i << std::endl;
}


std::vector<gaia::vec2> points;
int main(int argc, char* argv[]) {


	std::unique_ptr<SpaceGame> Game = std::make_unique<SpaceGame>();

   

    

    std::vector<gaia::vec2> points{
        {-5,-5},
        {5, -5},
        {5, 5},
        {-5, 5},
        {-5, -5}

    };


	gaia::Scene scene;
    std::shared_ptr<gaia::Model> model = std::make_shared<gaia::Model>(points, gaia::vec3{0, 0, 1});
    //gaia::Model* model = new gaia::Model{ points, gaia::vec3{1.0f, 0.0f, 0.0f} };
    std::vector<gaia::Actor> actors;


	gaia::Transform transform{ gaia::vec2{ 100, 100 }, 0, 1.0f };

  

    for(int i = 0; i < 10; i++) {
		gaia::Transform transform{ gaia::vec2{gaia::Random::getRandomFloat() * 1200, gaia::Random::getRandomFloat() * 1024 }, 0, 10 };
        std::unique_ptr<Player> player = std::make_unique<Player>(transform, model);
        scene.AddActor(std::move(player));
	}
	//gaia::Actor actor{ transform, model };

	//create transform
    //add sound
	audio->AddSound("bass.wav", "bass");
	audio->AddSound("snare.wav", "snare");
	audio->AddSound("open-hat.wav", "hihat");

    SDL_Event e;
    bool quit = false;


    //create stars
    std::vector<gaia::vec2> stars;
    for (int i = 0; i < 100; i++) {
        stars.push_back(gaia::vec2{ gaia::Random::getRandomFloat() * 1200, gaia::Random::getRandomFloat() * 1024});
    };

        gaia::vec2 v(38, 40);
        // Define a rectangle
        SDL_FRect greenSquare{ 270, 190, 200, 200 };
        //Main loop every frame


        

        while (!quit) {
			time.Tick();
            while (SDL_PollEvent(&e)) {
                if (e.type == SDL_EVENT_QUIT) {
                    quit = true;
                }
                
            }

            gaia::GetEngine().Update();
			scene.update(gaia::GetEngine().GetTime().GetDeltaTime());

			gaia::GetEngine().Update();

            if (gaia::GetEngine.GetinputSystem().GetKeyPressed(SDL_SCANCODE_ESCAPE)) quit = true;

            //update engine systems
            audio->Update();
			inputSystem->Update();

			

            //draw
            float f = 5;
            gaia::vec3 color{ 1,0,0 };

			renderer->SetColor(color.x, color.y, color.z);
			renderer->Clear();
            
            //get input
            /* if (inputSystem.GetKeyPressed(SDL_SCANCODE_Q)) {
                audio.PlaySound("bass");
            };

            if (inputSystem.GetKeyPressed(SDL_SCANCODE_W)) {
                audio.PlaySound("snare");
            }

            if (inputSystem.GetKeyPressed(SDL_SCANCODE_E)) {
                audio.PlaySound("hihat");
            }*/

			if (inputSystem->GetKeyDown(SDL_SCANCODE_A)) transform.rotation += gaia::math::degToRad(90 * time.GetDeltaTime());
			if (inputSystem->GetKeyDown(SDL_SCANCODE_D)) transform.rotation -= gaia::math::degToRad(90 * time.GetDeltaTime());

            

			float playerSpeed = 100.0f;

            gaia::vec2 direction{ 0,0 };
            if (inputSystem->GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;//100 * time.GetDeltaTime();
            if (inputSystem->GetKeyDown(SDL_SCANCODE_A)) direction.y = 1; //100 * time.GetDeltaTime();
            if (inputSystem->GetKeyDown(SDL_SCANCODE_S)) direction.x = -1;//100 * time.GetDeltaTime();
            if (inputSystem->GetKeyDown(SDL_SCANCODE_D)) direction.x = 1; //100 * time.GetDeltaTime();

            if (direction.lengthSqr() > 0) {
                direction = direction.Normalized(); // Normalize the direction vector to ensure consistent speed
                transform.position += direction * playerSpeed * time.GetDeltaTime();
            }

	

            if (inputSystem->GetMouseButtonDown(gaia::InputSystem::MouseButton::LEFT)) {
                gaia::vec2 position = inputSystem->GetMousePosition();
                if (points.empty()) points.push_back(position);
                else if ((position - points.back()).length() > 10) points.push_back(position);
            }
            if (inputSystem->GetMouseButtonPressed(gaia::InputSystem::MouseButton::LEFT)) {
                std::cout << "Left mouse button pressed" << std::endl;
            }


    
			gaia::vec2 mouse =inputSystem->GetMousePosition();
			//std::cout << mouse.x << " " << mouse.y << std::endl;
            //draw 
            gaia::vec3 Color{ 0, 0 ,0 };

			gaia::getEngine().GetRenderer().SetColor(Color.x, Color.y, Color.z);
			gaia::getEngine().GetRenderer().Clear();

			scene.draw(gaia::GetEngine().GetRenderer());
            

            renderer->SetColor(0, 0, 0);
            renderer->Clear();


            for (auto actor : actors) {
                actor.Draw(*renderer);
            }

         
            for (int i = 0; i < (int)points.size() - 1; i++) {
                // set color or random color
                renderer->SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));
                renderer->DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
            }

           
            gaia::vec2 speed{-40.0f,0};
            float length = speed.length();


             for (auto& star : stars) {
				 star += speed * time.GetDeltaTime();
               
				 if (star[0] > 1280) star[0] = 0;
				 if (star[0] < 0) star[0] = 1280;
                renderer->SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));
				renderer->DrawPoint(star.x, star.y);
            }

            renderer->SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));

			scene.draw(*renderer);
            //renderer.DrawLine(gaia::Random::getRandomFloat() * 1200, gaia::Random::getRandomFloat() * 1024, 1300, 1240);
            renderer->Present();
        }

		   

		gaia::getEngine().ShutDown();

        return 0;
    }
    
