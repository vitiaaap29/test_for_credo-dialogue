#include"stdafx.h"

using namespace std;

/*
 * Remove patr string between delimeters: firstDelimeter, secondDelimeter.
 */
void removeBetweenDelimeters(string& sourceStr, string firstDelimeter, string secondDelimeter, bool needDeleteSecondDelimeter)
{
	string::iterator it = sourceStr.begin();

	size_t findIndex = sourceStr.find(firstDelimeter, 0);
	while( findIndex != string::npos)
	{
		size_t endOneLineComment = sourceStr.find(secondDelimeter, findIndex);
		if (endOneLineComment != string::npos)
		{
			if (needDeleteSecondDelimeter)
			{
				sourceStr.erase(sourceStr.begin() + findIndex, sourceStr.begin() + endOneLineComment + secondDelimeter.size());
			}
			else
			{
				sourceStr.erase(sourceStr.begin() + findIndex, sourceStr.begin() + endOneLineComment);
			}
		}
		findIndex = sourceStr.find(firstDelimeter, 0);
	}
}
