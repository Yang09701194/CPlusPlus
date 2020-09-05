// GetDLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <MathLib.h>

typedef int(__cdecl *MYPROC)(LPWSTR);
int main()
{
	FARPROC pfAddInt;

	HMODULE hLibrary = LoadLibraryW(L"E:\\GS2018\\E\\Yang\\Program\\Git\\GitYang\\TestCSharpCallCpp\\TestCSharpCallCpp\\TestMain\\Debug\\MathLib.dll");

	if (hLibrary)
	{
		pfAddInt = GetProcAddress(hLibrary, "Variable");

		if (pfAddInt)
		{
			std::cout << *pfAddInt << std::endl;
		}

		FreeLibrary(hLibrary);
	}
	else
	{
		std::cout << "Failed To Load Library" << std::endl;
	}

	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
