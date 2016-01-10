#include "Node.h"

Node * Node::create()
{
	return create(*Point::create());
}

Node * Node::create(const Point & position)
{
	Node * result = new Node();
	if (!result->init(position)) {
		delete result;
		result = nullptr;
	}
	return result;
}


const bool Node::init(const Point & position)
{
	if (!Object::init()) {
		return false;
	}

	this->position = position;

	return true;
}
