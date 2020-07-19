#pragma once
#include "../Globals/Headers.h"

class RenderManager
{
public:
	RenderManager();
	~RenderManager(); // Release DX11 Things Here
	void Update();
	void Draw();

	Return InitWindow(Window_Information win); // Initializing DX11
	Return InitScene();					 // Initialize Scene


private:

	IDXGISwapChain* m_SwapChain = nullptr;
	ID3D11Device* m_Device = nullptr;
	ID3D11DeviceContext* m_Context = nullptr;

	ID3D11RenderTargetView* m_MainRenderTargetView = nullptr;
	ID3D11DepthStencilView* m_DepthStencil = nullptr;

};