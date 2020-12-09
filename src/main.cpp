#define INCLUDED_BY_MAIN

#include <iostream>
#include <chrono>
#include <map>

#include <day.h>

#include <cli.h>
#include <common.h>

void executeDay(cli& c, Day* d, std::string input) {
    auto start = std::chrono::high_resolution_clock::now();
    d->parseInput(input);
    auto parse_end = std::chrono::high_resolution_clock::now();

    auto startsolve1 = std::chrono::high_resolution_clock::now();
    std::string result1 = d->solvePart1();
    auto solve1end = std::chrono::high_resolution_clock::now();

    auto startsolve2 = std::chrono::high_resolution_clock::now();
    std::string result2 = d->solvePart2();
    auto solve2end = std::chrono::high_resolution_clock::now();

    auto parse_time = std::chrono::duration_cast<std::chrono::microseconds>(parse_end - start);
    auto solve_time1 = std::chrono::duration_cast<std::chrono::microseconds>(solve1end - startsolve1);
    auto solve_time2 = std::chrono::duration_cast<std::chrono::microseconds>(solve2end - startsolve2);
    auto complete_time = std::chrono::duration_cast<std::chrono::microseconds>(solve2end - start);

    c.print("finished in " + std::to_string(complete_time.count()) + "μs ( " + std::to_string(parse_time.count()) + "μs parsing input, " + std::to_string(solve_time1.count()) + "μs solving part 1, " + std::to_string(solve_time2.count()) + "μs solving part 2 )");
    c.print("part 1 solution: " + result1);
    c.print("part 2 solution: " + result2);
}

int main() {
    std::map<int, Day*> days;

    #ifdef LAST_DAY_INIT
    LAST_DAY_INIT(days);
    #endif // LAST_DAY_INIT

    days[2] = new Day2;

    cli c;

    c.printLine();
    c.print("Advent Of Code 2020 solutions");
    c.print("By LeMoonStar");
    c.print("Licensed under the terms and conditions of the MIT license");
    c.printLine();

    c.print("The following days are avaliable to choose from:");
    std::vector<std::string> human_readable_days;
    for (auto it = days.begin(); it != days.end(); ++it) {
        human_readable_days.push_back(std::to_string(it->first));
    }
    c.printLine();
    c.printList(human_readable_days);

    while (true) {
        std::string input = c.getSingleLineInput("Please select a day by entering the corresponding number");
        if (isNumber(input)) {
            auto selected_day = days.find(std::stoi(input));
            if (selected_day != days.end()) {
                executeDay(c, selected_day->second, c.getInput("Please provide your input for the selected day."));
                continue;
            } else
                c.print("the day with the number you selected is not supported");
        } else if (input == "exit") {
            for (auto it = days.begin(); it != days.end(); ++it) {
                delete it->second;
            }
        } else
            c.print("your input is not a valid number");
    }
    
    return 0;
}