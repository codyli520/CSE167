#ifndef CSE167_Group_h
#define CSE167_Group_h

#include <iostream>
#include <stdio.h>
#include <list>
#include "Node.h"

class Group : public Node
{
public:
    std::list<Node*> childNodes;
    
	Group();
	~Group();
    
	void draw(Matrix4 C);
    void update();
	void addChild(Node *child);
	void removeChild(Node *child);

};

#endif