#include <iostream>
#include <Windows.h>
#include <time.h>


void FindChat(HWND hnd, char * msg) {
	HWND chk1 = FindWindowEx(hnd, 0, "RichEdit20W", 0);
	HWND chk2 = FindWindowEx(hnd, 0, "Edit", 0);
	HWND chk3 = FindWindowEx(hnd, 0, "EVA_VH_ListControl_Dblclk", 0);
	/*
	채팅방핸들에는 고유의 3가지 자식핸들이있다.
	해당핸들이 고유의 3가지 자식핸들을 가지고있으면
	채팅방핸들을 구한것이다.
	*/
	if ((chk1 != NULL) && (chk2 != NULL) && (chk3 != NULL))
	{	
		SendMessage(chk1, WM_SETTEXT, NULL, (LPARAM)msg);
		Sleep(100);
		PostMessage(chk1, WM_KEYDOWN, VK_RETURN, 0);
		PostMessage(chk1, WM_KEYUP, VK_RETURN, 0);
	}
}

int main()
{
	using namespace std;
	HWND head = FindWindow(TEXT("#32770"), 0);
	char msg[1000];
	while (1) {
		cin.getline(msg,1000);
		do {
			head = GetNextWindow(head, GW_HWNDNEXT);
			FindChat(head, msg);
		} while (head != NULL);
		head = FindWindow(TEXT("#32770"), 0);
		system("cls");
	}
	system("pause");

	return 0;	
}