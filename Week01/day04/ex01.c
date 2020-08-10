#include <windows.h> 

int WINAPI 
WinMain (HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpCmdLine, int nShowCmd) 
{ 
  MessageBoxW (NULL, L"Hello World!", L"hello", MB_OKCANCEL | MB_ICONWARNING); 
  // "Hello World!" 앞 L은 unicode를 뜻함.

  return 0; 
}
//SHOW MESSAGE BOX IN C