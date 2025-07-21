#pragma once
#include "core/Time.h"
#include <memory>
#define RENDERER gaia::GetEngine().GetRenderer()
namespace gaia {
	class Renderer;
	class AudioSystem;
	class InputSystem;
	class Engine {

	public:
		Engine() = default;

		bool Initialize();
		void Update();
		void ShutDown();

		void Update();
		void Draw();

		Renderer& GetRenderer() const { return *renderer; }
		AudioSystem& GetAudio() const { return *audio; }
		InputSystem& GetInput() const { return *inputsystem; }

		Time& GetTime() { return time; }

	private:
		Time time;
		std::unique_ptr<Renderer> renderer;
		std::unique_ptr<AudioSystem> audio;
		std::unique_ptr<InputSystem> inputsystem;
	};

	Engine& GetEngine();
	inLine Renderer& GetRenderer() { return GetEngine().GetRenderer(); }
}