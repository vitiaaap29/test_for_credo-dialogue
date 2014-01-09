#include"stdafx.h"

#define PORTION_SIZE 0x0000FFFF

/*
 * Remove comments from file, which is described filename sourceFileName and 
 * handler sourceFileHandler. Generate file without comment with the name 
 * of the form: sourceFileName + result.cpp. Return sourceFileName + result.cpp.
 * If error return NULL, and display error message in stderr.
 */
std::wstring* removeComment(const TCHAR* sourceFileName, const HANDLE sourceFileHandler)
{
    std::wstring* resultFileName = new std::wstring(sourceFileName);
    resultFileName->append(L"_result.cpp");

    HANDLE destinationFileHandler = CreateFile((TCHAR*)resultFileName->c_str(), GENERIC_WRITE, 0,
        NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (destinationFileHandler != NULL)
    {
        LARGE_INTEGER li;
        GetFileSizeEx(sourceFileHandler, &li);
        long long size = li.QuadPart;

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

            std::string *portion = new std::string(buffer, bufferSize);
            removeBetweenDelimeters(*portion, "//", "\n", false);
            removeBetweenDelimeters(*portion, "/*", "*/");

            WriteFile(destinationFileHandler, portion->c_str(), portion->size() * sizeof(portion->at(0)), &countReadBytes, NULL);
            if (countReadBytes <= 0)
            {
                fprintf(stderr, "Error with code %d\n", GetLastError());
                return NULL;
            }
            delete portion;
        }
        delete[] buffer;
        CloseHandle(destinationFileHandler);
    }
    else
    {
        fprintf(stderr, "Error with code %d\n", GetLastError());
        resultFileName = NULL;
    }

    return resultFileName;
}
