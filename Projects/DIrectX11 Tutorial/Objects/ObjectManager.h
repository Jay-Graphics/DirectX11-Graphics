#pragma once
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	void Update();
	void AddObject(Object* obj);
	void RemoveObject(Object* obj);

private:

	// Some way to store objects

};
