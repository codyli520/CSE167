#ifndef CSE167_Sphere_h
#define CSE167_Sphere_h

#include "Drawable.h"
#include "Vector3.h"
#include "Matrix4.h"
#include "Geode.h"

class Sphere : public Geode
{
    
public:
    Sphere();
     ~Sphere();
    double radius;
    int slices, stacks;
   
    Sphere(double, int, int);
    
    void render(Matrix4);
   
    
    
};

#endif
