#include "Sphere.h"

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"

Sphere::Sphere(){
    
}

Sphere::~Sphere(){
    
}
Sphere::Sphere(double radius, int slices, int stacks) : Geode()
{
    this->radius = radius;
    this->slices = slices;
    this->stacks = stacks;
}

void Sphere::render(Matrix4 C)
{

    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glColor3f(0.5,0.5, 0.5);
    glMultMatrixf(modelView.ptr());
    
    glutSolidSphere(radius, slices, stacks);
    
    glPopMatrix();
}


