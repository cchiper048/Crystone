#include "gameObject.h"
#include <iostream>
#include "./helpers/types.h"
#include "./input.h"

GameObject::GameObject() {
    this->Input = nullptr;
}

GameObject::~GameObject() {};

U0 GameObject::Start() {};
U0 GameObject::Update() {};
U0 GameObject::Colliding(GameObject &obj) {};

