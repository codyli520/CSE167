#ifndef CSE167_House_h
#define CSE167_House_h

#include "Drawable.h"
#include "Matrix4.h"
#include "Rasterizer.h"

class House: public Drawable{
    protected:
        bool visible;
        Matrix4 model2world;
    public:
    Vector3 a,b,c,n1,n2,n3;
        int nVerts;
        House();
        virtual ~House(void);
        virtual void draw(DrawData&);
        virtual void myDraw(DrawData& data);
};

#endif