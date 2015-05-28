#ifndef CSE167_OBJObject_h
#define CSE167_OBJObject_h

#include <iostream>
#include <vector>
#include <string>
#include "Vector3.h"
#include "Drawable.h"
#include "Rasterizer.h"
struct Face
{
    int vs[3];
    int ns[3];
    int ts[3];

};

class OBJObject : public Drawable
{
    
protected:
    Face face;
    bool withColor;
    //Storage vectors
    std::vector<Vector3*>* vertices;
    std::vector<Vector3*>* colors;
    std::vector<Vector3*>* normals;
    std::vector<Vector3*>* texcoords;
    std::vector<Face>* faces;
    
    //Helper functions
    std::vector<std::string>& split(const std::string&, char, std::vector<std::string>&);
    std::vector<std::string> split(const std::string&, char);
    
    //Parse
    void parse(std::string&);
    
public:
    Vector3 vvnorm1,vvnorm2,vvnorm3;
    OBJObject(std::string);
    virtual ~OBJObject(void);
    
    void spin(float);
    virtual void draw(DrawData&);
    virtual void myDraw(DrawData&);
    virtual void update(UpdateData&);
    
};

#endif
