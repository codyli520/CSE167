
#ifndef CSE167_Geode_h
#define CSE167_Geode_h

#include "Node.h"

class Geode: public Node
{
public:
    Matrix4 modelView;
    
    Geode();
    ~Geode();
    
    void setModelView(Matrix4*);
    virtual void draw(Matrix4 C);
    void update();
    virtual void render(Matrix4) = 0;
};

#endif
