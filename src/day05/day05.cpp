#include "day05.h"

#include <common.h>
#include <cli.h>
#include <math.h>
#include <map>

void day05(cli& c) {
    std::vector<std::string> seats = split(c.getInput("please enter your input for Day 5 (https://adventofcode.com/2020/day/5)"));

    std::map<int, std::string> ids;
    int highest_id = 0;
    for (auto seat = seats.begin(); seat != seats.end(); ++seat) {
        if(*seat == "")
            continue;
        uint8_t lower_row = 0, upper_row = 127, lower_collum = 0, upper_collum = 7;
        for (auto it = seat->begin(); it != seat->end(); ++it) {
            switch (*it) {
            case 'F':
                upper_row = floor((lower_row + upper_row)/2);
                break;
            case 'B':
                lower_row = ceil((lower_row + upper_row)/2);
                break;
            case 'R':
                lower_collum = ceil((lower_collum + upper_collum)/2);
                break;
            case 'L':
                upper_collum = floor((lower_collum + upper_collum)/2);
                break;
            }
        }
        int id = upper_row * 8 + upper_collum;
        if (id > highest_id)
            highest_id = id;
        ids[id] = *seat;
    }
    c.print("the solution to part 1 is: " + std::to_string(highest_id));

    for (auto it = ids.begin(); it != ids.end(); ++it) {
        if (ids.find(it->first+1) == ids.end()) {
            if (ids.find(it->first+2) != ids.end()) {
                c.print("the solution to part 2 is: " + std::to_string(it->first+1));
                return; // for some reason this would othwerise find another - invalid - solution.
            }
        }else if (ids.find(it->first-1) == ids.end()) {
            if (ids.find(it->first-2) != ids.end()) {
                c.print("the solution to part 2 is: " + std::to_string(it->first+1));
                return; // for some reason this would othwerise find another - invalid - solution.
            }

        }
    }
}