#include "RenderManager.h"

RenderManager::RenderManager()
{
}

RenderManager::~RenderManager()
{
	m_Context->Release();
	m_Device->Release();
	m_SwapChain->Release();
}

void RenderManager::Update()
{
}

void RenderManager::Draw()
{

	const FLOAT bg[4] = { 0.0f , 0.0f , 1.0f , 1.0f };
	m_Context->ClearRenderTargetView(m_MainRenderTargetView, bg);

	//Present the backbuffer to the screen
	m_SwapChain->Present(0, 0);

}

Return RenderManager::InitWindow(Window_Information win)
{
	HRESULT hr;


	//Describe our Buffer
	DXGI_MODE_DESC bufferDesc;

	ZeroMemory(&bufferDesc, sizeof(DXGI_MODE_DESC));

	bufferDesc.Width = win.Width;
	bufferDesc.Height = win.Height;
	bufferDesc.RefreshRate.Numerator = 60;
	bufferDesc.RefreshRate.Denominator = 1;
	bufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	bufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	bufferDesc.Scaling = DXGI_MODE_SCALING_CENTERED;

	//Describe our SwapChain
	DXGI_SWAP_CHAIN_DESC swapChainDesc;

	ZeroMemory(&swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	swapChainDesc.BufferDesc = bufferDesc;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.BufferCount = 1;
	swapChainDesc.OutputWindow = win.hwnd;
	swapChainDesc.Windowed = TRUE;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;


	//Create our SwapChain
	hr = D3D11CreateDeviceAndSwapChain(NULL, D3D_DRIVER_TYPE_HARDWARE, NULL, NULL, NULL, NULL,
		D3D11_SDK_VERSION, &swapChainDesc, &m_SwapChain, &m_Device, NULL, &m_Context);
	if (FAILED(hr))
	{
		return Return::FAILURE;
	}

	//Create our BackBuffer
	ID3D11Texture2D* BackBuffer;
	hr = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&BackBuffer);
	if (FAILED(hr))
	{
		return Return::FAILURE;
	}

	//Create our Render Target
	hr = m_Device->CreateRenderTargetView(BackBuffer, NULL, &m_MainRenderTargetView);
	BackBuffer->Release();
	if (FAILED(hr))
	{
		return Return::FAILURE;
	}

	//Set our Render Target
	m_Context->OMSetRenderTargets(1, &m_MainRenderTargetView, NULL);

	return Return::SUCCESS;

}

Return RenderManager::InitScene()
{




	return Return::SUCCESS;
}
