#ifndef BLOCK_H
#define BLOCK_H

#include "../Qhilius/Qhilius.h"

class Block : public GameObject {
    public:
        void Start() {
            this->BoxCollider2D = true;
        }

        void Update() override {
        }

        void BoxColliding(GameObject &obj, const std::string direction) override {
            if(obj.name == "Ball") {
                this->renderObject = false;
                this->BoxCollider2D = false;
            }
        }
};

#endif
