#include "./input.h"
#include "./helpers/types.h"
#include "SDL2/SDL.h"
#include <iostream>

InputClass::InputClass() {}
InputClass::~InputClass() {}

U0 InputClass::Update(const SDL_Event &event) {
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

Bool InputClass::GetButton(SDL_Scancode key) {
    return Held_Keys[key];
}

inline Bool InputClass::GetButtonDown(SDL_Scancode key) {
    return Pressed_Keys[key];
}

inline Bool InputClass::GetButtonUp(SDL_Scancode key) {
    return Released_Keys[key];
}
