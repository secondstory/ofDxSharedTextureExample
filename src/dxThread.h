#pragma once


#include "ofMain.h"

#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include <xnamath.h>
#include "resource.h"


//PL: causes weird crash on my laptop if the following is not defined.... Only when running in ofThread though
#define _XM_NO_INTRINSICS_


class myDxThread : public ofThread
{


private :
	Poco::Event dxReady;
	Poco::Event glReady;

		//--------------------------------------------------------------------------------------
// Global Variables
//--------------------------------------------------------------------------------------
	public :

HINSTANCE               g_hInst;
HWND                    g_hWnd ;
D3D_DRIVER_TYPE         g_driverType;
D3D_FEATURE_LEVEL       g_featureLevel;
ID3D11Device*           g_pd3dDevice;
ID3D11DeviceContext*    g_pImmediateContext;
IDXGISwapChain*         g_pSwapChain ;
ID3D11RenderTargetView* g_pRenderTargetView ;
ID3D11VertexShader*     g_pVertexShader;
ID3D11PixelShader*      g_pPixelShader ;
ID3D11InputLayout*      g_pVertexLayout ;
ID3D11Buffer*           g_pVertexBuffer ;
ID3D11Buffer*           g_pIndexBuffer ;
ID3D11Buffer*           g_pConstantBuffer ;


XMMATRIX                g_World;
XMMATRIX                g_View;
XMMATRIX                g_Projection;




	myDxThread();
	void threadedFunction();
	void waitForDxReady();
	void notifyGlReady();



int wWinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow );

HRESULT InitWindow( HINSTANCE hInstance, int nCmdShow );
HRESULT InitDevice();
void CleanupDevice();

void Render();


};