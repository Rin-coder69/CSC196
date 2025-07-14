#pragma once
#include "../Math/vector2.h"
#include <vector>
#include "SDL3/SDL.h"
#include <array>



namespace gaia {
	class InputSystem {
	public:
		enum class MouseButton : uint8_t
		{
			LEFT ,
			MIDDLE ,
			RIGHT,
		};

	public:
		InputSystem() = default;

		bool Initialize();

		void ShutDown();
		void Update();

		//key updates
		bool GetKeyDown(uint8_t key)
		{
			return m_KeyboardState[key];
		}

		bool getprevKeyDown(uint8_t key) {
			return m_prevKeyboardState[key];
		}
		bool GetKeyPressed(uint8_t key) 
		{return m_KeyboardState[key] && !m_prevKeyboardState[key];}	

		bool GetKeyReleased(uint8_t key)
		{
			return !m_KeyboardState[key] && m_prevKeyboardState[key];
		}

		const vec2& GetMousePosition() const { return m_mousePosition; }
		const vec2& GetPreviousMousePosition() const { return m_prevMousePosition; }
		//mouse inputs
		bool getMouseButtonDown(MouseButton button)  {  return m_mouseButtonState[(uint8_t)button]; }
		bool getPreviousMouseButtonDown(MouseButton button) { return m_prevMouseButtonState[(uint8_t)button]; }
		bool getMouseButtonPressed(MouseButton button) {  return m_mouseButtonState[(uint8_t)button] && !m_prevMouseButtonState[(uint8_t)button]; }
		bool getMouseButtonReleased(MouseButton button)  { return !m_mouseButtonState[(uint8_t)button] && m_prevMouseButtonState[(uint8_t)button]; }
	private:
		 std::vector<bool> m_KeyboardState; // current keyboard state
		 std::vector<bool> m_prevKeyboardState; // previous keyboard state

		 vec2 m_mousePosition{ 0, 0 };
		 vec2 m_prevMousePosition{ 0, 0 };

		 std::array<bool, 3> m_mouseButtonState{ false,false,false }; // current mouse button state
		 std::array<bool, 3> m_prevMouseButtonState{ false,false,false }; // previous mouse button state
	};
}
