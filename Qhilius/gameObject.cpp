#include "gameObject.h"
#include <iostream>
#include "./input.h"

GameObject::GameObject() {
    this->Input = nullptr;
    this->name = "";
    this->tag = "";
}

GameObject::~GameObject() = default;;

void GameObject::Start() {};
void GameObject::Update() {};
void GameObject::BoxColliding(GameObject &obj, const std::string direction) {};

