#include "day06.h"

#include <common.h>
#include <cli.h>

class Group {
    const std::vector<std::string> data;
public:
    Group(const std::string& str) : data(split(str)) {
    }

    int countPart1() {
        int count = 0;
        std::map<char, bool> found_characters;
        for (auto it = data.begin(); it != data.end(); ++it)
            for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
                if (found_characters.find(*it2) == found_characters.end()) {
                    found_characters[*it2] = true;
                    count++;
                }
            }
        return count;
    }

    int countPart2() {
        int count = 0;
        int person_count = data.size()-1;
        std::map<char, int> found_characters;

        for (auto it = data.begin(); it != data.end(); ++it)
            for (auto it2 = it->begin(); it2 != it->end(); ++it2) {
                if (*it2 != '\n' && *it2 != '\r')
                    found_characters[*it2]++;
            }
        for (auto it = found_characters.begin(); it != found_characters.end(); ++it) {
            if (it->second == person_count)
                count++;
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
        group_input +=  *it + "\n";
    }

    int count = 0;
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        count += it->countPart1();
    }

    c.print("the solution to part 1 is: " + std::to_string(count));

    count = 0;
    for (auto it = groups.begin(); it != groups.end(); ++it) {
        count += it->countPart2();
    }

    c.print("the solution to part 2 is: " + std::to_string(count));
}