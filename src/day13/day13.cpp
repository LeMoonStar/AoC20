#include "day13.h"

#include <common.h>
#include <cli.h>
#include <math.h>

static long bruteforcePart2Range(const long beginning, const long ending, const std::vector<std::pair<int, int>>& shuttles) {
    for (long current_timestamp = beginning;; current_timestamp += shuttles[0].first) {
        if (ending != -1 && current_timestamp > ending) return -1;
        
        bool found = true;
        for (auto it = shuttles.begin()+1; it != shuttles.end(); ++it) {
            if ( (current_timestamp + it->second) % it->first != 0) {
                found = false;
                break;
            }
        }

        if (found)
            return current_timestamp;
    }
}

void day13(cli& c) {
    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 13 (https://adventofcode.com/2020/day/13)");

    int timestamp = std::stoi(input[0]);
    std::vector<std::pair<int, int>> shuttles;

    std::vector<std::string> splitted_second_line = split(input[1], ",");
    int i = -1;
    for (auto it = splitted_second_line.begin(); it != splitted_second_line.end(); ++it) {
        i++;
        if (*it == "x" || *it == "") continue;
        shuttles.push_back(std::make_pair(std::stoi(*it), i));
        
    }

    std::pair<int, int> earliest_shuttle = std::make_pair(99999, 0);
    for (auto it = shuttles.begin(); it != shuttles.end(); ++it) {
        int wait_time = ( ceil((double)timestamp / (double)it->first) * it->first)  - timestamp;
        if (earliest_shuttle.first > wait_time) {
            earliest_shuttle.first = wait_time;
            earliest_shuttle.second = it->first;
        }
    }

    c.print("the solution to part 1 is: " + std::to_string(earliest_shuttle.first * earliest_shuttle.second));


    c.print("BRUTEFORCING Part 2....");
    c.print("the solution to part 2 is: " + std::to_string(bruteforcePart2Range(100000000000000, -1, shuttles)));
}