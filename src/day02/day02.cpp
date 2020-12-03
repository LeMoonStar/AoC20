#include "day02.h"

#include <common.h>
#include <cli.h>

class PasswordPolicy {
    int min, max;
    char c;
public:
    PasswordPolicy() = default;

    PasswordPolicy(const std::string& str) {
        std::vector<std::string> v = split(str, " ");
        c = v[1][0];
        std::vector<std::string> minmax = split(v[0], "-");
        min = std::stoi(minmax[0]);
        max = std::stoi(minmax[1]);
    }
    /**
     * @brief checks if a password is valid 
     * 
     * @param str the password to be checked
     * @return true the password is valid
     * @return false the password is invalid
     */
    bool isValidPart1(const std::string& str) {
        int count = 0;
        for (auto it = str.begin(); it != str.end(); ++it) {
            if (*it == c)
                count++;
        }

        if (count >= min && count <= max)
            return true;
        return false;
    }

    bool isValidPart2(const std::string& str) {
        // -1 is not needed, cause the string begins with an space, I know, ugly solution, but does it really matter?
        return (str[min] == c) ^ (str[max] == c);
    }
};

class Password {
    PasswordPolicy policy;
    std::string password;
public:
    Password(const std::string& str) {
        std::vector<std::string> splitted = split(str, ":");
        policy = PasswordPolicy(splitted[0]);
        password = splitted[1];
    }

    bool isValidPart1() {
        return policy.isValidPart1(password);
    }
    bool isValidPart2() {
        return policy.isValidPart2(password);
    }
};

void day02(cli& c) {
    std::vector<std::string> input = split(c.getInput("please enter your input for Day 2 (https://adventofcode.com/2020/day/2)"));
    std::vector<Password> data;
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it == "")
            continue;
        data.push_back(Password(*it));
    }

    int count = 0;
    for (auto it = data.begin(); it != data.end(); ++it)
        if (it->isValidPart1())
            count++;
    
    c.print("the solution to part 1 is: " + std::to_string(count));

    count = 0;
    for (auto it = data.begin(); it != data.end(); ++it)
        if (it->isValidPart2())
            count++;
    
    c.print("the solution to part 2 is: " + std::to_string(count));

}