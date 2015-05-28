#ifndef CSE167_Node_h
#define CSE167_Node_h

#include <iostream>
#include "Matrix4.h"

class Node{
public:
	Node();
	virtual ~Node();
	virtual void draw(Matrix4) = 0;
	virtual void update() = 0;
};

#endif
		