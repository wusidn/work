#include "Object.h"
#include <iostream>

list<Object *> * Object::depositary = nullptr;
mutex Object::mtx;

//初始化对象
const bool Object::init() {

	if (!depositary) {
		depositary = new list<Object *>();
	}
	this->autoRelease();

	return true;
}

//持久化
void Object::retain()
{
	this->referenceCount++;
}

//加入托管机制
void Object::autoRelease()
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

//遍历所有托管对象， 清理垃圾
void Object::__depositaryClean()
{
	if (!Object::depositary) {
		return;
	}


	for (auto item = Object::depositary->begin(); item != Object::depositary->end(); ) {
		if ((*item)->referenceCount > 0) {
			++item;
			continue;
		}
		Object * deleteObject = (*item);
		++item;

		Object::depositary->remove(deleteObject);
		delete deleteObject;
	}
}
