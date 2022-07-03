#ifndef PLAYER_H
#define PLAYER_H

#include "../engine/engine_include.h"

class Player : public GameObject {
    private:
        Bool W,A,S,D;

    public:
    U0 Start() {
        size = Vector2(75, 75);
        BoxCollider2D = true;
    }

    U0 Update() {
        W = Input->GetButton(SDL_SCANCODE_W);
        A = Input->GetButton(SDL_SCANCODE_A);
        S = Input->GetButton(SDL_SCANCODE_S);
        D = Input->GetButton(SDL_SCANCODE_D);


        position += Vector2(1.5f*D-1.5f*A, 1.5f*S - 1.5f*W);
    }

    U0 Colliding(GameObject &obj) {
        Debug.Log(":D");
    }
};

#endif