#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "./helpers/vector.h"
#include <string>

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
        virtual void BoxColliding(GameObject &obj, std::string dirrection);
        
        std::string name;
        std::string tag;
        bool renderObject = true;
        bool BoxCollider2D = false;
        InputClass *Input;
        Transform transform;
};


#endif