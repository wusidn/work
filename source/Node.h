#pragma once
#ifndef __NODE_H__
#define __NODE_H__

#include "Object.h"
#include "Point.h"

class Node : public Object
{
public:
	Point position;
	static Node * create();
	static Node * create(const Point & position);

	virtual const bool init(const Point & position);

};

#endif //__NODE_H__
