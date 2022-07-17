#include "gameObject.h"
#include <iostream>
#include "./input.h"

GameObject::GameObject() {
    this->Input = nullptr;
}

GameObject::~GameObject() {};

void GameObject::Start() {};
void GameObject::Update() {};
void GameObject::BoxColliding(GameObject &obj) {};

