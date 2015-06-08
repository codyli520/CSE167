//
//  Buildings.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/2.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Buildings.h"
#include "Sphere.h"
#include "Cube.h"
#include "Block.h"
#include "Cylinder.h"
#include "Limbs.h"

Buildings::Buildings(){
    i =0.0;
    this->buildMatrix.identity();
}

Buildings::~Buildings(){
    
}
void Buildings::draw(float x, float z, int v1,int v2, int v3){
    glPushMatrix();
    glMultMatrixf(buildMatrix.ptr());
    Group *world;
    Matrix4 m3,m4,m5,spin;
    world = new Group();
    //head
    Matrix4 m1,m2;
    m1.identity();
    m2.identity();
    m3.identity();
    
    
    m1 = m1.makeTranslate(0.0+x, -10, 0.0+z);

    m2 = m2.makeScale(v1, v2, v3);
    MatrixTransform bodyTranslate = *new MatrixTransform(m1);
    MatrixTransform bodyScale = *new MatrixTransform(m2);
    world->addChild(&bodyTranslate);
    bodyTranslate.addChild(&bodyScale);
    bodyScale.addChild(&Globals::block);
    //world->draw(m3);
    
    world->draw(m3);
    glPopMatrix();
}

