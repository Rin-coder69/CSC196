#pragma once
#include "../Math/vector2.h"
#include <vector>
#include <array>

namespace gaia {
	class InputSystem {
	public:
		enum class MouseButton {
			LEFT = 0,
			MIDDLE = 1,
			RIGHT = 2
		};

	public:
		InputSystem() = default;

		bool Initialize();
		void ShutDown();
		void Update();

		//keyboard input functions
		bool GetKeyDown(uint8_t key) { return m_KeyboardState[key]; }
		bool GetPreviousKeyDown(uint8_t key) { return m_prevKeyboardState[key]; }

		vec2 GetMousePosition() const { return m_mousePosition; }
		vec2 GetPreviousMousePosition() const { return m_prevMousePosition; }

	private:
		vec2 m_mousePosition;
		vec2 m_prevMousePosition;

		std::vector<bool> m_KeyboardState;
		std::vector<bool> m_prevKeyboardState;

		std::array<bool, 3> m_mouseButtonState; // Array for mouse button states
		std::array<bool, 3> m_prevMouseButtonState; // Array for previous mouse button states
	};
}
