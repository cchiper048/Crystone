#ifndef BALL_H
#define BALL_H

#include "../Crystone/Crystone.h"

class Ball : public GameObject {
    public:
        short int speedX = -2, speedY = 2;
        void Start() override {
            this->name = "Ball";
            this->transform.localSize = Vector2(16, 16);
            this->transform.localPosition = Vector2(392, 530);
            this->BoxCollider2D = true;
        }

        void Update() override {
            if (this->transform.localPosition.x < 0) {
                this->transform.localPosition.x = 0;
                speedX *= -1;
            }

            if (this->transform.localPosition.x + this->transform.localSize.x > 800) {
                this->transform.localPosition.x = 800-this->transform.localSize.x;
                speedX *= -1;
            }

            if (this->transform.localPosition.y < 0) {
                this->transform.localPosition.y = 0;
                speedY *= -1;
            }

            this->transform.localPosition += Vector2(speedX, speedY);
        }

        void BoxColliding(GameObject &obj, std::string direction) override {
            if(direction == "Top") {
                this->speedY = 2;
                this->transform.localPosition.y = obj.transform.localPosition.y + obj.transform.localSize.y;
            }
            else if(direction == "Bottom") {
                this->speedY = -2;
                this->transform.localPosition.y = obj.transform.localPosition.y - this->transform.localSize.y;
            }
            else if(direction == "Left") {
                this->speedX = 2;
                this->transform.localPosition.x = obj.transform.localPosition.x + obj.transform.localSize.x;
            }
            else if(direction == "Right") {
                this->speedX = -2;
                this->transform.localPosition.x = obj.transform.localPosition.x - this->transform.localSize.x;
            }

            if(obj.name == "Player") {
                this->speedY = -2;
            }
        }
};


#endif