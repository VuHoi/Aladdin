#include "dxinput.h"
#define BUTTON_DOWN(obj,button) (obj.rgbButtons[button] & 0x80)
LPDIRECTINPUT8 dinput;
LPDIRECTINPUTDEVICE8 dikeyboard;

char keys[256];
int Init_directin(HWND hwnd)
{
	HRESULT result = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, NULL);
	if (result != DI_OK) return 0;
	result = dinput->CreateDevice(GUID_SysKeyboard, &dikeyboard, NULL);
	if (result != DI_OK) return 0;
	return 1;
}
int Init_Key(HWND hwnd)
{
	HRESULT result = dikeyboard->SetDataFormat(&c_dfDIKeyboard);
	if (result != DI_OK) return 0;
	result = dikeyboard->SetCooperativeLevel(hwnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	if (result != DI_OK) return 0;

	result = dikeyboard->Acquire();
	if (result != DI_OK) return 0;
	return 1;
}
void Poll_key()
{
	dikeyboard->GetDeviceState(sizeof(keys), (LPVOID)&keys);
}

int Key_down(int key)
{
	return (keys[key]&0x80);

}

void Kill_Keyboard()
{
	if (dikeyboard != NULL)
	{
		dikeyboard->Unacquire();
		dikeyboard->Release();
		dikeyboard = NULL;
	}
}