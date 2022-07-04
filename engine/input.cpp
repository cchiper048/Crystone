#include "./input.h"
#include "SDL2/SDL.h"
#include <iostream>

InputClass::InputClass() {}
InputClass::~InputClass() {}

void InputClass::Update(const SDL_Event &event) {
    Pressed_Keys.clear();
    Released_Keys.clear();

    if(event.type == SDL_KEYDOWN) {
        this->Pressed_Keys[event.key.keysym.scancode] = true;
        this->Held_Keys[event.key.keysym.scancode] = true;

    } else if(event.type == SDL_KEYUP) {
        this->Released_Keys[event.key.keysym.scancode] = true;
        this->Held_Keys[event.key.keysym.scancode] = false;
    }
}

bool InputClass::GetButton(SDL_Scancode key) {
    return Held_Keys[key];
}

inline bool InputClass::GetButtonDown(SDL_Scancode key) {
    return Pressed_Keys[key];
}

inline bool InputClass::GetButtonUp(SDL_Scancode key) {
    return Released_Keys[key];
}
