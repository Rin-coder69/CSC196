#include "Scene.h"
#include "../Actor/Actor.h"
#include "../Renderer/rendeder.h"
namespace gaia {


		void Scene::update(float deltaTime) {
			for (auto& actor : actors) {
				actor->Update(deltaTime);
			}

		}
		void Scene::draw(class Renderer& renderer) {
			for (auto& actor : actors) {
				actor->Draw(renderer);
			}
		}
		void Scene::AddActor(std::unique_ptr<class Actor> actor) {
			actors.push_back(std::move(actor));

		}
	
}
