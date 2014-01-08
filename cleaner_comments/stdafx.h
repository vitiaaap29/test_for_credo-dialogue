// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include <stdio.h>
#include <tchar.h>
#include<string>
#include<Windows.h>

TCHAR* removeComment(TCHAR* sourceFile, HANDLE sourceFileHandler);
void removeBetweenDelimeters(std::string& sourceStr, std::string firstDelimeter, std::string secondDelimeter, bool needDeleteSecondDelimeter = true);
