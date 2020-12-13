#include "day13.h"

#include <common.h>
#include <cli.h>
#include <math.h>

static cli* cl;

void day13(cli& c) {
    cl = &c;

    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 13 (https://adventofcode.com/2020/day/13)");

    int timestamp = std::stoi(input[0]);
    std::vector<int> shuttles;

    std::vector<std::string> splitted_second_line = split(input[1], ",");
    for (auto it = splitted_second_line.begin(); it != splitted_second_line.end(); ++it) {
        if (*it == "x" || *it == "") continue;
        shuttles.push_back(std::stoi(*it));
    }

    std::pair<int, int> earliest_shuttle = std::make_pair(99999, 0);
    for (auto it = shuttles.begin(); it != shuttles.end(); ++it) {
        int wait_time = ( ceil((double)timestamp / (double)*it) * *it)  - timestamp;
        if (earliest_shuttle.first > wait_time) {
            earliest_shuttle.first = wait_time;
            earliest_shuttle.second = *it;
        }
    }

    c.print("the solution to part 1 is: " + std::to_string(earliest_shuttle.first * earliest_shuttle.second));

}