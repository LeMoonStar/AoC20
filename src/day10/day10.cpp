#include "day10.h"

#include <common.h>
#include <cli.h>
#include <algorithm>

void day10(cli& c) {
    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 10 (https://adventofcode.com/2020/day/10)");
    std::vector<int> adapters;
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it == "") continue;
        adapters.push_back(std::stoi(*it));
    }
    std::sort(adapters.begin(), adapters.end());

    int diffOne = 0, diffThree = 0, prev = 0;
    for (auto it = adapters.begin(); it != adapters.end(); ++it) {
        c.print("now:" + std::to_string(*it) + " prev: " + std::to_string(prev));
        if (prev+1 == *it) {++diffOne; c.print("ONE");}
        if (prev+3 == *it) {++diffThree; c.print("THREE");}
        prev = *it;
    }
    diffThree++;

    c.print("the solution to part 1 is: " + std::to_string(diffOne * diffThree) + "[" + std::to_string(diffOne) + "*" + std::to_string(diffThree) + "]");

}