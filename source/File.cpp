#include "File.h"
#include <fstream>

const string File::readAllText(const string & path)
{
	string result;
	ifstream fileStream;
	int len;
	fileStream.open(path.c_str(), ios::out);
	if (!fileStream.is_open())
	{
		return "";
	}
	fileStream.seekg(0, ios::end);
	len = (int)fileStream.tellg();
	fileStream.seekg(0, ios::beg);

	char * buffer = new char[len + 1];
	buffer[len] = 0;
	fileStream.read(buffer, len);
	result = string(buffer);
	delete[] buffer;
	return result;
}
