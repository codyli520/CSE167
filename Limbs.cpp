//
//  Limbs.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15-5-7.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "Limbs.h"


#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"

Limbs::Limbs() : Geode()
{
    
}


Limbs::~Limbs()
{
    //Delete any dynamically allocated memory/objects here
}

Limbs::Limbs(float size)
{
    this->size = size;
}




void Limbs::render(Matrix4 C)
{
    
    
    
    glMultMatrixf(modelView.ptr());
    
    glPushMatrix();
    
    
    glColor3f(1,1, 0);
    // front
    //front.bind();
    glBegin(GL_QUADS);
    
    glVertex3f(size, size, -size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f(size, -size, -size);
    glEnd();
    //front.unbind();
    
    //base
    //base.bind();
    glBegin(GL_QUADS);
    //glColor3f(0.5, 0.5, 0.5);
    glVertex3f(size, -size, size);
    glVertex3f(-size, -size, size);
    glVertex3f(-size, -size, -size);
    glVertex3f(size, -size, -size);
    glEnd();
    //base.unbind();
    
    //top
    //top.bind();
    glBegin(GL_QUADS);
    //glColor3f(0.5, 0.5, 0.5);
    glVertex3f(size, size, size);
    glVertex3f(-size, size, size);
    glVertex3f(-size, size, -size);
    glVertex3f(size, size, -size);
    glEnd();
    //top.unbind();
    
    glColor3f(0.6,0, 0);
    //left
    //left.bind();
    glBegin(GL_QUADS);
    //glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-size, size, size);
    glVertex3f(-size, size, -size);
    glVertex3f(-size, -size, -size);
    glVertex3f(-size, -size, size);
    glEnd();
    //left.unbind();
    
    //right
    //right.bind();
    glBegin(GL_QUADS);
    //glColor3f(0.5, 0.5, 0.5);
    glVertex3f(size, size, -size);
    glVertex3f(size, size, size);
    glVertex3f(size, -size, size);
    glVertex3f(size, -size, -size);
    glEnd();
    //right.unbind();
    
    glColor3f(1,1, 0);
    //back
   
    glBegin(GL_QUADS);
    
    glVertex3f(size, size, size);
    glVertex3f(-size, size, size);
    glVertex3f(-size, -size, size);
    glVertex3f(size, -size, size);
    glEnd();
    ;
    
    glPopMatrix();
    /* swap the back and front buffers so we can see what we just drew */
    //glutSwapBuffers();
}

void Limbs::update(UpdateData& data)
{
    //
}



