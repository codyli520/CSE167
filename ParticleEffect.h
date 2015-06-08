//
//  ParticleEffect.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__ParticleEffect__
#define __CSE167_Spring_2015_Starter_Code__ParticleEffect__

#include <stdio.h>
#include "MatrixTransform.h"
#include "Group.h"
#include "Vector3.h"
#include <vector>
#include <cstdlib>
#include <ctime>

class Matrix4;
class Particle{
public:
    Particle() {}
    
    int delay;
    Vector3 dir;
    Vector3 pos;
    Vector3 color;
    int duration;
};

class ParticleEffect : public Group{
public:
    ParticleEffect(Vector3);
    
    
    
    Vector3 newPosition();
    virtual void draw(Matrix4& matrix);
    virtual void update(Matrix4 matrix);
    virtual void drawBoundingSpheres(Matrix4 worldMatrix);
    
    
    bool alive;
    double duration;
    std::vector<Particle*> *particles;
    int count;
    double speed;
};


#endif