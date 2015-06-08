//
//  Obstacles.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Obstacles__
#define __CSE167_Spring_2015_Starter_Code__Obstacles__

#include "MatrixTransform.h"

class Obstacles{
public:
    float i,k;
    Matrix4 obstacleMatrix;
    MatrixTransform *obstacle;
    
    Obstacles();
    ~Obstacles();
    void draw(float,float);
    
};

#endif /* defined(__CSE167_Spring_2015_Starter_Code__Obstacles__) */
