#pragma once
#include <cassert>
#include "math.h"
namespace gaia {
	template<typename T>
	struct  Vector2 {
		float x, y;

		Vector2() = default;
		Vector2(T x, T y) : x{ x }, y{ y } {}

		T operator [] (unsigned int index) const{ assert(index < 2); return(&x)[index]; }

		T& operator [] (unsigned int index) { assert(index < 2); return(&x)[index]; };
		


		Vector2 operator + (const Vector2& v) const { return Vector2{ x + v.x, y + v.y }; }
		Vector2 operator - (const Vector2& v) const { return Vector2{ x - v.x, y - v.y }; }
		Vector2 operator * (const Vector2& v) const { return Vector2{ x * v.x, y * v.y }; }
		Vector2 operator / (const Vector2& v) const { return Vector2{ x / v.x, y / v.y }; }

		Vector2 operator + (float s) const { return Vector2{ x + s, y + s }; }
		Vector2 operator - (float s) const { return Vector2{ x - s, y - s }; }
		Vector2 operator * (float s) const { return Vector2{ x * s, y * s }; }
		Vector2 operator / (float s) const { return Vector2{ x / s, y / s }; }

		Vector2& operator += (float s) { x += s; y += s; return *this; }
		Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s; y /= s; return *this; }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }
		//square root (x * x + y * y)
		/// 
		float lengthSqr() const { return(x * x) + (y * y); }
		float length() const{ return gaia::math::sqrtf(lengthSqr()); }
	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}


/*Vector2<int> iv;
 Vector2<float> fv;*/
 