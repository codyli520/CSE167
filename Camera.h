#ifndef CSE167_Camera_h
#define CSE167_Camera_h

#include "Matrix4.h"
#include "Vector3.h"
#include "Vector4.h"

class Camera
{
private:
    
protected:
    
      //Inverse of Camera Matrix
    
public:
    Matrix4 c;   //Camera Matrix
    Matrix4 ci;
    Vector3 e;   //Center of Projection
    Vector3 d;   //Look At
    Vector3 up;  //Up Vector ^
    
    Camera(void);
    ~Camera(void);
    
    void update(void);
    void reset(void);
    Matrix4& getMatrix(void);
    Matrix4& getInverseMatrix(void);
    
    void set(Vector3& d, Vector3& e, Vector3& up);
    
};

#endif
