#ifndef _ALGORITHM_H
#define _ALGORITHM_H

#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include "../gameObject.h"

inline bool AABB_Collision(GameObject &obj1, GameObject &obj2) {
    return  obj1.rect.x < obj2.rect.x + obj2.rect.width &&
            obj1.rect.x + obj1.rect.width > obj2.rect.x &&
            obj1.rect.y < obj2.rect.y + obj2.rect.height &&
            obj1.rect.y + obj1.rect.height > obj2.rect.y;
}

inline std::pair<std::string, std::string> collisionSide(GameObject &obj1, GameObject &obj2) {
    const float obj1B_obj2T = abs((obj1.rect.y + obj1.rect.height) - obj2.rect.y );
    const float obj1T_obj2B = abs(obj1.rect.y - (obj2.rect.y + obj2.rect.height) );
    const float obj1L_obj2R = abs(obj1.rect.x - (obj2.rect.x + obj2.rect.width) );
    const float obj1R_obj2L = abs((obj1.rect.x + obj1.rect.width) - obj2.rect.x );

    const float minimumD = std::min(std::min(obj1B_obj2T, obj1T_obj2B), std::min(obj1L_obj2R, obj1R_obj2L));

    if(obj1B_obj2T == minimumD) return {"Bottom", "Top"};
    else if(obj1T_obj2B == minimumD) return {"Top", "Bottom"};
    else if(obj1L_obj2R == minimumD) return {"Left", "Right"};
    else return {"Right", "Left"};
}

#endif

// 3221847