#ifndef BLOCK_H
#define BLOCK_H

#include "../engine/engine_include.h"

class Block : public GameObject {
    public:
        void Main() {
            BoxCollider2D = true;
        }
        void Update() {
            
        }
};

#endif