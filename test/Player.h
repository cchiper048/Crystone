#ifndef PLAYER_H
#define PLAYER_H

#include "../engine/engine_include.h"

class Player : public GameObject {
    public:
    Bool W,A,S,D;
    void Start() {}
    void Update() {
        size = Vector2(75, 75);
        W = Input->GetButton(SDL_SCANCODE_W);
        A = Input->GetButton(SDL_SCANCODE_A);
        S = Input->GetButton(SDL_SCANCODE_S);
        D = Input->GetButton(SDL_SCANCODE_D);


        position += Vector2(1.5f*D-1.5f*A, 1.5f*S - 1.5f*W);
        // std::cout << 1.5f*D-1.5f*A << " " << 1.5f*S - 1.5f*W << '\n';
        // std::cout << W << A << S << D << '\n';
    }
};

#endif