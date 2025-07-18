#pragma once
#include "Math/transform.h"
#include "../Renderer/Model.h"
namespace gaia {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform, class Model* model) :
			m_transform{ transform },
			m_model{ model }
		{
		}

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer) const;


		Transform GetTransform() {
			return m_transform;
		}


	protected:
		Transform m_transform;

		Model* m_model;
	};
}