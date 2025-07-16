#include "Actor.h"
#include "Renderer/rendeder.h"

void gaia::Actor::Update(float dt) {

}

void gaia::Actor::Draw(class Renderer& renderer) const {
	if (m_model) {
		m_model->Draw(renderer, m_transform);
	}
}