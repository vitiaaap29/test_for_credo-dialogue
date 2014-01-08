#include"stdafx.h"

#define PORTION_SIZE 0x0000FFFF

using namespace std;

TCHAR* removeComment(TCHAR* sourceFile, HANDLE sourceFileHandler)
{
	TCHAR* destinationFileName = NULL;
	wstring* resultFileName = new wstring(sourceFile);
	resultFileName->append(L"result.cpp");
	destinationFileName = (TCHAR*)resultFileName->c_str();

	HANDLE destinationFileHandler = CreateFile(destinationFileName, GENERIC_WRITE, 0,
		NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (destinationFileHandler != NULL)
	{
		LARGE_INTEGER li;
		GetFileSizeEx(sourceFileHandler, &li);
		INT64 size = li.QuadPart;

		char* buffer = NULL;
		for (; size > 0; size -= PORTION_SIZE)
		{
			if (buffer != NULL)
			{
				delete[] buffer;
			}
			int bufferSize = PORTION_SIZE;
			if (size < PORTION_SIZE)
			{
				bufferSize = size;
			}
			buffer = new char[bufferSize];

			DWORD countReadBytes = 0;
			ReadFile(sourceFileHandler, buffer, bufferSize, &countReadBytes, NULL);
			if (countReadBytes != bufferSize)
			{
				fprintf(stderr, "Error with code %d\n", GetLastError());
				return NULL;
			}

			string *portion = new string(buffer, bufferSize);
			removeBetweenDelimeters(*portion, "//", "\n");
			removeBetweenDelimeters(*portion, "/*", "*/");

			WriteFile(destinationFileHandler, portion->c_str(), portion->size() * sizeof(portion->at(0)), &countReadBytes, NULL);
			if (countReadBytes <= 0)
			{
				fprintf(stderr, "Error with code %d\n", GetLastError());
				return NULL;
			}
		}
	}
	else
	{
		fprintf(stderr, "Error with code %d\n", GetLastError());
		destinationFileName = NULL;
	}

	return destinationFileName;
}