#ifndef BLOCK_H
#define BLOCK_H

#include "../Crystone/engine_include.h"

class Block : public GameObject {
    public:
        void Main() {
            this->BoxCollider2D = true;
        }

        void Update() {
        }

        void BoxColliding(GameObject &obj, std::string Direction) {
            if(obj.name == "Ball") {
                this->renderObject = false;
                this->BoxCollider2D = false;
            }
        }
};

#endif
