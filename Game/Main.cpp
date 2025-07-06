////#define NAME "Nicholas"
//#include "Math/math.h"
//#include "core/random.h"
//#pragma once
//#include <iostream>
//
//
//
//int main()
//{
//	//const float deg = gaia::radToDeg(gaia::PI);
//	gaia::math::min(5, 3);
//	gaia::math::max(5, 3);
//    gaia::math::clamp(5, 3, 10);
//
//	std::cout << NAME;
//	std::cout << "Hello, World!\n";
//	std::cout << gaia::math::PI<< std::endl;
//
//	for(int i = 0; i < 10; ++i) {
//		std::cout << gaia::Random::getRandomInt(5) << std::endl;	
//	}
////}

#include <SDL3/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;

    //Lines
    
	
   // Draw a line from (100, 100) to (200, 200)
    
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set render draw color to red

        SDL_RenderPresent(renderer); // Render the screen
	


    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        
        SDL_RenderLine(renderer, 100, 200, 200, 400);
        SDL_SetRenderDrawColor(renderer, 0, 255, 240, 0);
        SDL_RenderLine(renderer, 325, 370, 500, 400);
        SDL_RenderLine(renderer, 510, 400, 100, 600);
        SDL_RenderLine(renderer, 200,300 , 250, 270);
        SDL_RenderLine(renderer, 320, 390, 400, 410);
        SDL_RenderLine(renderer, 240, 375, 240, 400);
        SDL_RenderLine(renderer, 625, 200, 400, 200);
        SDL_RenderLine(renderer, 300, 300, 400, 400);
        SDL_RenderLine(renderer, 500, 500, 600, 600);
		SDL_RenderLine(renderer, 100, 100, 200, 200);
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

        SDL_RenderPresent(renderer); // Render the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}