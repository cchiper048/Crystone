#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "./helpers/vector.h"

struct InputClass;

class GameObject {
    public:
        GameObject();
        ~GameObject();

        virtual void Start();
        virtual void Update();
        virtual void Colliding(GameObject &obj);
        
        bool renderObject = true;
        bool BoxCollider2D = false;
        Vector2 position;
        Vector2 size;
        InputClass *Input;
};

#endif