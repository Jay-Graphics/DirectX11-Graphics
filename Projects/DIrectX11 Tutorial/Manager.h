#pragma once
#include "Objects/ObjectManager.h"
#include "Render\RenderManager.h"

class Manager
{
public:
	Manager();
	~Manager();

	void Update();
	void Render();
	Return CreateDX11Window(Window_Information window);

private:

	RenderManager* m_Render = nullptr;
	ObjectManager* m_Object = nullptr;

};