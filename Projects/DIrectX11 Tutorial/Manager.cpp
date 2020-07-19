#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
	delete m_Render;
}

void Manager::Update()
{
	m_Object->Update();
}

void Manager::Render()
{
	m_Render->Update();
	m_Render->Draw();
}

Return Manager::CreateDX11Window(Window_Information window)
{
	m_Render = new RenderManager();

	if (FAIL(m_Render->InitWindow(window)))
	{
		return Return::FAILURE;
	}

	if (FAIL(m_Render->InitScene()))
	{
		return Return::FAILURE;
	}

	return Return::SUCCESS;
}

