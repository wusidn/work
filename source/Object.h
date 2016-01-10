#pragma once
#ifndef __ENGINE_OBJECT_H__
#define __ENGINE_OBJECT_H__

#include <vector>
#include <mutex>


using namespace std;

class Object {
public:

	//static Object * create();
	virtual const bool init();

	void retain();
	void autorelease();
	void release();

private:
	int referenceCount;

	static vector<Object *> * depositary;
	static mutex mtx;
	
};

#endif //__ENGINE_OBJECT_H__