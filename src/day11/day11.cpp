#include "day11.h"

#include <common.h>
#include <cli.h>
#include <algorithm>

static cli* cl;

enum Spot {
    FLOOR,
    SEAT,
    OCCUPIED ,
    UNKNOWN
};

// Thanks https://stackoverflow.com/questions/8473009/how-to-efficiently-compare-two-maps-of-strings-in-c-only-for-a-subset-of-the-k
template <typename Map>
static bool map_compare(Map const &lhs, Map const &rhs) {
    // No predicate needed because there is operator== for pairs already.
    return lhs.size() == rhs.size()
        && std::equal(lhs.begin(), lhs.end(),
                      rhs.begin());
}

static inline Spot getSpotFromChar(char c) {
    if (c == '.') return Spot::FLOOR;
    if (c == 'L') return Spot::SEAT;
    if (c == '#') return Spot::OCCUPIED;
    return Spot::UNKNOWN;
}

static inline char getCharFromSpot(Spot s) {
    if (s == Spot::FLOOR) return '.';
    if (s == Spot::SEAT) return 'L';
    if (s == Spot::OCCUPIED) return '#';
    return '-';
}

template <typename Map, typename T>
static inline int count_occurences(const Map& m, const T& v) {
    int i = 0;
    for (auto it = m.begin(); it != m.end(); ++it) {
        if (it->second == v) ++i;
    }
    return i;
}

static std::map<std::pair<int, int>, Spot> evolvePart1(std::map<std::pair<int, int>, Spot>& spots, int width, int height) {
    std::map<std::pair<int, int>, int> neighbours;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int i = 0;
            if (spots[std::make_pair(x-1, y)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x, y-1)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x-1, y-1)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x+1, y)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x, y+1)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x+1, y+1)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x-1, y+1)] == Spot::OCCUPIED) ++i;
            if (spots[std::make_pair(x+1, y-1)] == Spot::OCCUPIED) ++i;

            neighbours[std::make_pair(x, y)] = i;
        }
    }

    std::map<std::pair<int, int>, Spot> evolved = spots;
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (spots[std::make_pair(x,y)] == Spot::OCCUPIED && neighbours[std::make_pair(x,y)] >= 4) {
                evolved[std::make_pair(x,y)] = Spot::SEAT;
                continue;
            }
            if (spots[std::make_pair(x,y)] == Spot::SEAT && neighbours[std::make_pair(x,y)] == 0) {
                evolved[std::make_pair(x,y)] = Spot::OCCUPIED;
                continue;
            }
        }
    }

    return evolved;

};

static inline bool lookInDirection(std::map<std::pair<int, int>, Spot>& spots, int width, int height, int x, int y, int dirx, int diry) {
    while (true) {
        x += dirx;
        y += diry;

        if (x < 0 || x >= width) break;
        if (y < 0 || y >= height) break;

        if (spots[std::make_pair(x,y)] == Spot::OCCUPIED) return true;
        if (spots[std::make_pair(x,y)] == Spot::SEAT) return false;
    }
    return false;
}

static std::map<std::pair<int, int>, Spot> evolvePart2(std::map<std::pair<int, int>, Spot>& spots, int width, int height) {
    std::map<std::pair<int, int>, int> neighbours;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int i = 0;
            if (lookInDirection(spots, width, height, x, y, 1, 0)) ++i;
            if (lookInDirection(spots, width, height, x, y, 0, 1)) ++i;
            if (lookInDirection(spots, width, height, x, y, 1, 1)) ++i;
            if (lookInDirection(spots, width, height, x, y, -1, 0)) ++i;
            if (lookInDirection(spots, width, height, x, y, 0, -1)) ++i;
            if (lookInDirection(spots, width, height, x, y, -1, -1)) ++i;
            if (lookInDirection(spots, width, height, x, y, 1, -1)) ++i;
            if (lookInDirection(spots, width, height, x, y, -1, 1)) ++i;

            neighbours[std::make_pair(x, y)] = i;
        }
    }

    std::map<std::pair<int, int>, Spot> evolved = spots;
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (spots[std::make_pair(x,y)] == Spot::OCCUPIED && neighbours[std::make_pair(x,y)] >= 5) {
                evolved[std::make_pair(x,y)] = Spot::SEAT;
                continue;
            }
            if (spots[std::make_pair(x,y)] == Spot::SEAT && neighbours[std::make_pair(x,y)] == 0) {
                evolved[std::make_pair(x,y)] = Spot::OCCUPIED;
                continue;
            }
        }
    }

    return evolved;

};

void day11(cli& c) {
    cl = &c;
    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 11 (https://adventofcode.com/2020/day/11)");

    std::map<std::pair<int, int>, Spot> originalSpots;
    int height = 0, width = 0;
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it == "") continue;
        width = 0;
        for (auto c = it->begin(); c != it->end(); ++c) {
            originalSpots[std::make_pair(width, height)] = getSpotFromChar(*c);
            ++width;
        }
        ++height;
    }

    std::map<std::pair<int, int>, Spot> spots = originalSpots;
    while (true) {
        auto newSpots = evolvePart1(spots, width, height);
        if (map_compare(newSpots, spots)) {
            break;
        }
        spots = newSpots;
    }

    c.print("the solution to part 1 is: " + std::to_string(count_occurences(spots, Spot::OCCUPIED)));

    spots = originalSpots;
    while (true) {
        auto newSpots = evolvePart2(spots, width, height);
        if (map_compare(newSpots, spots)) {
            break;
        }
        spots = newSpots;
    }

    c.print("the solution to part 2 is: " + std::to_string(count_occurences(spots, Spot::OCCUPIED)));
    
}