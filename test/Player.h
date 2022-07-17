#ifndef PLAYER_H
#define PLAYER_H

#include "../crystone/engine_include.h"

class Player : public GameObject {
    private:
        bool leftArrow, rightArrow;
        short int speed = 3.0f;

    public:
        void Start() {
            this->transform.localSize = Vector2(120, 20);
            this->transform.localPosition = Vector2(340, 550);
            this->BoxCollider2D = true;
        }

        void Update() {
            rightArrow = Input->GetButton(SDL_SCANCODE_RIGHT);
            leftArrow  = Input->GetButton(SDL_SCANCODE_LEFT);

            transform.localPosition += Vector2(speed*(rightArrow-leftArrow), 0);
            if(transform.localPosition.x < 0) transform.localPosition.x = 0;
            if(transform.localPosition.x + transform.localSize.x > 800) transform.localPosition.x = 800 - transform.localSize.x;
        }

        void BoxColliding(GameObject &obj) {
            Debug.Log(obj.name);
        }
};

#endif