#include "stdafx.h"

std::wstring* removeComment(const TCHAR* sourceFileName, const HANDLE sourceFileHandler);
void removeBetweenDelimeters(std::string& sourceStr, const std::string firstDelimeter, const std::string secondDelimeter, const bool needDeleteSecondDelimeter = true);
