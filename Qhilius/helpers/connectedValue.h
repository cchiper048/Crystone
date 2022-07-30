#ifndef QHILIUS_CONNECTEDVALUE_H
#define QHILIUS_CONNECTEDVALUE_H

struct connectedValue {
    connectedValue() = default;
    connectedValue(float *value1, float *value2) {
        this->value1 = value1;
        this->value2 = value2;
    }
    float *value1;
    float *value2;
    connectedValue& operator=(const int &num) {
        *value1 = (float)num - *value2;
        return *this;
    }
    connectedValue& operator=(const float &num) {
        *value1 = num - *value2;
        return *this;
    }
    float operator+(const float &num) const {
        return (*value1 + *value2 + num);
    }
    float operator-(const float &num) const {
        return (*value1 + *value2 - num);
    }
    float operator+=(const float &num) const {
        *value1 += num;
        return *value1 + *value2;
    }
    float operator-=(const float &num) const {
        *value1 -= num;
        return *value1 + *value2;
    }
    float operator++(int) const {
        *value1 += 1;
        return *value1 + *value2;
    }
    float operator--(int) const {
        *value1 -= 1;
        return *value1 + *value2;
    }
    bool operator==(const int &num) const {
        return (*value1 + *value2) == (float)num;
    }
    bool operator==(const float &num) const {
        return (*value1 + *value2) == num;
    }
    bool operator>(const int &num) const {
        return (*value1 + *value2) > (float)num;
    }
    bool operator>(const float &num) const {
        return (*value1 + *value2) > num;
    }
    bool operator<(const int &num) const {
        return (*value1 + *value2) < (float)num;
    }
    bool operator<(const float &num) const {
        return (*value1 + *value2) < num;
    }
    bool operator>=(const int &num) const {
        return (*value1 + *value2) >= (float)num;
    }
    bool operator>=(const float &num) const {
        return (*value1 + *value2) >= num;
    }
    bool operator<=(const int &num) const {
        return (*value1 + *value2) <= (float)num;
    }
    bool operator<=(const float &num) const {
        return (*value1 + *value2) <= num;
    }
};

#endif
