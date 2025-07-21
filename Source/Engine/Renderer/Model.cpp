#include "Model.h"
#include "Renderer/rendeder.h"

namespace gaia {
	void Model::draw(Renderer& renderer, const vec2& position, float roatation, float scale) {

		if(points.empty()) return; // No points to draw
		// Set the color for the model
		renderer.SetColor(color.x, color.y, color.b);
		
		for (int i = 0; i < points.size() - 1; i++) {
				//points[i].Rotate(roatation);
			vec2 p1 = points[i];
					p1 *= scale;
					p1 += position;
				vec2 p2 = points[i + 1].Rotate(roatation)* scale + position;

				renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);
			}
	}
	void Model::draw(Renderer& renderer, const Transform& transform)
	{
		draw(renderer, transform.position, transform.rotation, transform.scale);
	}
}
