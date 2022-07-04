#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL.h"
#include <map>
#include <iostream>

class InputClass {
    public:
        InputClass();
        ~InputClass();

        void Update(const SDL_Event &event);
        bool GetButton(SDL_Scancode key);
        bool GetButtonDown(SDL_Scancode key);
        bool GetButtonUp(SDL_Scancode key);
        
    private:
        std::map<SDL_Scancode, bool> Held_Keys;
        std::map<SDL_Scancode, bool> Pressed_Keys;
        std::map<SDL_Scancode, bool> Released_Keys;
};

#endif

