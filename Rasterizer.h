#ifndef CSE167_Rasterizer_h
#define CSE167_Rasterizer_h
#include <iostream>
#include <list>
#include <string>
#include "Vector3.h"

#include "Window.h"
#include "Vector4.h"
#include "Globals.h"
#include "Matrix4.h"


class Rasterizer
{
protected:
    Matrix4 P; //projection Matrix
    Matrix4 D;

public:
    int objMODE = 0;
    int sign = 0;
    Vector3 p;
    float R,G,B;
    float alpha,beta,gamma;
    Rasterizer(void);
    virtual ~Rasterizer(void);
    virtual void clearBuffer(void);
    virtual void display(void);
    virtual Vector4 rasterizeVertex(Vector4&);
    virtual void rasterizeTriangle(Vector4,Vector4,Vector4);
    virtual void reshape(int,int);
    virtual void setProjectionMatrix(float,float,float,float);
    virtual void setViewport(float,float);
    virtual void drawPoint(int ,int, float , float, float);
    virtual bool findBarycentric(Vector3,Vector3,Vector3,Vector3&);

};

#endif