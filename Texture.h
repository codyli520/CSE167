#ifndef CSE167_Texture_h
#define CSE167_Texture_h
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Texture
{
    
protected:
    
    
       // storage for one texture
    static unsigned char* loadPPM(const char*, int&, int&);
    
public:
    
    const char* filename;
    unsigned int id;
    static Texture* emptyTexture;
    
    Texture(void);
    Texture(const char* filename);
    virtual ~Texture(void);
    
    void bind(void);
    void unbind(void);
    //virtual void idle();
    void reshape(int,int);
    //void display(float);
    //void Drawface(float);
    void initGL();
    //void loadTexture();
    
    
};

#endif
