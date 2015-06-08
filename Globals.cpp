#include "Globals.h"
#include "Rasterizer.h"
#include "House.h"


Camera Globals::camera = Camera();

Cube Globals::cube = Cube();
Limbs Globals::limb = Limbs();
Sphere Globals::sphere = Sphere();
Light Globals::light = Light();
Light Globals::pLight = Light();
Light Globals::pLight2 = Light();
House Globals::house = House();

DrawData Globals::drawData = DrawData();
UpdateData Globals::updateData = UpdateData();

OBJObject Globals::bear("bear.obj");
OBJObject Globals::bunny("bunny.obj");
OBJObject Globals::dragon("dragon.obj");

/*Texture Globals::top("cityUp.ppm");
Texture Globals::bottom("cityDn.ppm");
Texture Globals::left("cityLt.ppm");
Texture Globals::right("cityRt.ppm");
Texture Globals::front("cityFt.ppm");
Texture Globals::back("cityBk.ppm");*/
Texture Globals::txt = Texture();
Skybox Globals::sbox = Skybox();
Cylinder Globals::ironman = Cylinder();
Rasterizer Globals::myRaster = Rasterizer();
Block Globals::block = Block();
float trees[50];

L_System Globals::l_system = *new L_System();
L_System Globals::l_system1 = *new L_System();
L_System Globals::l_system2 = *new L_System();

