#include "day10.h"

#include <common.h>
#include <cli.h>
#include <algorithm>
#include <memory>

static cli* cl = nullptr;

class Adapter {
    int ratedJolt;
    std::vector<std::unique_ptr<Adapter>*> children;
public:
    Adapter(int ratedJolt) : ratedJolt(ratedJolt) {
    }

    inline int getRatedJolt() const {
        return ratedJolt;
    }

    bool buildtree(std::vector<std::unique_ptr<Adapter>>& adapters) {
        bool hasSolvingPath = false;
        for (auto it = adapters.begin(); it != adapters.end(); ++it) {
            if ((*it)->getRatedJolt() < ratedJolt && (*it)->getRatedJolt() >= ratedJolt-3) {
                if ((*it)->getRatedJolt() == 0) {
                    children.push_back(&(*it));
                    return true;
                }
                //cl->print(std::to_string((*it)->getRatedJolt()));
                if ((*it)->buildtree(adapters)) {
                    hasSolvingPath = true;
                    children.push_back(&(*it));
                }
            }
        }
        return hasSolvingPath;
        //cl->printLine();
    }

    unsigned long countSolutions(int depth = 0) const {
        unsigned long a = 0;
        for (auto it = children.begin(); it != children.end(); ++it) {
            if ((*(*it))->getRatedJolt() == 0) {
                ++a;
                continue;
            }
            if (depth < 18) {
                std::string a = "";
                for (int i = 0; i < depth; ++i) {
                    a += " ";
                }
                a += std::to_string((double)(it - children.begin()) / children.size() * 100) + "%";
                
                cl->print(a);
            }
            a += (*(*it))->countSolutions(depth + 1);
        }
        return a;
    } 
};

void day10(cli& c) {
    cl = &c;
    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 10 (https://adventofcode.com/2020/day/10)");
    std::vector<std::unique_ptr<Adapter>> adapters;
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it == "") continue;
        adapters.push_back(std::make_unique<Adapter>(std::stoi(*it)));
    }
    std::sort(adapters.begin(), adapters.end(), [](std::unique_ptr<Adapter>& a, std::unique_ptr<Adapter>& b) -> bool {
        return a->getRatedJolt() < b->getRatedJolt();
    });

    int diffOne = 0, diffThree = 0, prev = 0, highest = 0;
    for (auto it = adapters.begin(); it != adapters.end(); ++it) {
        if (prev+1 == (*it)->getRatedJolt()) ++diffOne;
        if (prev+3 == (*it)->getRatedJolt()) ++diffThree;
        if ((*it)->getRatedJolt() > highest) highest = (*it)->getRatedJolt();
        prev = (*it)->getRatedJolt();
    }
    diffThree++;
    c.print("the solution to part 1 is: " + std::to_string(diffOne * diffThree) + "[" + std::to_string(diffOne) + "*" + std::to_string(diffThree) + "]");

    adapters.push_back(std::make_unique<Adapter>(0));
    std::sort(adapters.begin(), adapters.end(), [](std::unique_ptr<Adapter>& a, std::unique_ptr<Adapter>& b) -> bool {
        return a->getRatedJolt() < b->getRatedJolt();
    });

    Adapter a(highest+3);
    c.print(std::to_string(a.buildtree(adapters)));
    c.print("the solution to part 2 is: " + std::to_string(a.countSolutions()));

}