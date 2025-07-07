#pragma once
#include <SDL3/SDL.h>
namespace gaia
{

	class Renderer {
	public:
		Renderer() = default;

		bool Initialize();

		void DrawPoint(float x, float y);

		void ShutDown();

		bool CreateWindow(const std::string& name, int width, int height);

		void Clear();

		void Present();

		void DrawLine(float x1, float y1, float x2, float y2);

		void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
	private:
		SDL_Window* window = nullptr;//<---member variable for the SDL window
		SDL_Renderer* renderer = nullptr;//<---member variable for the SDL renderer 
	};
};