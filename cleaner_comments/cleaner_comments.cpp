/*
 * Command-line options: filename
 */
#include "stdafx.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc < 2)
	{
		cout << "Wrong number parameters!\nPress any key for exit" << endl;
		cin.get();
		return EXIT_FAILURE;
		//argv[1] = L"C:\\Program Files\\Google\\cleaner_comments.cpp";
	}

	TCHAR* fileName = argv[1];
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

