#include "day13.h"

#include <common.h>
#include <cli.h>
#include <math.h>
#include <thread>
#include <mutex>
#include <algorithm>

#define THREAD_COUNT std::thread::hardware_concurrency()
#define ITERATIONS_PER_THREAD 1000000L

static void bruteforcePart2Thread(const std::vector<std::pair<int, int>>& shuttles, long& nextRange, bool& exit, long& result, cli& c, const int td_num,  std::mutex& guard) {
    while (true) {
        guard.lock();
        if (exit) {
            guard.unlock();
            return;
        }
        long beginning = nextRange;
        nextRange += ITERATIONS_PER_THREAD*shuttles[0].first;
        c.print(std::to_string(td_num) + ": NEW RANGE: " + std::to_string(beginning) + " - " + std::to_string(beginning + ITERATIONS_PER_THREAD*shuttles[0].first)); // FOR DEBUG POURPOSES, SLOWS BRUTEFORCE DOWN.
        guard.unlock();

        long ending = beginning + ITERATIONS_PER_THREAD*shuttles[0].first;

        for (long current_timestamp = beginning; current_timestamp < ending; current_timestamp += shuttles[0].first) {

            bool found = true;
            for (auto it = shuttles.begin()+1; it != shuttles.end(); ++it) {
                if ( (current_timestamp + it->second -shuttles[0].second) % it->first != 0) {
                    found = false;
                    break;
                }
            }

            if (found) {
                guard.lock();
                c.print(std::to_string(td_num) + ": SOLVED: " + std::to_string(current_timestamp - shuttles[0].second));
                if (!exit || (exit && result > current_timestamp - shuttles[0].second))
                    result = current_timestamp - shuttles[0].second;
                exit = true;
                guard.unlock();
                return;
            }
        }
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

    std::sort(shuttles.rbegin(), shuttles.rend());

    std::mutex guard;
    long nextRange = ((100000000000000 + shuttles[0].first - 1) / shuttles[0].first) * shuttles[0].first, result = -1;
    bool exit = false;

    std::thread threads[THREAD_COUNT];
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i] = std::thread(bruteforcePart2Thread, std::ref(shuttles), std::ref(nextRange), std::ref(exit), std::ref(result), std::ref(c), i, std::ref(guard));
        guard.lock();
        c.print("created thread " + std::to_string(i));
        guard.unlock();
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i].join();
        guard.lock();
        c.print("thread " + std::to_string(i) + " exited.");
        guard.unlock();
    }

    c.print("the solution to part 2 is: " + std::to_string(result));

}