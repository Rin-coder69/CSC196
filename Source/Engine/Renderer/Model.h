#pragma once
#include "../Engine/Math/vector2.h"
#include "../Engine/Math/vector3.h"
#include "../Engine/Math/transform.h"
#include <vector>


namespace gaia {
	class Model{
	public:
		Model() = default;
		Model(const std::vector<gaia::vec2>& points, const vec3& color):
			points{points},
			color{ color } {
		}
		void draw(class Renderer& renderer, const vec2& position, float roatation, float scale);
		void draw(class Renderer& renderer, const Transform& transform);

	private:
		std::vector<gaia::vec2> points;
		vec3 color{ 1.0f, 1.0f, 1.0f }; // Default color white
		};
} 