//
//  Cylinder.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15-5-6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "Cylinder.h"
#include <stdlib.h>
#include <stdio.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>   // include math functions, such as sin, cos, M_PI
#include <iostream>
using namespace std;

Cylinder::Cylinder() : Geode()
{
    
}

Cylinder::Cylinder(float height, float radius)
{
    this->height = height;
    this->radius = radius;
    face  = Texture("ironman.ppm");
}

void Cylinder::render(Matrix4 C)
{
    const double PI = 3.14159;
    
    /* top triangle */
    double i, resolution  = 0.1;
    //double height = 1;
    //double radius = 0.5;
    glDisable(GL_LIGHT0);
    glMultMatrixf(modelView.ptr());
    
    glPushMatrix();
    //glTranslatef(C.m[3][0], C.m[3][1], C.m[3][2]);
    
    glBegin(GL_TRIANGLE_FAN);
    //glTexCoord2f( 0.5, 0.5 );
    glColor3f(0.6,0, 0);
    glVertex3f(0, height, 0);  /* center */
    for (i = 2 * PI; i >= 0; i -= resolution)
        
    {
        //glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glColor3f(0.6, 0,0);
        glVertex3f(radius * cos(i), height, radius * sin(i));
    }
    /* close the loop back to 0 degrees */
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(radius, height, 0);
    glEnd();
    
    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
    //glTexCoord2f( 0.5, 0.5 );
    glColor3f(0.6, 0, 0);
    glVertex3f(0, 0, 0);  /* center */
    for (i = 0; i <= 2 * PI; i += resolution)
    {
        //glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glColor3f(0.6, 0, 0);
        glVertex3f(radius * cos(i), 0, radius * sin(i));
    }
    glEnd();
    
    /* middle tube */
    face.bind();
    glBegin(GL_QUAD_STRIP);
    for (i = -PI/2; i <= 3*PI/2; i += resolution)
    {
        const float tc = ( i / (float)( 2 * PI ) );
        glColor3f(1, 1, 1);
        glTexCoord2f( tc, 1.0 );
        glVertex3f(radius * cos(i), 0, radius * sin(i));
        glTexCoord2f( tc, 0.0 );
        glVertex3f(radius * cos(i), height, radius * sin(i));
    }
    /* close the loop back to zero degrees */
    glTexCoord2f( 0.0, 0.0 );
    glVertex3f(radius, 0, 0);
    glTexCoord2f( 0.0, 1.0 );
    glVertex3f(radius, height, 0);
    glEnd();
    face.unbind();
    
    glPopMatrix();
}