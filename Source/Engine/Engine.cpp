#include "Engine.h"
#include "Render/Renderer.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
namespace gaia{

	Engine& GetEngine()
	{
		static Engine engine;
		return engine;
	}

	bool Engine::Initialize() {
		
		// Initialize all subsystems
		m_renderer = std::make_unique<gaia::Renderer>();

		m_renderer->Initialize();
		m_renderer->CreateWindow("gaia Engine", 1280, 1024);

		m_input = std::make_unique<gaia::InputSystem>();
		m_input->Initialize();

		m_audio = std::make_unique<gaia::AudioSystem>();
		m_audio->Initialize();

		
		return true;
	}

	void Engine::ShutDown() {
		m_audio->ShutDown();
		m_renderer->ShutDown();
		m_input->ShutDown();

		std::cout << "Engine shut down successfully." << std::endl;
	}

	void Engine::Update() {
		time.Tick();
		m_audio->Update();
		m_input->Update();
	}

	void Engine::Draw()
	{
		//renderer->Clear();

	}
	
}