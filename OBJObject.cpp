#include "OBJObject.h"

#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

#include "Window.h"
#include "math.h"
#include <sstream>
#include <fstream>

#define deleteVector(__vect__) do {\
                                   iter = __vect__->begin();\
                                   end = __vect__->end();\
                                   while(iter != end) delete (*(iter++));\
                                   delete __vect__;\
                               } while(false)


OBJObject::OBJObject(std::string filename) : Drawable()
{
    this->vertices = new std::vector<Vector3*>();
    this->normals = new std::vector<Vector3*>();
    this->texcoords = new std::vector<Vector3*>();
    this->colors = new std::vector<Vector3*>();
    this->faces = new std::vector<Face>();
    
    //parse(filename);
}

OBJObject::~OBJObject()
{
    //Delete any dynamically allocated memory/objects here
    std::vector<Vector3*>::iterator iter;
    std::vector<Vector3*>::iterator end;
    
    deleteVector(vertices);
    deleteVector(normals);
    deleteVector(texcoords);
    
    delete faces;
}

void OBJObject::draw(DrawData& data)
{
    material.apply();
    
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
    glMultMatrixf(toWorld.ptr());
    
    
    glBegin(GL_TRIANGLES);
    
    for(int i = 0; i<faces->size();i++){
        face = faces->at(i);
        for(int k = 0; k<3; k++){
            Vector3 vnorm = *normals->at(face.ns[k]-1);
            vnorm = vnorm.normalize();
            glNormal3f(vnorm[0],vnorm[1],vnorm[2]);
            
            
            //glColor4f(vnorm[0],vnorm[1],vnorm[2],0.5); //rainbow
            glColor4f(1,1,1,0.5); //white
            
            if(withColor){
                Vector3 cvert = *colors->at(face.vs[k]-1);
                glColor4f(cvert[0],cvert[1],cvert[2],0.5);
            }
        
            
            Vector3 vvert = *vertices->at(face.vs[k]-1);
            glVertex3f(vvert[0],vvert[1],vvert[2]);
        }
    }
    
    glEnd();
    
    glPopMatrix();
}

void OBJObject::myDraw(DrawData &)
{
    Globals::myRaster.clearBuffer();
    Vector4 v1,v2,v3;
    Vector3 vert;
    
    //float r,g,b;
    for (int i = 0; i < faces->size(); i++)
    {
        Face f = faces->at(i);
        
            vvnorm1 = *normals->at(f.ns[0]-1);
            vvnorm1 = vvnorm1.normalize();
            vvnorm2 = *normals->at(f.ns[1]-1);
            vvnorm2 = vvnorm2.normalize();
            vvnorm3 = *normals->at(f.ns[2]-1);
            vvnorm3 = vvnorm3.normalize();
        
            vert=*(vertices->at(f.vs[0] - 1));
            
            v1.set(vert[0],vert[1],vert[2],1.0);
            v1 = toWorld*v1;
        
            vert=*(vertices->at(f.vs[1] - 1));
        
            v2.set(vert[0],vert[1],vert[2],1.0);
            v2 = toWorld*v2;
        
            vert=*(vertices->at(f.vs[2] - 1));
        
            v3.set(vert[0],vert[1],vert[2],1.0);
            v3 = toWorld*v3;
        
        if(Globals::myRaster.sign == 0){
                Globals::myRaster.rasterizeVertex(v1);
                Globals::myRaster.rasterizeVertex(v2);
                Globals::myRaster.rasterizeVertex(v3);
            }
        else{
                   
            Globals::myRaster.rasterizeTriangle(v1, v2, v3);
        }
    }
    Globals::myRaster.display();
}


void OBJObject::update(UpdateData& data)
{

}

void OBJObject::spin(float radians)
{
    Matrix4 rotation;
    rotation.makeRotateY(radians);
    
    toWorld = toWorld * rotation;
}

void OBJObject::parse(std::string& filename)
{
    std::ifstream infile(filename);
    std::string line;
    std::vector<std::string> tokens,fToken1,fToken2,fToken3;
    std::string token;
    
    //int lineNum = 0;
    
    
    std::cout << "Starting parse..." << std::endl;
    std::cout << filename << std::endl;
    
    //While all your lines are belong to us
    while (std::getline(infile, line))
    {
        //Progress
        //if(++lineNum % 10000 == 0)
           // std::cout << "At line " << lineNum << std::endl;
        
        //Split a line into tokens by delimiting it on spaces
        //"Er Mah Gerd" becomes ["Er", "Mah", "Gerd"]
        tokens.clear();
        tokens = split(line, ' ', tokens);
        
        //If first token is a v then it gots to be a vertex
        if(tokens.at(0).compare("v") == 0)
        {
            withColor = false;
            //Parse the vertex line
            float x = std::stof(tokens.at(1));
            float y = std::stof(tokens.at(2));
            float z = std::stof(tokens.at(3));
            vertices->push_back(new Vector3(x, y, z));
            
            if (tokens.size()>4) {
                //vertices->resize(6);
                withColor = true;
                float a = std::stof(tokens.at(4));
                float b = std::stof(tokens.at(5));
                float c = std::stof(tokens.at(6));
                colors->push_back(new Vector3(a, b, c));
            }
        }
        else if(tokens.at(0).compare("vn") == 0)
        {
            float xn = std::stof(tokens.at(1));
            float yn = std::stof(tokens.at(2));
            float zn  = std::stof(tokens.at(3));
            normals->push_back(new Vector3(xn, yn, zn));
        }
        else if(tokens.at(0).compare("f") == 0)
        {
            fToken1.clear();
            fToken2.clear();
            fToken3.clear();
            fToken1 = OBJObject::split(tokens.at(1), '/');
            fToken2 = OBJObject::split(tokens.at(2), '/');
            fToken3 = OBJObject::split(tokens.at(3), '/');
            
            face.vs[0] = std::stof(fToken1.at(0));
            face.ns[0] = std::stof(fToken1.at(2));
            face.vs[1] = std::stof(fToken2.at(0));
            face.ns[1] = std::stof(fToken2.at(2));
            face.vs[2] = std::stof(fToken3.at(0));
            face.ns[2] = std::stof(fToken3.at(2));
            
            faces->push_back(face);
        }
        else if(tokens.at(0).compare("i don't know") == 0)
        {
            //Parse as appropriate
            //There are more line types than just the above listed
            //See the Wavefront Object format specification for details
        }
        
    }
    
    std::cout << "Done parsing." << std::endl;
    
}

//Split functions from the interwebs
//http://stackoverflow.com/questions/236129/split-a-string-in-c
std::vector<std::string>& OBJObject::split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> OBJObject::split(const std::string &s, char delim)
{
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
