#ifndef _DXINPUT_H
#include <dinput.h>
#define _DXINPUT_H
int Init_directin(HWND);
int Init_Key(HWND);
void Poll_key();
int Key_down(int);
void Kill_Keyboard();
extern LPDIRECTINPUT8 dinput;
extern LPDIRECTINPUTDEVICE8 dikeyboard;
#endif

