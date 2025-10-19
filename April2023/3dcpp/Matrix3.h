#include "Vector3f.h"

class Matrix3{
    float val0;
    float val1;
    float val2;
    float val3;
    float val4;
    float val5;
    float val6;
    float val7;
    float val8;
public:
    Matrix3(float val0, float val1, float val2, 
            float val3, float val4, float val5, 
            float val6, float val7, float val8);
    Matrix3(Vector3f vec1, Vector3f vec2, Vector3f vec3);
    float* getFArray();
    ~Matrix3();
};