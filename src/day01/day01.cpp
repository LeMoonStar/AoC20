#include "day01.h"

#include <common.h>
#include <cli.h>
#include <iostream>

void day01(cli& c) {


    std::vector<std::string> input = split(c.getInput("please enter your input for Day 1 (https://adventofcode.com/2020/day/1)"));

    // convert input to integers
    std::vector<int> parsed_input;
    for(auto it = input.begin(); it != input.end(); ++it) {
        int tmp = std::atoi(it->c_str());
        if (tmp != 0)   // this is a bad solution to the problem... oh well
            parsed_input.push_back(tmp);
    }

    // solve part 1
    bool finished = false;
    for (auto it1 = parsed_input.begin(); it1 != parsed_input.end() && !finished; ++it1) {
        for (auto it2 = it1+1; it2 != parsed_input.end() && !finished; ++it2) {
            if (*it1 + *it2 == 2020) {
                c.print("the solution of part 1 is " + std::to_string(*it1 * *it2));
                finished = true;
            }
        }
    }

    // solve part 2
    finished = false;
    for (auto it1 = parsed_input.begin(); it1 != parsed_input.end() && !finished; ++it1) {
        for (auto it2 = it1+1; it2 != parsed_input.end() && !finished; ++it2) {
            for (auto it3 = it2+1; it3 != parsed_input.end() && !finished; ++it3) {
                if (*it1 + *it2 + *it3 == 2020) {
                    c.print("the solution of part 2 is " + std::to_string(*it1 * *it2 * *it3));
                    finished = true;
                }
            }
        }
    }
}