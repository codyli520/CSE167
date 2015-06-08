//
//  Sphere2.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Sphere2__
#define __CSE167_Spring_2015_Starter_Code__Sphere2__

#include <stdio.h>
#include "Drawable.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "Geode.h"

class Sphere2 : public Geode
{
    
public:
    Sphere2();
    ~Sphere2();
    double radius;
    int slices, stacks;
    
    Sphere2(double, int, int);
    
    void render(Matrix4);
    //void render();
    double r,g,b;
    
    
};

#endif