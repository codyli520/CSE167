//
//  Skybox.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15-5-6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//
#ifndef CSE167_Skybox_h
#define CSE167_Skybox_h

#include "Drawable.h"
#include "Rasterizer.h"
#include "Texture.h"

class Skybox : public Drawable
{
    
public:
    Vector3 n1,n2;
    float size;
    
    Texture front,back,top,base,left,right;
    Skybox(void);
    Skybox(float size);
    virtual ~Skybox(void);
    
    virtual void draw(DrawData&);
    //virtual void update(UpdateData&);
    
};

#endif