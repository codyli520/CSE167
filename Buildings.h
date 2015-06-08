//
//  Buildings.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/2.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Buildings__
#define __CSE167_Spring_2015_Starter_Code__Buildings__
#include "MatrixTransform.h"

class Buildings{
public:
    float i;
    Matrix4 buildMatrix;
    MatrixTransform *building;
    int v1,v2,v3;
    Buildings();
    ~Buildings();
    void draw(float,float,int,int,int);
    
};

#endif /* defined(__CSE167_Spring_2015_Starter_Code__Buildings__) */
