#include "day13.h"

#include <common.h>
#include <cli.h>
#include <math.h>

static cli* cl;

void day13(cli& c) {
    cl = &c;

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
    for (long i = 100000000000000;;++i) {
        if (i%10000000000 == 0)
            c.print("still BRUTEFORCING (current timestamp " + std::to_string(i) + ")...");
        
        bool found = true;
        long wanted_timestamp = i*shuttles[0].first;
        for (auto it = shuttles.begin()+1; it != shuttles.end(); ++it) {
            //c.print("checking " + std::to_string(it->first) + " at pos " + std::to_string(it->second));
            if ( (wanted_timestamp + it->second) % it->first != 0) {
                found = false;
                break;
            }
            //c.print(std::to_string(it->first) + " matches timestamp " + std::to_string(wanted_timestamp) + "(+" + std::to_string(it->second) + ")");
        }

        if (found) {
            c.print("the solution to part 2 is: " + std::to_string(wanted_timestamp));
            return;
        }
        
    }
}