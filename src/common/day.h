#pragma once

#include <utility>
#include <string>

class Day {
public:
    virtual ~Day() = default;

    virtual void parseInput(const std::string& input) {};
    virtual std::string solvePart1() {}
    virtual std::string solvePart2() {}
};