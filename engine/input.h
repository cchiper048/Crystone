#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL.h"
#include "./helpers/types.h"
#include <map>
#include <iostream>

class InputClass {
    public:
        InputClass();
        ~InputClass();

        U0 Update(const SDL_Event &event);
        Bool GetButton(SDL_Scancode key);
        Bool GetButtonDown(SDL_Scancode key);
        Bool GetButtonUp(SDL_Scancode key);
        
    private:
        std::map<SDL_Scancode, Bool> Held_Keys;
        std::map<SDL_Scancode, Bool> Pressed_Keys;
        std::map<SDL_Scancode, Bool> Released_Keys;
};

#endif

