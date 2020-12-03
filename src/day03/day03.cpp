#include "day03.h"

#include <common.h>
#include <cli.h>

int countTrees(const std::vector<std::string>& map, int slope_x, int slope_y) {
    int w = map[0].size();
    int x = 0;
    int y = 0;
    int tree_count = 0;
    while (true) {
        x += slope_x;
        y += slope_y;

        if (y > map.size())
            break;

        if (x >= w) {
            x -=  w;
        }

        if (map[y][x] == '#') {
            tree_count++;
        }
    }

    return tree_count;
}

void day03(cli& c) {
    std::vector<std::string> map = split(c.getInput("please enter your input for Day 3 (https://adventofcode.com/2020/day/3)"));
    map.erase(map.begin()); // for some reason there is a empty line at the beginning... ugly fix, but it works

    std::vector<std::pair<int, int>> slopes  = {{1,1}, /*{3,1},*/ {5,1}, {7,1}, {1,2}};

    int part2_result = 1;

    int part1_result = countTrees(map, 3, 1);
    part2_result *= part1_result;

    c.print("the solution to part 1 is: " + std::to_string(part1_result));

    for (auto slope = slopes.begin(); slope != slopes.end(); slope++) {
        part2_result *= countTrees(map, slope->first, slope->second);
    }

    c.print("the solution to part 2 is: " + std::to_string(part2_result));

}