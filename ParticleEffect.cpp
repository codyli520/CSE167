//
//  ParticleEffect.cpp
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/6.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#include "ParticleEffect.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include "Sphere2.h"


ParticleEffect::ParticleEffect(Vector3 pos){
    srand((unsigned int) time(0));
    speed = 0.00055;
    count = 600;
    particles = new std::vector<Particle*>();
    for (int i = 0; i < count; i++){
        Particle *current = new Particle;
        current->delay = rand() % 4;
        double x = double(2 * (rand() % 2) - 1)*(double)(rand() % 1000) * speed / 10.0;
        double y = double(2 * (rand() % 2) - 1)*(double)(rand() % 1000) * speed / 10.0;
        double z = double(2 * (rand() % 2) - 1)*(double)(rand() % 1000) * speed / 10.0;
        current->dir = Vector3(x, y, z);
        current->pos = pos;
        
        current->color = Vector3((double)(rand() % 100) / 100.0, (double)(rand() % 100) / 100.0, (double)(rand() % 100) / 100.0);
        current->duration = 120 + rand() % 300;
        particles->push_back(current);
    }
}

void ParticleEffect::draw(Matrix4& matri){
    double s = 0.10;
    Matrix4 scale;
    scale.makeScale(s, s, s);
    Matrix4 temp;
    temp.identity();
    
    std::vector<Particle*>::iterator it;
    int active = 0;
    for (it = particles->begin(); it != particles->end(); it++){
        Particle *current = *it;
        if (current->delay <= 0){
            if (current->duration > 0){
                //cout << "Particle effect!!!" << endl;
                current->duration = current->duration - 1;
                current->pos = current->pos + current->dir;
                
                Sphere2 *sphere = new Sphere2();
                sphere->r = current->color[0];
                sphere->g = current->color[1];
                sphere->b = current->color[2];
                Matrix4 translate;
                translate = translate.makeTranslate(current->pos[0], current->pos[1], current->pos[2]);
                //current->pos.print("pos");
                //current->dir.print("dir");
                temp = matri*translate;
                temp = temp*scale;
                
                sphere->draw(temp);
                
                //sphere->render();
                active++;
                delete sphere;
            }
        }
        else{
            current->delay--;
        }
    }
    //printf("active = %d\n", active);
    if (active == 0) {
        particles->clear();
        alive = false;
    }
}

void ParticleEffect::update(Matrix4 matrix){
    
}

void ParticleEffect::drawBoundingSpheres(Matrix4 worldMatrix){
    
}