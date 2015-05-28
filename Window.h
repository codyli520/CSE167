#ifndef CSE167_Window_h
#define CSE167_Window_h
#include "Drawable.h"
#include "Rasterizer.h"
#include "Globals.h"
#include "Skybox.h"
#include "Geode.h"
#include "Robot.h"

class Window	  // OpenGL output window related routines
{
    
public:
    
    static Drawable* shapes;
    
    static int width, height; 	            // window size
    
    static void initialize(void);
    static void idleCallback(void);
    static void reshapeCallback(int, int);
    static void displayCallback(void);
    static void processNormalKeys(unsigned char key, int x, int y);
    static void processSpecialKeys(int key, int x, int y);
    static void mouseCallback(int button, int state,int x, int y);
    static void mouseMotionCallback(int x, int y);
    static Vector3 trackBallMapping(int x, int y);
};

#endif

