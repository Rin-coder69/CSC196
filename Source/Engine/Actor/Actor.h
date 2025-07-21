#pragma once
#include "Math/transform.h"
#include "../Renderer/Model.h"
#include <memory>
namespace gaia {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform, class std:: shared_ptr<Model>models) :
			m_transform{ transform },
			m_model{models}
		{
		}

		virtual void Update(float dt);

		virtual void Draw(class Renderer& renderer) const;


		Transform GetTransform() {
			return m_transform;
		}


	protected:
		Transform m_transform;
		std::shared_ptr<Model> m_model; // Use shared_ptr for better memory management
	};
}