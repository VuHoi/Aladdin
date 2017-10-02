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
GLOBAL::DIRECTION curDirect = GLOBAL::RIGHT; //=GLOBAL::GetCurDirect(); //true is right,false is left
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
	
		if (Key_down(DIK_RIGHT) && this->mState!=GLOBAL::JUMP && this->mState != GLOBAL::DROP)
		{
			curDirect = GLOBAL::RIGHT; //Dang quay ve ben phai
			if (mState == GLOBAL::CLIMB)
				mState = GLOBAL::DROP;
			else this->mState = GLOBAL::WALK;  //Set state hien tai cho Aladdin
			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());//Update vi tri cu de so sanh
			stand = false; //Khong dung im
			

		}
		else
		if (Key_down(DIK_UP) && this->mState != GLOBAL::JUMP)
		{
			if (mAladdin->GetCurrentLocation().x >= 920 && mAladdin->GetCurrentLocation().x <= 960)
			{
				this->mState = GLOBAL::CLIMB;
				curDirect = GLOBAL::UP;
			}
			else
			{

				this->mState = GLOBAL::JUMP;
				//Update vi tri cu de so sanh
		
			}
			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());
			stand = false;
		}
		else
		if (Key_down(DIK_LEFT) && this->mState != GLOBAL::JUMP && this->mState != GLOBAL::DROP)
		{
			curDirect = GLOBAL::LEFT;
			if (mState == GLOBAL::CLIMB)
			{
				mState = GLOBAL::DROP;
				
			}
			else this->mState = GLOBAL::WALK;
			UpdateCurPos(oldPos, mAladdin->GetCurrentLocation());//Update vi tri cu de so sanh
			stand = false;
		
		}
		else
		if (Key_down(DIK_DOWN) && this->mState != GLOBAL::JUMP && this->mState != GLOBAL::SITFIGHT)
		{
			if (mAladdin->GetCurrentLocation().x >= 920 && mAladdin->GetCurrentLocation().x <= 960)
			{
				this->mState = GLOBAL::CLIMB;
				curDirect = GLOBAL::DOWN;
			}
			else
			{
				this->mState = GLOBAL::SIT;
			
			}
			stand = false;

		}
		if (Key_down(DIK_SPACE ) && this->mState != GLOBAL::JUMP)
		{
			curTime = GetTickCount();
			if (mState == GLOBAL::SIT || mState == GLOBAL::SITFIGHT)
				this->mState = GLOBAL::SITFIGHT;
			else
				this->mState = GLOBAL::FIGHT;
			stand = false;
		}
	
		else 

		if(stand)
		{
			this->mState = GLOBAL::STAND;
			
		}

		GLOBAL::SetState(mState);

		int temp = GetTickCount();

		switch (this->mState)
		{
		case GLOBAL::AFTERDROP:
			if (temp - curTime >900)
			this->mState = GLOBAL::STAND;
			this->mAladdin->Activities(mState, curDirect);
			break;
		case GLOBAL::DROP:
			this->mAladdin->SetEndLocation(D3DXVECTOR3(this->mLastLocation.x, 480, 0));
			if (this->mAladdin->GetCurrentLocation().y >= this->mAladdin->GetEndLocation().y)
			{
				curTime = GetTickCount();
				this->mState = GLOBAL::AFTERDROP;

			}
			else
			{
				this->mAladdin->Activities(mState, curDirect);
			}
		
			
			break;
		case GLOBAL::CLIMB:
			if (curDirect == GLOBAL::UP)
			{
				this->mAladdin->Activities(mState, curDirect);
				if (oldPos.y - mAladdin->GetCurrentLocation().y >10)
				{
					curDirect = GLOBAL::NONE;
				}
			}
			else if (curDirect == GLOBAL::DOWN)
			{
				this->mAladdin->Activities(mState, curDirect);
				if (mAladdin->GetCurrentLocation().y-oldPos.y  >10)
				{
					curDirect = GLOBAL::NONE;
				}
			}
			else this->mAladdin->Activities(mState, curDirect);
			break;
		case GLOBAL::SITFIGHT:
		case GLOBAL::SIT:
		case GLOBAL::STAND:
			this->mAladdin->Activities(mState, curDirect);
			break;
		
		case GLOBAL::JUMP:
			if (curDirect == GLOBAL::RIGHT) //Check direct to draw
			{
				this->mAladdin->Activities(mState, curDirect);

				if (mAladdin->GetCurrentLocation().x - oldPos.x >179)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			else if (curDirect == GLOBAL::LEFT)
			{
				this->mAladdin->Activities(mState, curDirect);

				if (-mAladdin->GetCurrentLocation().x + oldPos.x >179)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			
			break;

		case GLOBAL::WALK:
			if (curDirect == GLOBAL::RIGHT)
			{
				this->mAladdin->Activities(mState, curDirect);
				if (mAladdin->GetCurrentLocation().x - oldPos.x >50)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			else if(curDirect == GLOBAL::LEFT)
			{
				this->mAladdin->Activities(mState, curDirect);
				if (oldPos.x-mAladdin->GetCurrentLocation().x   >50)
				{
					this->mState = GLOBAL::STAND;
					stand = true;
				}
			}
			break;
			
	


		case GLOBAL::FIGHT:
			if (temp-curTime> 500)
			this->mState = GLOBAL::STAND;
			this->mAladdin->Activities(mState, curDirect);
			break;
		}

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

