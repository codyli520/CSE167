#include <stdio.h>
#include "Robot.h"
#include "Sphere.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Limbs.h"

Robot::Robot(){
    i =0.0;
    this->robotMatrix.identity();
}

Robot::~Robot(){
    
}
void Robot::draw(float x, float z){
    glPushMatrix();
    glMultMatrixf(robotMatrix.ptr());
    Group *world;
    Matrix4 m3,m4,m5,spin;
    world = new Group();
    //head
    Matrix4 m1,m2;
    m1.identity();
    m2.identity();
    m3.identity();
    
    m1.makeTranslate(0+x, 2, 0.0+z);
    m2.makeRotateY(1.5);
    MatrixTransform headTranslate = *new MatrixTransform(m1);
    MatrixTransform headRotate = *new MatrixTransform(m2);
    
    world->addChild(&headTranslate);
    headTranslate.addChild(&headRotate);
    headRotate.addChild(&Globals::ironman);
    //world->draw(m3);
    
    //body
    m1.identity();
    m2.identity();
    
    m1 = m1.makeTranslate(0.0+x, 0.0, 0.0+z);
    m2 = m2.makeScale(1.5, 2, 1);
    MatrixTransform bodyTranslate = *new MatrixTransform(m1);
    MatrixTransform bodyScale = *new MatrixTransform(m2);
    world->addChild(&bodyTranslate);
    bodyTranslate.addChild(&bodyScale);
    bodyScale.addChild(&Globals::cube);
    //world->draw(m3);
    
    //left arm
    m1.identity();
    m2.identity();
    m4.identity();
    spin.identity();
    m1 = m1.makeTranslate(-1.75+x, 1, 0.0+z);
    m2 = m2.makeScale(0.25, 1.5, 0.25);
    m4 = m4.makeTranslate(0, -1, 0);
    spin = spin.makeRotateX(i);
    m5 = m1.multiply(spin.multiply(m4));
    
    MatrixTransform armLeftTranslate = *new MatrixTransform(m5);
    MatrixTransform armLeftScale = *new MatrixTransform(m2);
    
    world->addChild(&armLeftTranslate);
    armLeftTranslate.addChild(&armLeftScale);
    armLeftScale.addChild(&Globals::limb);
    
    //right arm
    m1.identity();
    m2.identity();
    m4.identity();
    spin.identity();
    m1 = m1.makeTranslate(1.75+x, 1, 0.0+z);
    m2 = m2.makeScale(0.25, 1.5, 0.25);
    m4 = m4.makeTranslate(0, -1, 0);
    spin = spin.makeRotateX(-i);
    m5 = m1.multiply(spin.multiply(m4));

    MatrixTransform armRightTranslate = *new MatrixTransform(m5);
    MatrixTransform armRightScale = *new MatrixTransform(m2);
    
    world->addChild(&armRightTranslate);
    armRightTranslate.addChild(&armRightScale);
    armRightScale.addChild(&Globals::limb);
    
    //left leg
    m1.identity();
    m2.identity();
    m4.identity();
    spin.identity();

    m1 = m1.makeTranslate(-0.75+x, -2, 0.0+z);
    m2 = m2.makeScale(0.5, 1.5, 0.5);
    m4 = m4.makeTranslate(0, -1, 0);
    spin = spin.makeRotateX(-i);
    m5 = m1.multiply(spin.multiply(m4));
    
    MatrixTransform legLeftTranslate = *new MatrixTransform(m5);
    MatrixTransform legLeftScale = *new MatrixTransform(m2);
    
    world->addChild(&legLeftTranslate);
    legLeftTranslate.addChild(&legLeftScale);
    legLeftScale.addChild(&Globals::limb);
    
    //right leg
    m1.identity();
    m2.identity();
    m4.identity();
    spin.identity();
    
    m1 = m1.makeTranslate(0.75+x, -2, 0.0+z);
    m2 = m2.makeScale(0.5, 1.5, 0.5);
    m4 = m4.makeTranslate(0, -1, 0);
    spin = spin.makeRotateX(i);
    m5 = m1.multiply(spin.multiply(m4));

    MatrixTransform legRightTranslate = *new MatrixTransform(m5);
    MatrixTransform legRightScale = *new MatrixTransform(m2);
    
    world->addChild(&legRightTranslate);
    legRightTranslate.addChild(&legRightScale);
    legRightScale.addChild(&Globals::limb);
    
    //left shoulder
    m1.identity();
    m4.identity();
    spin.identity();
    
    m1 = m1.makeTranslate(-1.6+x, 1.3, 0.0+z);
    MatrixTransform shLeftTranslate = *new MatrixTransform(m1);
    world->addChild(&shLeftTranslate);
    shLeftTranslate.addChild(&Globals::sphere);
    
    //right shoulder
    m1.identity();
    m4.identity();
    spin.identity();
    
    m1 = m1.makeTranslate(1.6+x, 1.3, 0.0+z);
    MatrixTransform shRightTranslate = *new MatrixTransform(m1);
    world->addChild(&shRightTranslate);
    shRightTranslate.addChild(&Globals::sphere);
    
    world->draw(m3);
    glPopMatrix();
}
