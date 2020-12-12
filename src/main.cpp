#define INCLUDED_BY_MAIN

#include <iostream>

#include <day01.h>
#include <day02.h>
#include <day03.h>
#include <day04.h>
#include <day05.h>
#include <day06.h>
#include <day07.h>
#include <day08.h>
#include <day09.h>
#include <day10.h>
#include <day11.h>
#include <day12.h>

#include <cli.h>
#include <common.h>

int main() {
    std::map<int, void(*)(cli&)> days;

    #ifdef LAST_DAY_INIT
    LAST_DAY_INIT(days);
    #endif // LAST_DAY_INIT

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
            std::map<int, void(*)(cli&)>::iterator selected_day = days.find(std::stoi(input));
            if (selected_day != days.end()) {
                selected_day->second(c);
                return 0;
            } else
                c.print("the day with the number you selected is not supported");
        } else
            c.print("your input is not a valid number");
    }
    
    return 0;
}