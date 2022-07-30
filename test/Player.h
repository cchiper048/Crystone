#ifndef PLAYER_H
#define PLAYER_H

#include "../Qhilius/Qhilius.h"

class Player : public GameObject {
    private:
        bool leftArrow, rightArrow;
        short int speed = 3.0f;

    public:
        void Start() override {
            this->name = "Player";
            this->rect.width = 120;
            this->rect.height = 20;
            this->rect.x = 340;
            this->rect.y = 550;
            this->BoxCollider2D = true;
        }

        void Update() override {
            rightArrow = Input->GetButton(SDL_SCANCODE_RIGHT);
            leftArrow  = Input->GetButton(SDL_SCANCODE_LEFT);

            this->rect.x += speed*(rightArrow-leftArrow);
            if(rect.x < 0) rect.x = 0;
            if(rect.x + rect.width > 800) rect.x = 800 - rect.width;
        }
};

#endif