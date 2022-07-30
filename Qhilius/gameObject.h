#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "./helpers/vector.h"
#include "./helpers/connectedValue.h"
#include <string>

struct InputClass;

struct Rect {
    Rect() {
            this->right = connectedValue(&this->x, &this->width);
            this->bottom = connectedValue(&this->y, &this->height);
    };
    float x{};
    float y{};
    float  width{};
    float height{};
    connectedValue right{};
    connectedValue bottom{};
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
        Rect rect;
};


#endif