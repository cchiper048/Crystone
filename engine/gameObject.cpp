#include "gameObject.h"
#include "./input.h"

GameObject::GameObject() {
    this->Input = nullptr;
}

GameObject::~GameObject() {}

void GameObject::Start(){};
void GameObject::Update(){};

