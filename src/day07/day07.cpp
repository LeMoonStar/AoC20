#include "day07.h"

#include <common.h>
#include <cli.h>

cli* cl = nullptr;

class Bag {
    std::string name;
    std::map<Bag*, int> contents;
    std::vector<Bag*> contained_by;

    inline void addParent(Bag* b) {
        contained_by.push_back(b);
    }

public:
    Bag() = default;

    Bag(const std::string& str) {
        name = str;
    }

    void link(std::map<std::string, Bag*>& bags, const std::string& datastr) {
        std::vector<std::string> data = split(datastr.substr(0, datastr.size()-1), std::vector<std::string>({", ", "."}));

        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == "no other bags")
                continue;
            int count = std::stoi(it->substr(0,1));
            Bag* bag = bags[it->substr(2, it->find(" bag")-2)];
            if (!bag) {cl->print("ERROR"); continue; }
            addChild(bag, count);
        }
    }

    void addChild(Bag* b, int count) {
        contents[b] = count;
        b->addParent(this);
    }

    inline int bagCount() {
        int c = 0;
        for (auto it = contents.begin(); it != contents.end(); ++it) {
            c += it->second * (it->first->bagCount() +1);
        }
        return c;
    }

    inline bool contains(Bag* b) {
        for (auto it = contents.begin(); it != contents.end(); ++it) {
            if (it->first == b)   //directly contains searched bag
                return true;
            
            if (it->first->contains(b)) // child contains bag
                return true;
        }
        return false;
    }
};

void day07(cli& c) {
    cl = &c;
    std::vector<std::string> data = split(c.getInput("please enter your input for Day 7 (https://adventofcode.com/2020/day/7)"));

    std::map<std::string, Bag*> bags;

    // creating bags
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == "")
            continue;
        std::size_t pos = it->find(" bags");
        std::string name = it->substr(0, pos);
        bags[name] = new Bag(name);
    }

    // linking bags together
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == "")
            continue;
        std::size_t pos = it->find(" bags");
        std::string name = it->substr(0, pos);
        bags[name]->link(bags, it->substr(pos+14));
    }

    int count = 0;
    for (auto it = bags.begin(); it != bags.end(); ++it) {
        if (it->second->contains(bags["shiny gold"])) count++;
    }
    c.print("the solution of part 1 is: "  + std::to_string(count));
    c.print("the solution of part 2 is: "  + std::to_string(bags["shiny gold"]->bagCount()));

    // clean
    for (auto it = bags.begin(); it != bags.end(); ++it) {
        delete it->second;
    }
}