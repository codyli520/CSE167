//
//  Sphere222.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "Sphere2.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"

Sphere2::Sphere2() :Geode(){
    r= 1;
    g= 0;
    b= 0;
}

Sphere2::~Sphere2(){
    
}
Sphere2::Sphere2(double radius, int slices, int stacks) : Geode()
{
    this->radius = radius;
    this->slices = slices;
    this->stacks = stacks;
}


void Sphere2::render(Matrix4 C) {
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glColor3f(r, g, b);
    glutSolidSphere(1, 10, 10);
    glPopMatrix();
}


