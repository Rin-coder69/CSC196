#pragma once
#include <algorithm>
#include <SDL3/SDL.h>
#include <cmath>
namespace gaia {
	namespace math {
		constexpr float PI = 3.14159265358979323846f;
		constexpr float TWO_PI = 2 * PI;
		constexpr float HALF_PI = PI / 2;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="rad"></param>
		/// <returns></returns>
		constexpr float radToDeg(float rad) { return rad * (180 / PI); }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="deg"></param>
		/// <returns></returns>
		constexpr float degToRad(float deg) { return degToRad(deg) * (PI / 180); }

		using std::min;
		using std::max;
		using std::clamp;
		using std::sqrtf;
		using std::sqrt;
		using std::cos;
		using std::sin;
		using std::atan2;
		using std::atan2f;
		using std::cosf;
		using std::sinf;



	};
}