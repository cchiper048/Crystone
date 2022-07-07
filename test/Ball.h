#ifndef BALL_H
#define BALL_H

#include "../engine/engine_include.h"

class Ball : public GameObject {
    public:
        short int speedX = 1, speedY = 1;
        void Start() {
            this->transform.localSize = Vector2(16, 16);
            this->transform.localPosition = Vector2(392, 20);
            this->BoxCollider2D = true;
        }

        void Update() {
            if(this->transform.localPosition.x < 0) 
                speedX *= -1;
            
            if(this->transform.localPosition.x + this->transform.localSize.x > 800)
                speedX *= -1;

            if(this->transform.localPosition.y < 0)
                speedY *= -1;

            this->transform.localPosition += Vector2(speedX, speedY);
        }
};


#endif