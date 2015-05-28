#include <iostream>

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "Cube.h"
#include "Matrix4.h"
#include "Globals.h"
#include "House.h"
#include "Rasterizer.h"
#include "Skybox.h"
int modeFlag = 0;
int Window::width  = 512;   //Set window width in pixels here
int Window::height = 512;   //Set window height in pixels here
float SpinAngle = 0.005;

Drawable* Window::shapes = &Globals::sbox;
Robot android = Robot();

Matrix4 myMatrix;
Vector3 d,e,up;
bool rasterization = false;
bool forward = false;
bool sky=false;

float camX,camY,camZ;

//Texture txt;

void Window::initialize(void)
{
    //Setup the light
    Vector4 lightPos(0.0, 10.0, 15.0, 1.0);
    Globals::light.position = lightPos;
    Globals::light.quadraticAttenuation = 0.02;
    
    //Initialize cube matrix:
    //Globals::cube.toWorld.identity();
    
    //Setup the cube's material properties
    Color color(0x23ff27ff);
    //Globals::cube.material.color = color;
    
    
    Color ballColor(0x00f5ffff);
    //Globals::sphere.material.color = ballColor;
    
    /*Color objColor(0xedeff1ff);
    Globals::bear.material.color = objColor;
    Globals::dragon.material.color = objColor;*/
    
    //txt = Texture();
    Globals::txt.initGL();
    Globals::sbox = Skybox(100);
    Globals::ironman = Cylinder(2, 1);
    Globals::cube = Cube(1);
    Globals::limb = Limbs(1);
    Globals::sbox.toWorld.identity();
    Globals::ironman.modelView.identity();
    Globals::sphere = Sphere(0.65, 20, 20);
    
    //Globals::ironman.modelView.identity();
    Globals::limb.modelView.identity();
    Globals::cube.modelView.identity();
    Globals::sphere.modelView.identity();
}

//----------------------------------------------------------------------------
// Callback method called when system is idle.
// This is called at the start of every new "frame" (qualitatively)
void Window::idleCallback()
{
    //Set up a static time delta for update calls
    Globals::updateData.dt = 1.0/60.0;// 60 fps
    
    
    if(!forward){
        android.i -=0.05;
        if(android.i <-0.75){
            forward = true;
        }
    }
    else{
        android.i+=0.05;
        if(android.i > 0.75){
            forward = false;
        }
    }
    
    
    
    //Rotate cube; if it spins too fast try smaller values and vice versa
    switch (modeFlag) {
        case 0:
            //Globals::cube.spin(SpinAngle);
            //Call the update function on cube
            Globals::cube.update(Globals::updateData);
            break;
        case 1:
            //Globals::sphere.move();
            break;
        case 4:
            Globals::bear.spin(SpinAngle*10);
            //Globals::bear.update(Globals::updateData);
            break;
        case 5:
            Globals::bunny.spin(SpinAngle*10);
            //Globals::bunny.update(Globals::updateData);
            break;
        case 6:
            Globals::dragon.spin(SpinAngle*10);
            //Globals::dragon.update(Globals::updateData);
            break;
            
        default:
            break;
    }
    

    //Call the display routine to draw the cube
    displayCallback();
    
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when graphics window is resized by the user
void Window::reshapeCallback(int w, int h)
{
    width = w;                                                       //Set the window width
    height = h;                                                      //Set the window height
    glViewport(0, 0, w, h);                                          //Set new viewport size
    glMatrixMode(GL_PROJECTION);                                     //Set the OpenGL matrix mode to Projection
    glLoadIdentity();                                                //Clear the projection matrix by loading the identity
    gluPerspective(60.0, double(width)/(double)height, 1.0, 1000.0); //Set perspective projection viewing frustum
    Globals::myRaster.reshape(w,h);
    
    
}

//----------------------------------------------------------------------------
// Callback method called by GLUT when window readraw is necessary or when glutPostRedisplay() was called.
void Window::displayCallback()
{
    
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //Clear color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //Set the OpenGL matrix mode to ModelView
    glMatrixMode(GL_MODELVIEW);
    
    //Push a matrix save point
    //This will save a copy of the current matrix so that we can
    //make changes to it and 'pop' those changes off later.
    glPushMatrix();
    
    //Replace the current top of the matrix stack with the inverse camera matrix
    //This will convert all world coordiantes into camera coordiantes
    glLoadMatrixf(Globals::camera.getInverseMatrix().ptr());
    
    
    
    //Bind the light to slot 0.  We do this after the camera matrix is loaded so that
    //the light position will be treated as world coordiantes
    //(if we didn't the light would move with the camera, why is that?)
    
    Globals::light.bind(0);
    
    //glDisable(GL_TEXTURE_2D);
    //glDisable(GL_LIGHTING);
    //Draw the cube or sphere
    switch (modeFlag) {
        case 7:
            glEnable(GL_LIGHTING);
            
            if (rasterization == false) {
                //Globals::cube.draw(Globals::drawData);
            }
            else{
                Globals::myRaster.objMODE = 5;
                //Globals::cube.myDraw(Globals::drawData);
            }
            break;
            
        case 1:
            glEnable(GL_LIGHTING);
            //Globals::sphere.draw(Globals::drawData);
            break;
        case 2: case 3:
            glDisable(GL_LIGHTING);
            
            if (rasterization == false) {
                Globals::house.draw(Globals::drawData);
            }
            else{
                Globals::house.myDraw(Globals::drawData);
            }
                
            break;
        case 4:
            glEnable(GL_LIGHTING);
            if (rasterization == false) {
                shapes->draw(Globals::drawData);
            }
            else
            {
                shapes->myDraw(Globals::drawData);
            }
            break;
        case 5:
            glEnable(GL_LIGHTING);
            if (rasterization == false) {
                Globals::bunny.draw(Globals::drawData);
            }
            else
            {
                Globals::bunny.myDraw(Globals::drawData);
            }
            break;
        case 6:
            glEnable(GL_LIGHTING);
            if (rasterization == false) {
                Globals::dragon.draw(Globals::drawData);
            }
            else
            {
                Globals::dragon.myDraw(Globals::drawData);
            }
            break;
            
        case 0:
            
            glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
            glDisable(GL_LIGHTING);
            Globals::sbox.draw(Globals::drawData);
            
            for(int i = 20;i>-30;i-=5){
                for(int j =0; j>-50;j-=5){
                    android.draw(i,j);
                }
            }
            
            break;
            
            
    }
    
    //Pop off the changes we made to the matrix stack this frame
    glPopMatrix();
    
    //Tell OpenGL to clear any outstanding commands in its command buffer
    //This will make sure that all of our commands are fully executed before
    //we swap buffers and show the user the freshly drawn frame
    glFlush();
    
    //Swap the off-screen buffer (the one we just drew to) with the on-screen buffer
    glutSwapBuffers();
}

void Window::processNormalKeys(unsigned char key, int x, int y) {
//Keyboard callbacks!
    
    switch (key)
    {
        case 't':
            SpinAngle = -SpinAngle;
            break;
            
        case 'x':
            myMatrix.makeTranslate(-1, 0, 0);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
            
        case 'X':
            myMatrix.makeTranslate(1, 0, 0);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
        case 'y':
            myMatrix.makeTranslate(0,-1, 0);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
            
        case 'Y':
            myMatrix.makeTranslate(0,1, 0);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
        case 'z':
            myMatrix.makeTranslate(0,0,-1);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
            
        case 'Z':
            myMatrix.makeTranslate(0,0,1);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
        
        case 'r':
            shapes->toWorld.identity();
            android.robotMatrix.identity();
            SpinAngle = 0.005;
            break;
            
        case 'o':
            myMatrix.makeRotateZ(SpinAngle*10);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
            
        case 'O':
            myMatrix.makeRotateZ(-SpinAngle*10);
            if(sky)
                shapes->toWorld= myMatrix*shapes->toWorld;
            else
                android.robotMatrix = myMatrix*android.robotMatrix;
            break;
            
        case 's':
            myMatrix.makeScale(0.9);
            if(sky)
                shapes->toWorld= shapes->toWorld*myMatrix;
            else
                android.robotMatrix = android.robotMatrix*myMatrix;
            break;
            
        case 'S':
            myMatrix.makeScale(1.1);
            if(sky)
                shapes->toWorld= shapes->toWorld*myMatrix;
            else
                android.robotMatrix = android.robotMatrix*myMatrix;
            break;
            
        case 'b':
            if(modeFlag==1){
                modeFlag = 0;
                break;
            }
            else{
                modeFlag = 1;
                break;
            }
        case 'a':
            modeFlag = 5;
            break;
            
        case 'e':
            rasterization = !rasterization;//rasterize mode
            break;
            
        case '+':
            
            if(Globals::myRaster.sign <4 && rasterization)
                Globals::myRaster.sign++;
             
            
            break;
            
        case '-':
            if(Globals::myRaster.sign > 0 && rasterization)
                Globals::myRaster.sign--;
            break;
            
        case 'p':
           
            sky = !sky;
            break;
    }
    /*Vector3 pos = Vector3(Globals::cube.toWorld.m[3][0],
                          Globals::cube.toWorld.m[3][1],
                          Globals::cube.toWorld.m[3][2]);*/
    
    //pos.print("The Cube is at:");
}

void Window::processSpecialKeys(int key, int x, int y) {
//Function Key callbacks!
    switch (key)
    {
        case GLUT_KEY_F1://cube
            modeFlag = 0;
            Globals::camera.reset();
            Globals::myRaster.objMODE = 5;
            //shapes = &Globals::cube;
            break;
        
        case GLUT_KEY_F2://house view 1
            modeFlag = 2;
            Globals::myRaster.objMODE = 3;
            d.set(0.0,24.14,24.14);
            e.set(0.0,0.0,0.0);
            up.set(0.0,1.0,0.0);
            Globals::camera.set(d, e, up);
            break;
        case GLUT_KEY_F3://house view 2
            modeFlag = 3;
            Globals::myRaster.objMODE = 4;
            d.set(-28.33, 11.66, 23.33);
            e.set(-5.0,0.0,0.0);
            up.set(0.0,1.0,0.5);
            Globals::camera.set(d, e, up);
            break;
        case GLUT_KEY_F4://bear
            modeFlag = 4;
            Globals::myRaster.objMODE = 0;
            shapes = &Globals::bear;
            Globals::camera.reset();
            break;
        case GLUT_KEY_F5://bunny
            modeFlag = 5;
            Globals::myRaster.objMODE = 1;
            shapes = &Globals::bunny;
            Globals::camera.reset();
            break;
        case GLUT_KEY_F6://dragon
            modeFlag = 6;
            Globals::myRaster.objMODE = 2;
            shapes = &Globals::dragon;
            Globals::camera.reset();
            break;
        case GLUT_KEY_F7://skybox
            modeFlag = 7;
            camX = 0.0;
            camY = 0.0;
            camZ = 20.0;
            d.set(camX,camY,camZ);
            e.set(0.0,0.0,0.0);
            up.set(0.0,1.0,0.0);
            Globals::camera.set(d, e, up);
            shapes = &Globals::sbox;
            break;
            
        case GLUT_KEY_UP:
            if(Globals::myRaster.sign < 3 && rasterization)
                Globals::myRaster.sign++;
            
            break;
            
        case GLUT_KEY_DOWN:
            if(Globals::myRaster.sign > 0 && rasterization)
                Globals::myRaster.sign--;
            
            break;
        
        

    }
}

bool leftMouse,clicked;
Vector3 vPoint,wPoint,axisA;
float mouseAngle;

void Window::mouseCallback(int button, int state, int x, int y){//TODO: Mouse callbacks!
    
    switch(button){
        case GLUT_LEFT_BUTTON:
            if(state == GLUT_DOWN){
                leftMouse = true;
                clicked = true;
                vPoint = trackBallMapping(x, y);
                break;
            }
        case GLUT_RIGHT_BUTTON:
            if(state == GLUT_DOWN){
                leftMouse = false;
                clicked = true;
                vPoint = trackBallMapping(x, y);
                break;
                
            }
            
    }
}



void Window::mouseMotionCallback(int x, int y){//TODO: Mouse Motion callbacks!
    wPoint = trackBallMapping(x, y);
    Vector3 distance = (wPoint - vPoint);
    
    if(leftMouse){
        
        axisA = vPoint.cross(wPoint);
        mouseAngle = asinf(axisA.magnitude()/(wPoint.magnitude()*vPoint.magnitude()));
        
        myMatrix.makeRotateArbitrary(axisA, mouseAngle);
        if(sky)
            shapes->toWorld= myMatrix*shapes->toWorld;
        else{
            android.robotMatrix=myMatrix*android.robotMatrix;
        }
        
    }
    vPoint = wPoint;
}

Vector3 Window::trackBallMapping(int x, int y){
    Vector3 v;
    float d = 0.0;
    v[0] = (2.0*x - width) / width;
    v[1] = (height - 2.0*y) / height;
    v[2] = 0.0;
    d = v.magnitude();
    d = (d<1.0) ? d : 1.0;
    v[2] = sqrtf(1.001 - d*d);
    v = v.normalize();
    return v;
}


//TODO: Mouse callbacks!

//TODO: Mouse Motion callbacks!
