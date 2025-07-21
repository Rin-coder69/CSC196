#include "Engine.h"
#include "Renderer/rendeder.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
namespace gaia{

	Engine& GetEngine()
	{
		static Engine engine;
		return engine;
	}

	bool Engine::Initialize() {
		
		renderer = std::make_unique<gaia::Renderer>();

		renderer->Initialize();
		renderer->CreateWindow("gaia Engine", 1280, 1024);


		std::unique_ptr<gaia::InputSystem> inputSystem = std::make_unique<gaia::InputSystem>();
		inputSystem->Initialize();



		std::unique_ptr<gaia::AudioSystem> audio = std::make_unique<gaia::AudioSystem>();
		audio->Initialize();

		
		
		
		// Initialize all subsystems
		return true;


		}

	void Engine::ShutDown() {
		Audio->ShutDown();
		renderer->ShutDown();
		InputSystem->ShutDown();
		SDL_Quit();
		std::cout << "Engine shut down successfully." << std::endl;
	}

	void Engine::Update() {
		time.Tick();
		Audio->Update();
		InputSystem->Update();
		renderer->Clear();
	}
	
}