#pragma once

#include <map>
#include <cli.h>

/**
 * @brief executes the CLI for day 1
 * 
 */
void day07(cli& c);

#ifdef INCLUDED_BY_MAIN

/**
 * @brief if defined, calls the previous day_init function, and adds day to map
 * 
 * @param days the day map, containing day number and function
 */
void day07_init(std::map<int, void(*)(cli&)>& days) {
    #if defined(LAST_DAY_INIT)
    LAST_DAY_INIT(days);
    #undef LAST_DAY_INIT
    #endif // LAST_DAY_INIT
    #define LAST_DAY_INIT(days) day07_init(days)
    days[7] = day07;
}

#endif // INCLUDED_BY_MAIN