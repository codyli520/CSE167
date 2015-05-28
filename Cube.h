#ifndef CSE167_Cube_h
#define CSE167_Cube_h

#include "Drawable.h"
#include "Rasterizer.h"
#include "Geode.h"
#include  "Matrix4.h"
#include "Texture.h"

class Cube : public Geode{
    
public:
    
    Vector3 n1,n2;
    float size;
    Texture front,back,base,top,left,right;
    
    Cube();
    Cube(float);
    virtual ~Cube(void);
    
    //virtual void draw(DrawData&);
    virtual void update(UpdateData&);
    //virtual void myDraw(DrawData&);
    //void spin(float);
    void render(Matrix4);
    
};

#endif

