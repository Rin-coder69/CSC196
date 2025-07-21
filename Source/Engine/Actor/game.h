#pragma once
namespace gaia {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;

		virtual void Update() = 0;

		virtual void ShutDown() = 0;


	private:
		std::unique_ptr<class Scene> Scene;
	};
}