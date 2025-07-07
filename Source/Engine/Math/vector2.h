#pragma once
template<typename T>
 struct  Vector2 {
	float x, y;

	Vector2() = default;
	Vector2(T x, T y) : x{ x }, y{ y } {}
};

 using ivec2 = Vector2<int>;
 using vec2 = Vector2<float>;


/*Vector2<int> iv;
 Vector2<float> fv;*/
 