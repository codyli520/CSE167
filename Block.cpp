//
//  Block.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/2.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//
#include "Block.h"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include "Texture.h"
Block::Block() : Geode()
{
    
}


Block::~Block()
{
    //Delete any dynamically allocated memory/objects here
}

/*void Block::render(Matrix4 C) {
 
 glColor3f(1,1,0);
 glutSolidBlock(size);
 
 }*/


Block::Block(float size)
{
    this->size = size;
    
    
}



/*
void Block::render(Matrix4 C)
{
    
    
     clear the color buffer (resets everything to black)
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glMatrixMode(GL_MODELVIEW);
    glMultMatrixf(modelView.ptr());
    
    glPushMatrix();
    
    
    // front
    //front.bind();
    glBegin(GL_QUADS);
    //glColor3f(0.5, 0.5, 0.5);
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
    
    //back
    glColor3f(1, 1, 1);
    front.bind();
    glBegin(GL_QUADS);
    
    glTexCoord2f(0, 0); glVertex3f(size, size, size);
    glTexCoord2f(1, 0); glVertex3f(-size, size, size);
    glTexCoord2f(1, 1); glVertex3f(-size, -size, size);
    glTexCoord2f(0, 1); glVertex3f(size, -size, size);
    glEnd();
    front.unbind();
    
    glPopMatrix();
     //swap the back and front buffers so we can see what we just drew 
    //glutSwapBuffers();
}*/
void Block::render(Matrix4 C)
 {
 float halfSize = size;
 
 //Apply the material properties
 //From here forward anything drawn will be drawn with these material
     glEnable(GL_LIGHTING);
 
 //Se the OpenGL Matrix mode to ModelView (used when drawing geometry)
 glMatrixMode(GL_MODELVIEW);
 
 //Push a save state onto the matrix stack, and multiply in the toWorld matrix
 glPushMatrix();
 //glMultMatrixf(toWorld.ptr());
 
 //Make Block!
 //Note: The glBegin, and glEnd should always be as close to the glNormal/glVertex calls as possible
 //These are special calls that 'freeze' many internal states of OpenGL.
 //Once the glBegin state is active many of the calls made to OpenGL (like glMultMatrixf) will be IGNORED!
 //As a good habit, only call glBegin just before you need to draw, and call end just after you finish
 glBegin(GL_QUADS);
     glColor3f(0, 1, 0);
 // Draw front face:
 glNormal3f(0.0, 0.0, 1.0);
 glVertex3f(-halfSize,  halfSize,  halfSize); //f1
 glVertex3f( halfSize,  halfSize,  halfSize); //f2
 glVertex3f( halfSize, -halfSize,  halfSize); //f3
 glVertex3f(-halfSize, -halfSize,  halfSize); //f4
 
 // Draw left side:
 glNormal3f(-1.0, 0.0, 0.0);
 glVertex3f(-halfSize,  halfSize,  halfSize); //f1
 glVertex3f(-halfSize,  halfSize, -halfSize); //l1
 glVertex3f(-halfSize, -halfSize, -halfSize); //l2
 glVertex3f(-halfSize, -halfSize,  halfSize); //f4
 
 // Draw right side:
 glNormal3f(1.0, 0.0, 0.0);
 glVertex3f( halfSize,  halfSize,  halfSize); //f2
 glVertex3f( halfSize,  halfSize, -halfSize); //r1
 glVertex3f( halfSize, -halfSize, -halfSize); //r2
 glVertex3f( halfSize, -halfSize,  halfSize); //f3
 
 // Draw back face:
 glNormal3f(0.0, 0.0, -1.0);
 glVertex3f(-halfSize,  halfSize, -halfSize); //l1
 glVertex3f( halfSize,  halfSize, -halfSize); //r1
 glVertex3f( halfSize, -halfSize, -halfSize); //r2
 glVertex3f(-halfSize, -halfSize, -halfSize); //l2
 
 // Draw top side:
 glNormal3f(0.0, 1.0, 0.0);
 glVertex3f(-halfSize,  halfSize,  halfSize); //f1
 glVertex3f( halfSize,  halfSize,  halfSize); //f2
 glVertex3f( halfSize,  halfSize, -halfSize); //r1
 glVertex3f(-halfSize,  halfSize, -halfSize); //l1
 
 // Draw bottom side:
 glNormal3f(0.0, -1.0, 0.0);
 glVertex3f(-halfSize, -halfSize, -halfSize); //l2
 glVertex3f( halfSize, -halfSize, -halfSize); //r2
 glVertex3f( halfSize, -halfSize,  halfSize); //f3
 glVertex3f(-halfSize, -halfSize,  halfSize); //f4
 
 glEnd();
 
 //The above glBegin, glEnd, glNormal and glVertex calls can be replaced with a glut convenience function
 //glutSolidBlock(size);
 
 //Pop the save state off the matrix stack
 //This will undo the multiply we did earlier
 glPopMatrix();
 }
 
 /*
 void Block::myDraw(DrawData& data)
 {
 
 Globals::myRaster.clearBuffer();
 float halfSize = size/2.0;
 Vector4 f1(-halfSize,  halfSize,  halfSize);
 Vector4 f2( halfSize,  halfSize,  halfSize);
 Vector4 f3( halfSize, -halfSize,  halfSize);
 Vector4 f4(-halfSize, -halfSize,  halfSize);
 Vector4 l1(-halfSize,  halfSize, -halfSize);
 Vector4 l2(-halfSize, -halfSize, -halfSize);
 Vector4 r1( halfSize,  halfSize, -halfSize);
 Vector4 r2( halfSize, -halfSize, -halfSize);
 
 f1 = toWorld*f1;
 f2 = toWorld*f2;
 f3 = toWorld*f3;
 f4 = toWorld*f4;
 l1 = toWorld*l1;
 l2 = toWorld*l2;
 r1 = toWorld*r1;
 r2 = toWorld*r2;
 
 
 if(Globals::myRaster.sign == 0){
 Globals::myRaster.rasterizeVertex(f1);
 Globals::myRaster.rasterizeVertex(f2);
 Globals::myRaster.rasterizeVertex(f3);
 Globals::myRaster.rasterizeVertex(f4);
 Globals::myRaster.rasterizeVertex(l1);
 Globals::myRaster.rasterizeVertex(l2);
 Globals::myRaster.rasterizeVertex(r1);
 Globals::myRaster.rasterizeVertex(r2);
 }
 else{
 
 n1.set(0,0,1);
 
 Globals::myRaster.rasterizeTriangle(f1, f2 ,f3);
 Globals::myRaster.rasterizeTriangle(f3 ,f4, f1);
 
 n1.set(-1,0,0);
 
 Globals::myRaster.rasterizeTriangle(f1, l1 ,l2);
 Globals::myRaster.rasterizeTriangle(l2 ,f4, f1);
 
 n1.set(1,0,0);
 
 Globals::myRaster.rasterizeTriangle(f2, r1 ,r2);
 Globals::myRaster.rasterizeTriangle(r2 ,f3, f2);
 
 n1.set(0,0,-1);
 
 Globals::myRaster.rasterizeTriangle(l1, r1 ,r2);
 Globals::myRaster.rasterizeTriangle(r2 ,l2, l1);
 
 n1.set(0,1,0);
 
 Globals::myRaster.rasterizeTriangle(f1, f2 ,r1);
 Globals::myRaster.rasterizeTriangle(r1 ,l1 ,f1);
 
 n1.set(0,-1,0);
 
 Globals::myRaster.rasterizeTriangle(l2, r2 ,f3);
 Globals::myRaster.rasterizeTriangle(f3 ,f4 ,l2);
 }
 Globals::myRaster.display();
 }*/

void Block::update(UpdateData& data)
{
    //
}

/*void Block::spin(float radians)
 {
 Matrix4 rotation;
 rotation.makeRotateY(radians);
 
 toWorld = toWorld * rotation;
 }
 */


