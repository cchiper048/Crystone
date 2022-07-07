#ifndef BLOCK_H
#define BLOCK_H

#include "../engine/engine_include.h"

class Block : public GameObject {
    public:
        void Main() {
            this->BoxCollider2D = true;
        }
        void Update() {
        }
        void Colliding(GameObject &obj) {
            Debug.Log(this->transform.localPosition.x);
        }
};

#endif