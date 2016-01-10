#include "Object.h"
#include <iostream>

vector<Object *> * Object::depositary = nullptr;
mutex Object::mtx;

const bool Object::init() {
	//实现内存管理机制代码

	if (depositary == nullptr) {
		depositary = new vector<Object *>();
	}
	this->autorelease();

	return true;
}

void Object::retain()
{
	this->referenceCount++;
}

void Object::autorelease()
{
	mtx.lock();
	depositary->push_back(this);
	mtx.unlock();
	cout << depositary->size() << endl;
}

void Object::release()
{
	--this->referenceCount;
}
