#ifndef CSE167_MatrixTransform_h
#define CSE167_MatrixTransform_h

#include "Group.h"

class MatrixTransform: public Group
{
public:
    std::list<Node*> childM;
    Matrix4 M;
    MatrixTransform(Matrix4);
    ~MatrixTransform();
    void draw(Matrix4);
    void update();
    void addChild(Node *child);
    void removeChild(Node *child);
};


#endif
