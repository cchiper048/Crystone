#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "./helpers/includes.h"
#include "./helpers/types.h"
#include "./helpers/vector.h"

struct InputClass;

class GameObject {
    public:
        GameObject();
        ~GameObject();

        virtual void Start();
        virtual void Update();
        
        Vector2 position;
        Vector2 size;
        bool renderObject = true;
        InputClass *Input;
};

#endif