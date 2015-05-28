//
//  Cylinder.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15-5-6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Cylinder__
#define __CSE167_Spring_2015_Starter_Code__Cylinder__

#include <stdio.h>
#include <iostream>
#include "Drawable.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "Texture.h"
#include "Geode.h"

class Cylinder: public Geode
{
    
public:
    Cylinder();
    Cylinder(float,float);
    float radius,height;
    Texture face;
    void render(Matrix4);
    
    
};


#endif /* defined(__CSE167_Spring_2015_Starter_Code__Cylinder__) */
