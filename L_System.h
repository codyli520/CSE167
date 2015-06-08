//
//  L_System.h
//  CSE167 Spring 2015 Starter Code
//
//  Created by Longfei Li on 15/6/2.
//  Copyright (c) 2015年 RexWest. All rights reserved.
//

#ifndef __CSE167_Spring_2015_Starter_Code__L_System__
#define __CSE167_Spring_2015_Starter_Code__L_System__

#include <GLUT/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <time.h>
#include "Matrix4.h"
using namespace std;

class L_System{
public:
    float PI = 3.14, DEPTH = 3;
    // Angle of branches, and depth of tree
    float ANGLE = 10, depth = 3;
    float length = 0.25;
    Matrix4 LMatrix;
    vector<string> *trees = new vector<string>();
    float lineWidth = 1;
    float incr = 1;
    // L-System
    string str = "X";
    L_System();
    void push();
    void pop();
    void rotL();
    void rotR();
    void drawLine();
    void draw();
    void draw2();//(X → F-[[X]+X]+F[+FX]-X), (F → FF)
    void expand(float num);
    void expand1(float num);
    void expand2(float num);
    
};

#endif /* defined(__CSE167_Spring_2015_Starter_Code__L_System__) */
