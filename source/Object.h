#pragma once
#ifndef __ENGINE_OBJECT_H__
#define __ENGINE_OBJECT_H__

#include <list>
#include <mutex>


using namespace std;

class Object {
public:

	//static Object * create();
	virtual const bool init();

	void retain();
	void autoRelease();
	void release();

	static void __depositaryClean();

private:
	int referenceCount;

	static list<Object *> * depositary;
	static mutex mtx;
	
};

#endif //__ENGINE_OBJECT_H__