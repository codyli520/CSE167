#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>
#include <iomanip>
#include <cstring>
#include "Matrix4.h"
#include "Window.h"
#include "Globals.h"
#include "Rasterizer.h"


static int window_width = 512, window_height = 512;
static float* pixels = new float[window_width * window_height * 3];

static float* zBuffer = new float[window_width * window_height];

static float z;

using namespace std;


Rasterizer::Rasterizer()
{
    D.set(window_width/2.0,0,0,0,
          0,window_height/2.0,0,0,
          0,0,1.0/2.0,0,
          window_width/2.0,window_height/2.0,1.0/2.0,1);
}

Rasterizer::~Rasterizer()
{
    
}

/*struct Color    // generic color
{
    float r,g,b;
};*/

void Rasterizer::setProjectionMatrix(float fov, float aspect, float n, float f)
{
    float FOV = (fov/180.0)*M_PI;
    
    P.set(
     1/(aspect*(tan(FOV/2.0))),0.0,0.0,0.0,
     0.0,1/(tan(FOV/2.0)),0.0,0.0,
     0.0,0.0,(n + f)/(n - f),-1.0,
     0.0,0.0, (2.0 * n * f)/(n - f),0.0);
}

void Rasterizer::setViewport(float x,float y)
{
    D.set(
    x/2.0,0.0,0.0,0.0,
    0.0,y/2.0,0.0,0.0,
    0.0,0.0,1.0/2.0,0.0,
    x/2.0,y/2.0,1.0/2.0,1.0);
}

void loadData()
{
    // put code to load data model here
}

// Clear frame buffer
void Rasterizer::clearBuffer()
{
    Color clearColor = {0.0, 0.0, 0.0};   // clear color: black
    for (int i=0; i<window_width*window_height; ++i)
    {
        pixels[i*3]   = clearColor[0];
        pixels[i*3+1] = clearColor[1];
        pixels[i*3+2] = clearColor[2];
        zBuffer[i] = 1;
    }
}

// Draw a point into the frame buffer
void Rasterizer::drawPoint(int x, int y, float r, float g, float b)
{
    
    int offset = y*window_width*3 + x*3;
    if(z<zBuffer[x+y*window_width]){
    //if statement
        pixels[offset]   = r;
        pixels[offset+1] = g;
        pixels[offset+2] = b;
        if (sign > 1){
        zBuffer[x+y*window_width] = z;
        }
    }
}

//part1
Vector4 Rasterizer::rasterizeVertex(Vector4& V)
{
    //Vector4 p;
    V = Globals::camera.getInverseMatrix()*V;//to Camera
    V = P*V; //to canonical
    V = V.dehomogenize();
    V = D*V; //to window
   
    if ((int)V[0] <= window_width && (int)V[1] <= window_height&&(int)V[0]>=0&&(int)V[1]>=0)
        
    drawPoint((int)V[0],(int)V[1], 1.0 , 1.0 , 1.0); //white dots

    return V;
    
}

void Rasterizer::rasterizeTriangle(Vector4 a,Vector4 b,Vector4 c)
{
    a = Globals::camera.getInverseMatrix()*a;//to Camera
    a = P*a; //to canonical
    a = a.dehomogenize();
    a = D*a;
    
    b = Globals::camera.getInverseMatrix()*b;//to Camera
    b = P*b; //to canonical
    b = b.dehomogenize();
    b = D*b;
    
    c = Globals::camera.getInverseMatrix()*c;//to Camera
    c = P*c; //to canonical
    c = c.dehomogenize();
    c = D*c;
    
    Vector3 x = a.toVector3();
    Vector3 y = b.toVector3();
    Vector3 z = c.toVector3();
    
    int minX = min(min(x[0],y[0]),z[0]);
    int minY = min(min(x[1],y[1]),z[1]);
    int maxX = max(max(x[0],y[0]),z[0]);
    int maxY = max(max(x[1],y[1]),z[1]);
    
    minX = max(minX, 0);
    minY = max(minY, 0);
    maxX = min(maxX, window_width-1);
    maxY = min(maxY, window_height-1);
    
    if(sign <3){
        R = (float) (rand()) / (float) (RAND_MAX);
        G = (float) (rand()) / (float) (RAND_MAX);
        B = (float) (rand()) / (float) (RAND_MAX);

        for (int i = minX; i <= maxX; i++){
            for (int j = minY; j <= maxY; j++){
                Vector3 p(i,j,0);
            
                if(findBarycentric(x, y, z,p)){
                    drawPoint(i,j,R,G,B);
                }
            }
        }
    }
        
    else
    {
        for (int i = minX; i <= maxX; i++){
            for (int j = minY; j <= maxY; j++){
                p.set(i,j,0);
                
                if(findBarycentric(x, y, z,p)){
                    if(objMODE == 1){
                    Vector3 color(Globals::bunny.vvnorm1*alpha+Globals::bunny.vvnorm2*beta+Globals::bunny.vvnorm3*gamma);
                    color = color.add(Vector3(1,1,1));
                    color = color.multiply(0.5);
                    R = color[0];
                    G = color[1];
                    B = color[2];
                    drawPoint(i,j,R,G,B);
                    }
                    else if(objMODE == 0){
                    Vector3 color(Globals::bear.vvnorm1*alpha+Globals::bear.vvnorm2*beta+Globals::bear.vvnorm3*gamma);
                    color = color.add(Vector3(1,1,1));
                    color = color.multiply(0.5);
                    R = color[0];
                    G = color[1];
                    B = color[2];
                    drawPoint(i,j,R,G,B);
                    }
                    else if(objMODE == 2){
                    Vector3 color(Globals::dragon.vvnorm1*alpha+Globals::dragon.vvnorm2*beta+Globals::dragon.vvnorm3*gamma);
                    color = color.add(Vector3(1,1,1));
                    color = color.multiply(0.5);
                    R = color[0];
                    G = color[1];
                    B = color[2];
                    drawPoint(i,j,R,G,B);
                    }
                    else if(objMODE == 3){
                        /*Vector3 color(Globals::house.n1.multiply(alpha)+Globals::house.n2.multiply(beta)+Globals::house.n3.multiply(gamma));
                        color = color.add(Vector3(1,1,1));
                        color = color.multiply(0.5);
                        R = color[0];
                        G = color[1];
                        B = color[2];*/
                        drawPoint(i,j,R,G,B);
                    }
                    else if(objMODE == 4){
                        /*Vector3 color(Globals::house.n1.multiply(alpha)+Globals::house.n2.multiply(beta)+Globals::house.n3.multiply(gamma));
                        color = color.add(Vector3(1,1,1));
                        color = color.multiply(0.5);
                        R = color[0];
                        G = color[1];
                        B = color[2];*/
                        drawPoint(i,j,R,G,B);
                    }
                    else if(objMODE ==5){
                        Vector3 color(Globals::cube.n1.multiply(alpha)+Globals::cube.n1.multiply(beta)+Globals::cube.n1.multiply(gamma));
                        color = color.add(Vector3(1,1,1));
                        color = color.multiply(0.5);
                        R = color[0];
                        G = color[1];
                        B = color[2];

                        drawPoint(i,j,R,G,B);
                    }
                    
                }
            }

        }
    }
    // Add code to rasterize a triangle
}

bool Rasterizer::findBarycentric(Vector3 a,Vector3 b, Vector3 c,Vector3& p)
{

    Vector3 v0 = b - a;
    Vector3 v1 = c - a;
    Vector3 v2 = c - b;
    Vector3 v3 = p - b;
    Vector3 v4 = a - c;
    Vector3 v5 = p - c;
    Vector3 v6 = p - a;
    
    Vector3 n = v0.cross(v1);
    Vector3 na = v2.cross(v3);
    Vector3 nb = v4.cross(v5);
    Vector3 nc = v0.cross(v6);
    
    float nMeg = n.magnitude()*n.magnitude();
    float nna = n.dot(na);
    float nnb = n.dot(nb);
    //float nnc = n.dot(nc);
    
    alpha = nna/nMeg;
    beta = nnb/nMeg;
    gamma = 1 - alpha - beta;
    
    z = alpha*a[2]+beta*b[2]+gamma*c[2];
    
    if (alpha >= 0 && alpha <= 1 && beta >= 0 && beta <= 1 && gamma >= 0 && gamma <= 1){
        
        return true;
    }
    else
        return false;
}


// Called whenever the window size changes
void Rasterizer::reshape(int new_width, int new_height)
{
    window_width  = new_width;
    window_height = new_height;
    delete[] pixels;
    pixels = new float[window_width * window_height * 3];
    zBuffer = new float[window_width * window_height];
    
    setViewport(new_width, new_height);
    setProjectionMatrix(60.0, (float)new_width/(float)new_height, 1.0, 1000.0);
}

void keyboard(unsigned char key, int, int)
{
    cerr << "Key pressed: " << key << endl;
}

void Rasterizer::display()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    // glDrawPixels writes a block of pixels to the framebuffer
    glDrawPixels(window_width, window_height, GL_RGB, GL_FLOAT, pixels);
    //clearBuffer();
}

