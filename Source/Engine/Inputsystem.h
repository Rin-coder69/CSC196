#pragma once
#include <vector>
namespace gaia {
	class InputSystem {
	public:
		InputSystem() = default;

		bool Initialize();

		void ShutDown();
		void update();

		//keyboard input functions
		bool GetKeydown(uint8_t key) { return m_KeyboardState[key]; }
		bool GetPreviousKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }

	private:
		std::vector<bool> m_KeyboardState;
		std::vector<bool> m_prevKeyboardState;
	};
}
