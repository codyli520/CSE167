//
//  Skybox.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15-5-6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "Skybox.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include "Globals.h"
#include "Texture.h"

Skybox::Skybox()
{
    
}
Skybox::Skybox(float size) : Drawable()
{
    this->size = size;
  
    front  = Texture("front.ppm");
    back  = Texture("back.ppm");
    top  =  Texture("top.ppm");
    base  =  Texture("base.ppm");
    left  =  Texture("left.ppm");
    right  = Texture("right.ppm");
}

Skybox::~Skybox()
{
    //Delete any dynamically allocated memory/objects here
}


void Skybox::draw(DrawData& drawdata)
{
    
    
    /* clear the color buffer (resets everything to black) */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(toWorld.ptr());
    
    glPushMatrix();
    
    glColor4f(1,1,1,1);
    
    // front
    front.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0); glVertex3f(size, size, -size);
    glTexCoord2f(0, 0); glVertex3f(-size, size, -size);
    glTexCoord2f(0, 1); glVertex3f(-size, -size, -size);
    glTexCoord2f(1, 1); glVertex3f(size, -size, -size);
    glEnd();
    front.unbind();
    
    //base
    base.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 1); glVertex3f(size, -size, size);
    glTexCoord2f(0, 1); glVertex3f(-size, -size, size);
    glTexCoord2f(0, 0); glVertex3f(-size, -size, -size);
    glTexCoord2f(1, 0); glVertex3f(size, -size, -size);
    glEnd();
    base.unbind();
    
    //top
    top.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(1, 0); glVertex3f(size, size, size);
    glTexCoord2f(0, 0); glVertex3f(-size, size, size);
    glTexCoord2f(0, 1); glVertex3f(-size, size, -size);
    glTexCoord2f(1, 1); glVertex3f(size, size, -size);
    glEnd();
    top.unbind();
    
    //left
    left.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-size, size, size);
    glTexCoord2f(1, 0); glVertex3f(-size, size, -size);
    glTexCoord2f(1, 1); glVertex3f(-size, -size, -size);
    glTexCoord2f(0, 1); glVertex3f(-size, -size, size);
    glEnd();
    left.unbind();
    
    //right
    right.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(size, size, -size);
    glTexCoord2f(1, 0); glVertex3f(size, size, size);
    glTexCoord2f(1, 1); glVertex3f(size, -size, size);
    glTexCoord2f(0, 1); glVertex3f(size, -size, -size);
    glEnd();
    right.unbind();
    
    //back
    back.bind();
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(size, size, size);
    glTexCoord2f(1, 0); glVertex3f(-size, size, size);
    glTexCoord2f(1, 1); glVertex3f(-size, -size, size);
    glTexCoord2f(0, 1); glVertex3f(size, -size, size);
    glEnd();    
    back.unbind();
    
    glPopMatrix();
    /* swap the back and front buffers so we can see what we just drew */
    //glutSwapBuffers();
}
