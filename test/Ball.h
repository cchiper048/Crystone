#ifndef BALL_H
#define BALL_H

#include "../Qhilius/Qhilius.h"

class Ball : public GameObject {
    public:
        short int speedX = -2, speedY = 2;
        void Start() override {
            this->name = "Ball";
            this->rect.width = 16;
            this->rect.height = 16;

            this->rect.x = 392;
            this->rect.y = 530;
            this->BoxCollider2D = true;
        }

        void Update() override {
            if (this->rect.x < 0) {
                this->rect.x = 0;
                speedX *= -1;
            }

            if (this->rect.right > 800) {
                this->rect.right = 800;
                speedX *= -1;
            }

            if (this->rect.y < 0) {
                this->rect.y = 0;
                speedY *= -1;
            }

            this->rect.x += speedX;
            this->rect.y += speedY;
        }

        void BoxColliding(GameObject &obj, std::string direction) override {
            if(direction == "Top") {
                this->speedY = 2;
                this->rect.y = obj.rect.y + obj.rect.height;
            }
            else if(direction == "Bottom") {
                this->speedY = -2;
                this->rect.y = obj.rect.y - this->rect.height;
            }
            else if(direction == "Left") {
                this->speedX = 2;
                this->rect.x = obj.rect.x + obj.rect.width;
            }
            else if(direction == "Right") {
                this->speedX = -2;
                this->rect.x = obj.rect.x - this->rect.width;
            }

            if(obj.name == "Player") {
                this->speedY = -2;
            }
        }
};


#endif