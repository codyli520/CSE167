//
//  Obstacles.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "Obstacles.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Limbs.h"

Obstacles::Obstacles(){
    i =0.0;
    k = -0.5;
    this->obstacleMatrix.identity();
}

Obstacles::~Obstacles(){
    
}
void Obstacles::draw(float x, float z){
    
    glPushMatrix();
    
    glMultMatrixf(obstacleMatrix.ptr());
    Group *world;
    Matrix4 m1,m2,m3,m4,m5,spin;
    world = new Group();
    
    //left arm
    m1.identity();
    m2.identity();
    m3.identity();
    //m4.identity();
    //spin.identity();
    m1 = m1.makeTranslate(0.0+x,150, 0.0+z);
    m2 = m2.makeScale(5, 125, 5);
    //m4 = m4.makeTranslate(0, -1, 0);
    //spin = spin.makeRotateZ(k);
    //m5 = m1.multiply(m4);
    
    MatrixTransform LeftTranslate = *new MatrixTransform(m1);
    MatrixTransform LeftScale = *new MatrixTransform(m2);
    
    world->addChild(&LeftTranslate);
    LeftTranslate.addChild(&LeftScale);
    LeftScale.addChild(&Globals::block);
    
    //right arm
    m1.identity();
    m2.identity();
    //m4.identity();
    //spin.identity();
    m1 = m1.makeTranslate(0.0+x, -150, 0.0+z);
    m2 = m2.makeScale(5, 125, 5);
    //m4 = m4.makeTranslate(0, -1, 0);
    //spin = spin.makeRotateZ(-k);
    //m5 = m1.multiply(spin.multiply(m4));
    
    MatrixTransform RightTranslate = *new MatrixTransform(m1);
    MatrixTransform RightScale = *new MatrixTransform(m2);
    
    world->addChild(&RightTranslate);
    RightTranslate.addChild(&RightScale);
    RightScale.addChild(&Globals::block);
    
    
    world->draw(m3);
    glPopMatrix();
}