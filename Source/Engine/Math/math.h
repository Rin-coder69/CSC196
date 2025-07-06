#pragma once
#include <algorithm>
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


	}
}