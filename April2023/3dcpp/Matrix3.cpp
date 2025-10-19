#include "Vector3f.h"
#include "Matrix3.h"

Matrix3::Matrix3(float val0, float val1, float val2, 
            float val3, float val4, float val5, 
            float val6, float val7, float val8) 
            : val0(val0), val1(val1), val2(val2), 
              val3(val3), val4(val4), val5(val5), 
              val6(val6), val7(val7), val8(val8) {};
Matrix3::Matrix3(Vector3f vec0, Vector3f vec1, Vector3f vec2){
    this->val0 = vec0.x;
    this->val1 = vec0.y;
    this->val2 = vec0.z;

    this->val3 = vec1.x;
    this->val4 = vec1.y;
    this->val5 = vec1.z;

    this->val6 = vec2.x;
    this->val7 = vec2.y;
    this->val8 = vec2.z;
};

float* Matrix3::getFArray(){};
Matrix3::~Matrix3(){};
