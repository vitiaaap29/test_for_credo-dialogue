#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Enter the name of the source file" << endl;
	TCHAR* fileName = new TCHAR[MAX_PATH];
	wcin.getline(fileName, MAX_PATH, '\n');
	HANDLE fileHandler = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0,
			NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL , NULL);
	if (fileHandler != INVALID_HANDLE_VALUE )
	{
		TCHAR* resultFileName = removeComment(fileName, fileHandler);
		wcout << L"Result in " << resultFileName << endl;
	}
	else
	{
		cout << "Error: file not exist or permission denied\nPress any key for exit. " << GetLastError() << endl;
		cin.get();
		return EXIT_FAILURE;
	}
	CloseHandle(fileHandler);
	cout << "Press any key for exit" << endl;
	cin.get();

	return EXIT_SUCCESS;
}
