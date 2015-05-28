#ifndef CSE167_Globals_h
#define CSE167_Globals_h

#include "Camera.h"
#include "Cube.h"
#include "Sphere.h"
#include "Light.h"
#include "DrawData.h"
#include "UpdateData.h"
#include "House.h"
#include "OBJObject.h"
#include "Rasterizer.h"
#include "Texture.h"
#include "Skybox.h"
#include "Cylinder.h"
#include "Limbs.h"

class House;
class Rasterizer;
class Cube;
class OBJObject;
class Texture;
class Skybox;
class Cylinder;
class Limbs;
class Sphere;

class Globals
{
    
public:
    
    static Camera camera;
    static Cube cube,head;
    static Sphere sphere;
    static Light light;
    static DrawData drawData;
    static UpdateData updateData;
    static House house;
    static OBJObject bear,bunny,dragon;
    static Rasterizer myRaster;
    static Texture txt;
    static Skybox sbox;
    static Cylinder ironman;
    static Limbs limb;
    //Feel free to add more member variables as needed
    
};

#endif
