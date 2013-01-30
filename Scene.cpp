#include "Scene.h"


Scene::Scene():theEngine(Engine::GetEngine()), theTextureManager(TextureManager::GetInstance()){

}


void Scene::EndScene(){
	Engine::GetEngine().EndCurrentScene();
}

