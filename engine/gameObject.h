#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "./helpers/vector.h"

struct InputClass;

struct Transform {
    Vector2 localPosition;
    Vector2 localSize;
};

class GameObject {
    public:
        GameObject();
        ~GameObject();

        virtual void Start();
        virtual void Update();
        virtual void BoxColliding(GameObject &obj);
        
        bool renderObject = true;
        bool BoxCollider2D = false;
        InputClass *Input;
        Transform transform;
};



#endif