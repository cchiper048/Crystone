#ifndef PLAYER_H
#define PLAYER_H

#include "../engine/engine_include.h"

class Player : public GameObject {
    private:
        bool leftArrow, rightArrow;
        short int speed = 3.0f;

    public:
    void Start() {
        transform.localSize = Vector2(120, 20);
        transform.localPosition = Vector2(340, 550);
        BoxCollider2D = true;
    }

    void Update() {
        rightArrow = Input->GetButton(SDL_SCANCODE_RIGHT);
        leftArrow  = Input->GetButton(SDL_SCANCODE_LEFT);

        transform.localPosition += Vector2(speed*(rightArrow-leftArrow), 0);
        if(transform.localPosition.x < 0) transform.localPosition.x = 0;
        if(transform.localPosition.x + transform.localSize.x > 800) transform.localPosition.x = 800 - transform.localSize.x;

    }

    void Colliding(GameObject &obj) {
        Debug.Log(":D");
    }
};

#endif