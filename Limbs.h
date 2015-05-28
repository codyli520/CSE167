#ifndef CSE167_Limbs_h
#define CSE167_Limbs_h

#include "Drawable.h"
#include "Rasterizer.h"
#include "Geode.h"
#include  "Matrix4.h"


class Limbs : public Geode{
    
public:
    
    Vector3 n1,n2;
    float size;
    
    Limbs();
    Limbs(float);
    virtual ~Limbs(void);
    
    
    virtual void update(UpdateData&);
    
    void render(Matrix4);
    
};

#endif

