#include "stdafx.h"

std::wstring* removeComment(TCHAR* sourceFileName, HANDLE sourceFileHandler);
void removeBetweenDelimeters(std::string& sourceStr, std::string firstDelimeter, std::string secondDelimeter, bool needDeleteSecondDelimeter = true);
