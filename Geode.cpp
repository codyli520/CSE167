#include <stdio.h>
#include "Geode.h"
#include <GLUT/glut.h>

Geode::Geode() {
    this->modelView.identity();
}
Geode::~Geode() {}

void Geode::setModelView(Matrix4 *C)
{
    
    glPushMatrix();
    glMultMatrixf(C->ptr());
    
}

void Geode::draw(Matrix4 C)
{
    glMatrixMode(GL_MODELVIEW);
    setModelView(&C);
    render(C);
    glPopMatrix();
}


void Geode::update()
{
    //
}
