#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "../gameObject.h"

inline bool AABB_Collision(GameObject &obj1, GameObject &obj2) {
    return  obj1.position.x < obj2.position.x + obj2.size.x &&
            obj1.position.x + obj1.size.x > obj2.position.x &&
            obj1.position.y < obj2.position.y + obj2.size.y &&
            obj1.position.y + obj1.size.y > obj2.position.y;
}

#endif

// 3221847