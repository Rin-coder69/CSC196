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
		void ShutDown();

		void Update();
		void Draw();

		Renderer& GetRenderer() const { return *m_renderer; }
		AudioSystem& GetAudio() const { return *m_audio; }
		InputSystem& GetInput() const { return *m_input; }

		Time& GetTime() { return time; }

	private:
		Time time;
		std::unique_ptr<Renderer> m_renderer;
		std::unique_ptr<AudioSystem> m_audio;
		std::unique_ptr<InputSystem> m_input;
	};

	Engine& GetEngine();
	//inline Renderer& GetRenderer() { return GetEngine().GetRenderer(); }
}