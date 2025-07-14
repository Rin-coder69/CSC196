#include "Math/Math.h"
#include "Math/Vector2.h"
#include "Renderer/rendeder.h"
#include "core/random.h"
#include "core/Time.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

#include <SDL3/SDL.h>
#include <vector>
#include <iostream>
#include <fmod.hpp>

std::vector<gaia::vec2> points;
int main(int argc, char* argv[]) {

    //itialize engine systems
    // create audio system

    gaia::Renderer renderer;
	gaia::Time time;

    renderer.Initialize();
    renderer.CreateWindow("gaia Engine", 1280, 1024);

	gaia::InputSystem inputSystem;
	inputSystem.Initialize();

    gaia::AudioSystem audio;
	audio.Initialize();

	audio.AddSound("bass.wav", "bass");

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

            //update engine systems
            audio.Update();
			inputSystem.Update();
            
            //get input
            if(inputSystem.GetKeyDown(SDL_SCANCODE_A)) {
				audio.PlaySound("bass");
			}

            //if (inputSystem.getMouseButtonDown(gaia::InputSystem::MouseButton::LEFT)) {
            //    gaia::vec2 position = inputSystem.GetMousePosition();
            //    if (points.empty()) points.push_back(position);
            //    else if ((position - points.back()).length() > 10) points.push_back(position);
            //}
            //if (inputSystem.getMouseButtonPressed(gaia::InputSystem::MouseButton::LEFT)) {
            //    std::cout << "Left mouse button pressed" << std::endl;
            //}


    
			gaia::vec2 mouse =inputSystem.GetMousePosition();
			//std::cout << mouse.x << " " << mouse.y << std::endl;
            //draw 
            renderer.SetColor(0, 0, 0);
            renderer.Clear();

         
            for (int i = 0; i < (int)points.size() - 1; i++) {
                // set color or random color
                renderer.SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));
                renderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
            }

           
            gaia::vec2 speed{-40.0f,0};
            float length = speed.length();
             for (auto& star : stars) {
				 star += speed * time.GetDeltaTime();
               
				 if (star[0] > 1280) star[0] = 0;
				 if (star[0] < 0) star[0] = 1280;
                renderer.SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));
				renderer.DrawPoint(star.x, star.y);
            }

            renderer.SetColor(gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256), gaia::Random::getRandomInt(256));
            //renderer.DrawLine(gaia::Random::getRandomFloat() * 1200, gaia::Random::getRandomFloat() * 1024, 1300, 1240);
            renderer.Present();
        }


        renderer.ShutDown();

        audio.ShutDown();

        return 0;
    }
