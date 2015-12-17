#pragma once
#ifndef __ENGINE_FILE_H__
#define __ENGINE_FILE_H__

#include <string>
#include "Object.h"

using namespace std;

class File : public Object
{
public:
	// 以文本方式读取所有数据
	static const string readAllText(const string & path);

};

#endif //__ENGINE_FILE_H__
