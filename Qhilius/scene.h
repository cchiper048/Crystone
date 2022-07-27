#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "./gameObject.h"

// struct GameObject{};

class Scene {
    public:
        Scene();
        ~Scene();
        void addObject(GameObject &obj);

        std::vector<GameObject *> objects;
};

#endif
