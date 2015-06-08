#ifndef CSE167_Robot_h
#define CSE167_Robot_h

#include "MatrixTransform.h"

class Robot{
public:
    float i,k;
    bool bound = false;
    Matrix4 robotMatrix;
    MatrixTransform *robot;
    
    Robot();
    ~Robot();
    void draw(float,float);
    
};

#endif
