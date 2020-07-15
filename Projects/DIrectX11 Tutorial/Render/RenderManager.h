#include "../Headers.h"
class RenderManager
{
public:
	RenderManager();
	~RenderManager();
	void Update();
	void Draw();

private:

	ID3D11Device* device = nullptr;
	IDXGISwapChain* swapChain = nullptr;
	ID3D11DeviceContext* context = nullptr;

	ID3D11RenderTargetView* mainRenderTarget = nullptr;
	ID3D11DepthStencilView* depthStencil = nullptr;

};