#pragma once

#include <string>

namespace Helper
{
    std::string extractFileFormat(const std::string &path)
    {
        for (uint32_t i = path.size(); i >= 0; i--)
        {
            if (path[i] == '.')
            {
                return path.substr(i, path.size());
            }
        }
        return std::string();
    }
    

    template<typename T>
    bool isElementExists(const T& element, const std::vector<T> arr)
    {
        return std::find(arr.begin(), arr.end(), element) != arr.end();
}
}