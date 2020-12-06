#include "common.h"

#include <iostream>

std::vector<std::string> split(std::string str, const std::string& seperator) {
    std::vector<std::string> result;
    
    size_t pos;
    while ((pos = str.find(seperator)) != std::string::npos) {
        result.push_back(str.substr(0, pos));

        str.erase(0, pos+seperator.size());
    }
    result.push_back(str);

    return result;
}

std::vector<std::string> split(const std::string& str, const std::vector<std::string>& seperators) {
    std::vector<std::string> result = {str};

    for(auto seperator = seperators.begin(); seperator != seperators.end(); ++seperator) {
        std::vector<std::string> sub_result;
        for (auto section = result.begin(); section != result.end(); ++section) {
            std::vector<std::string> tmp = split(*section, *seperator);
            sub_result.insert(sub_result.end(), tmp.begin(), tmp.end());
        }
        result.clear();
        result.insert(result.end(), sub_result.begin(), sub_result.end());
    }

    return result;
}

bool isNumber(const std::string& str) {
    if (str.size() == 0)
        return false;
    for (auto it = str.begin(); it != str.end(); ++it) {
        if (!std::isdigit(*it))
            return false;
    }
    return true;
}

std::vector<char> splitToChars(const std::string& str) {
    std::vector<char> out;
    for (auto it = str.begin(); it != str.end(); ++it) {
        out.push_back(*it);
    }
    return out;
}