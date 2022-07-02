#ifndef UTILS_H
#define UTILS_H
#include "./types.h"

//--- Vector ---//
struct Vector2 {
    public:
        Vector2(): x(0.F), y(0.F){}
        Vector2(I32 x, I32 y): x((F32)x), y((F32)y){}
        Vector2(F32 x, F32 y): x((F32)x), y((F32)y){}
        Vector2(F64 x, F64 y): x((F32)x), y((F32)y){}

        float x, y;

        inline Vector2& operator+=(const Vector2 &vec) {
            this->x += (F32)vec.x;
            this->y += (F32)vec.y;
            return *this;
        }

        inline Vector2& operator=(const Vector2 &vec) {
            this->x = (F32)vec.x;
            this->y = (F32)vec.y;
            return *this;
        }
};

#endif
