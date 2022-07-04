#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include "../gameObject.h"

inline bool AABB_Collision(GameObject &obj1, GameObject &obj2) {
    return  obj1.transform.localPosition.x < obj2.transform.localPosition.x + obj2.transform.localSize.x &&
            obj1.transform.localPosition.x + obj1.transform.localSize.x > obj2.transform.localPosition.x &&
            obj1.transform.localPosition.y < obj2.transform.localPosition.y + obj2.transform.localSize.y &&
            obj1.transform.localPosition.y + obj1.transform.localSize.y > obj2.transform.localPosition.y;
}

#endif

// 3221847