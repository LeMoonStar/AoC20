#include "day09.h"

#include <common.h>
#include <cli.h>

void day09(cli& c) {
    std::vector<std::string> raw_data = c.getSplittedInput("please enter your input for Day 9 (https://adventofcode.com/2020/day/9)");
    std::vector<unsigned long> data;
    for (auto it = raw_data.begin(); it != raw_data.end(); ++it) {
        if (*it == "") continue;
        c.print(*it);
        data.push_back(std::stoul(*it));
    }

    for (auto num = data.begin()+25; num != data.end(); ++num) {
        bool found = false;
        for (auto it = num-25; it != num-1; ++it) {
            for (auto it2 = num-24; it2 != num; ++it2) {
                //c.print(std::to_string(*it) + "+" + std::to_string(*it2) + " = " + std::to_string(*it + *it2) + ((*it + *it2 == *num)? "TRUE":"FALSE"));
                if (*it + *it2 == *num) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            c.print("the solution to part 1 is: " + std::to_string(*num));
            break;
        }
    }
}