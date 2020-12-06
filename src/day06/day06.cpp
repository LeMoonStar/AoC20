#include "day06.h"

#include <common.h>
#include <cli.h>

class Group {
    std::vector<char> data;
public:
    Group(const std::string& str) {
        data = splitToChars(str);
    }

    int count() {
        int count = 0;
        std::map<char, bool> found_characters;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (found_characters.find(*it) == found_characters.end()) {
                found_characters[*it] = true;
                count++;
            }
        }
        return count;
    }
};

void day06(cli& c) {
    std::vector<std::string> data = c.getSplittedInput("please enter your input for Day 6 (https://adventofcode.com/2020/day/6)");

    std::vector<Group> groups;
    std::string group_input;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == "") {
            groups.push_back(group_input);
            group_input = "";
            continue;
        }
        group_input += *it;
    }

    int count = 0;
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        count += it->count();
    }

    c.print("the solution to part 1 is: " + std::to_string(count));
}