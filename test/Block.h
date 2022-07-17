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
};

#endif