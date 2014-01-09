#include"stdafx.h"

/*
 * Remove patr string between delimeters: firstDelimeter, secondDelimeter.
 */
void removeBetweenDelimeters(std::string& sourceStr, const std::string firstDelimeter, const std::string secondDelimeter, const bool needDeleteSecondDelimeter)
{
    std::string::iterator it = sourceStr.begin();

    size_t findIndex = sourceStr.find(firstDelimeter, 0);
    while (findIndex != std::string::npos)
    {
        size_t endOneLineComment = sourceStr.find(secondDelimeter, findIndex);
        if (endOneLineComment != std::string::npos)
        {
            if (needDeleteSecondDelimeter)
            {
                sourceStr.erase(sourceStr.begin() + findIndex, sourceStr.begin() + endOneLineComment + secondDelimeter.size());
            }
            else
            {
                sourceStr.erase(sourceStr.begin() + findIndex, sourceStr.begin() + endOneLineComment);
            }
            findIndex = sourceStr.find(firstDelimeter, 0);
        }
        else
        {
            findIndex = std::string::npos;
        }
    }
}
