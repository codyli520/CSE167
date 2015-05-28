#include <stdio.h>
#include "Group.h"
using namespace std;
Group::Group()
{
    //
}

Group::~Group()
{
    childNodes.clear();
}

//traverse the list of children and call each child node's draw function
void Group::draw(Matrix4 C)
{
    
    std::list <Node*>::iterator it;
    for (it = childNodes.begin(); it != childNodes.end(); it++)
    {
        (*it)->draw(C);
    }
}

void Group::update()
{
    //
}

void Group::addChild(Node *child)
{
    childNodes.push_back(child);
}

void Group::removeChild(Node *child)
{
    //childNodes.remove(child);
    std::list <Node*>::iterator it;
    for (it = childNodes.begin(); it != childNodes.end(); it++)
    {
        delete(*it);
    }
}