#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
    std::cout << "Enter the name of the source file" << std::endl;
    TCHAR* fileName = new TCHAR[MAX_PATH];
    std::wcin.getline(fileName, MAX_PATH, '\n');

    HANDLE fileHandler = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, 0,
            NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL , NULL);

    if (fileHandler != INVALID_HANDLE_VALUE)
    {
        std::wstring* resultFileName = removeComment(fileName, fileHandler);
        if (resultFileName != NULL)
        {
            std::wcout << L"Result in " << resultFileName->c_str() << std::endl;
            delete resultFileName;
        }
        CloseHandle(fileHandler);
    }
    else
    {
        std::cout << "Error: file not exist or permission denied\nPress any key for exit. " << std::endl;
        std::cin.get();
        return EXIT_FAILURE;
    }
    
    delete[] fileName;

    std::cout << "Press any key for exit" << std::endl;
    std::cin.get();

    return EXIT_SUCCESS;
}
