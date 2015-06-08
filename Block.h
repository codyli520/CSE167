//
//  Block.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/2.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__Block__
#define __CSE167_Spring_2015_Starter_Code__Block__


#include "Drawable.h"
#include "Rasterizer.h"
#include "Geode.h"
#include  "Matrix4.h"
#include "Texture.h"

class Block : public Geode{
    
public:
    
    Vector3 n1,n2;
    float size;
    Texture front,back,base,top,left,right;
    
    Block();
    Block(float);
    virtual ~Block(void);
    
    //virtual void draw(DrawData&);
    virtual void update(UpdateData&);
    //virtual void myDraw(DrawData&);
    //void spin(float);
    void render(Matrix4);
    
};

#endif

