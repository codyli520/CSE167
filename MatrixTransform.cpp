#include <stdio.h>
#include "MatrixTransform.h"
using namespace std;

MatrixTransform::MatrixTransform(Matrix4 matrix)
{
    this->M = matrix;
}

MatrixTransform::~MatrixTransform()
{
    childM.clear();
}

void MatrixTransform::draw(Matrix4 C)
{
    
    M = C.multiply(M);
    
    for (std::list<Node*>::iterator it = childM.begin(); it != childM.end(); ++it){
        (*it)->draw(M);
    }
}

void MatrixTransform::update()
{
    //
}

void MatrixTransform::addChild(Node *child)
{
    childM.push_back(child);
}

void MatrixTransform::removeChild(Node *child)
{
    //childNodes.remove(child);
    std::list <Node*>::iterator it;
    for (it = childM.begin(); it != childM.end(); it++)
    {
        delete(*it);
    }
}