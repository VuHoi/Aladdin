#include "GAME.h"


GAME::GAME(HINSTANCE hInstance, int windowsWidth, int windowsHeight, char * gameName, int frameRate)
{
	GLOBAL::SethInstance(hInstance);
	GLOBAL::SetWindowsWidth(windowsWidth);
	GLOBAL::SetWindowsHeight(windowsHeight);
	GLOBAL::SetGameName(gameName);
	GLOBAL::SetFrameRate(frameRate);
}

GAME::~GAME()
{
	if (GLOBAL::GetDirect())
		GLOBAL::GetDirect()->Release();

	if (GLOBAL::GetDirectDevice())
		GLOBAL::GetDirectDevice()->Release();

	if (GLOBAL::GetBackBuffer())
		GLOBAL::GetBackBuffer()->Release();

}

void GAME::Initialize()
{
	this->InitWindows();
	this->InitDevice();
	this->LoadResource();
	if (!Init_directin(GLOBAL::GetHWND()))
	{
		MessageBox(GLOBAL::GetHWND(), "XAM", "ERR1", MB_OK);
		return;
	}
	if (!Init_Key(GLOBAL::GetHWND()))
	{
		MessageBox(GLOBAL::GetHWND(), "ERR", "ERR2", MB_OK);
		return;
	}
	
	this->mAladdin = new ALADDIN(D3DXVECTOR3(200, 500, 0));
	this->mLastLocation = D3DXVECTOR3(50, 500, 0);
	this->mState = GLOBAL::SWING;
	this->mMap = new SurfaceManager("Map\\Map1.png");
}

D3DVECTOR oldPos = D3DVECTOR();
bool curDirect = true; //=GLOBAL::GetCurDirect(); //true is right,false is left
int curTime = 0;//GetTickCount();
bool stand = true; // Kiem soat trang thai dung im
void UpdateCurPos(D3DVECTOR &a, D3DVECTOR b)
{
	a.x=b.x;
	a.y= b.y;
}

void GAME::Run()
{

	

	Poll_key();
	
	if (GLOBAL::GetDirectDevice()->BeginScene())
	{
		GLOBAL::GetSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);
		GLOBAL::GetDirectDevice()->ColorFill(
			GLOBAL::GetBackBuffer(),
			NULL,
			D3DCOLOR_XRGB(0, 0, 0));

		this->mMap->Render(NULL, NULL);
	
		if (Key_down(DIK_RIGHT) && this->mState!=GLOBAL::JUMP)
		{
			
			curDirect = true; //Dang quay ve ben phai
			GLOBAL::SetCurDirect(true); //Dang quay ve ben phai

			this->mState = GLOBAL::WALK;  //Set state hien tai cho Aladdin
			GLOBAL::SetState(mState); //Set state hien tai cho global

			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());//Update vi tri cu de so sanh

			stand = false; //Khong dung im

			
			
		}
		else
		if (Key_down(DIK_UP))
		{
			this->mState = GLOBAL::JUMP;
			GLOBAL::SetState(mState);
			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());//Update vi tri cu de so sanh

			stand = false;
		}
		else
		if (Key_down(DIK_LEFT) && this->mState != GLOBAL::JUMP)
		{
			curDirect = false;
			GLOBAL::SetCurDirect(false);
			this->mState = GLOBAL::WALK;
			GLOBAL::SetState(mState);

			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());//Update vi tri cu de so sanh
			stand = false;
		
		}
		else if (Key_down(DIK_DOWN))
		{
			this->mState = GLOBAL::SIT;
			GLOBAL::SetState(mState);
			stand = false;

		
		
		}
		else if (Key_down(DIK_SPACE))
		{
			curTime = GetTickCount();
			this->mState = GLOBAL::FIGHT;
			GLOBAL::SetState(mState);
			stand = false;
		}
		if(stand)
		{
			this->mState = GLOBAL::STAND;
			GLOBAL::SetState(mState);
		}

		int temp = GetTickCount();
		switch (this->mState)
		{
		case GLOBAL::JUMP:
			if (curDirect) //Check direct to draw
			{
				this->mAladdin->Activities(mState, GLOBAL::RIGHT);

				if (mAladdin->GetCurrentLocation().x - oldPos.x >179)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			else
			{
				this->mAladdin->Activities(mState, GLOBAL::LEFT);

				if (-mAladdin->GetCurrentLocation().x + oldPos.x >179)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}

			break;
		case GLOBAL::WALK:
			if (curDirect)
			{
				this->mAladdin->Activities(GLOBAL::WALK, GLOBAL::RIGHT);
				if (mAladdin->GetCurrentLocation().x - oldPos.x >50)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			else
			{
				this->mAladdin->Activities(GLOBAL::WALK, GLOBAL::LEFT);
				if (oldPos.x-mAladdin->GetCurrentLocation().x   >50)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			break;
			


		case GLOBAL::SIT:
			if (curDirect) //Check direct to draw
				this->mAladdin->Activities(mState, GLOBAL::RIGHT);
			else this->mAladdin->Activities(mState, GLOBAL::LEFT);
			break;


		case GLOBAL::FIGHT:
			if (temp-curTime> 500)
			this->mState = GLOBAL::STAND;
			if (curDirect) //Check direct to draw
				this->mAladdin->Activities(mState, GLOBAL::RIGHT);
			else this->mAladdin->Activities(mState, GLOBAL::LEFT);
			break;

		
			
		
		case GLOBAL::STAND:
			if (curDirect) //Check direct to draw
				this->mAladdin->Activities(mState, GLOBAL::RIGHT);
			else this->mAladdin->Activities(mState, GLOBAL::LEFT);
			break;
		}
	/*	switch (this->mState)
		{
		case GLOBAL::SWING:
		{
			this->mAladdin->Activities(GLOBAL::SWING, GLOBAL::LEFT);
			if (this->mAladdin->GetCurrentLocation().x <= 50)
			{
				this->mState = GLOBAL::DROP;
				this->mAladdin->SetSpeed(10);
			}
			break;
		}
		case GLOBAL::DROP:
		{
			this->mAladdin->SetEndLocation(D3DXVECTOR3(this->mLastLocation.x, 500, 0));
			this->mAladdin->Activities(GLOBAL::DROP, GLOBAL::RIGHT);
			if (this->mAladdin->GetCurrentLocation().y >= this->mAladdin->GetEndLocation().y)
			{ 
				this->mState = GLOBAL::WALK;
			}
			break;
		}
		case GLOBAL::WALK:
		{
			this->mAladdin->Activities(GLOBAL::WALK, GLOBAL::RIGHT);
			if (this->mAladdin->GetCurrentLocation().x >= 931)
				this->mState = GLOBAL::CLIMB;
			break;
		}
		case GLOBAL::CLIMB:
		{
			this->mAladdin->Activities(GLOBAL::CLIMB, GLOBAL::UP);
			if(this->mAladdin->GetCurrentLocation().y<=100)
				this->mState = GLOBAL::SWING;
			break;
		}
		}*/


		GLOBAL::GetSpriteHandler()->End();
		GLOBAL::GetDirectDevice()->EndScene();
	}
	GLOBAL::GetDirectDevice()->Present(NULL, NULL, NULL, NULL);
}
LRESULT GAME::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		return 0;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	} // End switch
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

void GAME::InitWindows()
{
	static TCHAR szAppName[] = TEXT("HelloWin");
	WNDCLASS wndclass;
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = GAME::WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = GLOBAL::GethInstance();
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;
	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT(" The program requires Windows"), szAppName, MB_ICONERROR);
		return;
	}
	GLOBAL::SetHWND(
		CreateWindow(szAppName, // Tên lớp cửa sổ
			TEXT(" The Hello World Program"), // Tiêu đề cửa sổ
			WS_OVERLAPPEDWINDOW, // Kiểu cửa sổ
			CW_USEDEFAULT, // Tọa độ x
			CW_USEDEFAULT, // Tọa độ y
			GLOBAL::GetWindowsWidth(), // Chiều ngang
			GLOBAL::GetWindowsHeight(), // Chiều dọc
			NULL, // Cửa sổ cha
			NULL, // Thực đơn
			GLOBAL::GethInstance(), // Định danh
			NULL)); // Tham số

	ShowWindow(GLOBAL::GetHWND(), SW_SHOWNORMAL);
	UpdateWindow(GLOBAL::GetHWND());
}

void GAME::InitDevice()
{
	GLOBAL::SetDirect(Direct3DCreate9(D3D_SDK_VERSION));
	D3DPRESENT_PARAMETERS	d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = GLOBAL::GetWindowsHeight();
	d3dpp.BackBufferWidth = GLOBAL::GetWindowsWidth();

	LPDIRECT3DDEVICE9 device;

	GLOBAL::GetDirect()->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		GLOBAL::GetHWND(),
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&device);

	GLOBAL::SetDirectDevice(device);

	if (!GLOBAL::GetDirectDevice())
	{
		MessageBox(NULL, "Can't create Direct Device", "Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

	LPDIRECT3DSURFACE9 backbuffer;

	GLOBAL::GetDirectDevice()->GetBackBuffer(
		0,
		0,
		D3DBACKBUFFER_TYPE_MONO,
		&backbuffer);

	GLOBAL::SetBackBuffer(backbuffer);

	LPD3DXSPRITE spriteHandler;

	if (D3DXCreateSprite(GLOBAL::GetDirectDevice(), &spriteHandler) != D3D_OK)
	{
		MessageBox(NULL, "Can't create spritehandler!", "Error", MB_OK | MB_ERR_INVALID_CHARS);
		return;
	}

	GLOBAL::SetSpriteHandler(spriteHandler);
}

void GAME::LoadResource()
{

}

