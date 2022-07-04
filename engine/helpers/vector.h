#ifndef UTILS_H
#define UTILS_H

struct Vector2 {
    public:
        Vector2(): x(0.F), y(0.F){}
        Vector2(int x,    int    y): x((float)x), y((float)y){}
        Vector2(float x,  float  y): x((float)x), y((float)y){}
        Vector2(double x, double y): x((float)x), y((float)y){}

        float x, y;

        inline Vector2& operator+=(const Vector2 &vec) {
            this->x += (float)vec.x;
            this->y += (float)vec.y;
            return *this;
        }

        inline Vector2& operator=(const Vector2 &vec) {
            this->x = (float)vec.x;
            this->y = (float)vec.y;
            return *this;
        }
};

#endif
