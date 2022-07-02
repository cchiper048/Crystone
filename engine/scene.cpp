#include "./scene.h"

Scene::Scene(){};
Scene::~Scene(){};

void Scene::addObject(GameObject &obj){
    objects.push_back(&obj);
}
