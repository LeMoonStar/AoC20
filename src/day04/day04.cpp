#include "day04.h"

#include <common.h>
#include <cli.h>
#include <regex>

cli* cl = nullptr;



class Id {
    std::vector<std::string> attributes;
    const std::regex byr = std::regex("^byr:(19[2-9][0-9]|200[0-2])$");
    const std::regex iyr = std::regex("^iyr:(201[0-9]|2020)$");
    const std::regex eyr = std::regex("^eyr:(202[0-9]|2030)$");
    const std::regex hgt = std::regex("^hgt:(59in|6[0-9]in|7[0-6]in|1[5-8][0-9]cm|19[0-3]cm)$");
    const std::regex hcl = std::regex("^hcl:#[a-f0-9]{6}$");
    const std::regex ecl = std::regex("^ecl:(amb|blu|brn|gry|grn|hzl|oth)$");
    const std::regex pid = std::regex("^pid:[0-9]{9}$");
public:
    Id(const std::string& str) : attributes(split(str, " ")) {
    }

    bool isValidPart1() {
        bool has_byr = false;
        bool has_iyr = false;
        bool has_eyr = false;
        bool has_hgt = false;
        bool has_hcl = false;
        bool has_ecl = false;
        bool has_pid = false;
        bool has_cid = false;

        for (auto it = attributes.begin(); it != attributes.end(); ++it) {
            if (it->substr(0, 3) == "byr") has_byr = true;
            else if (it->substr(0, 3) == "iyr") has_iyr = true;
            else if (it->substr(0, 3) == "hgt") has_hgt = true;
            else if (it->substr(0, 3) == "eyr") has_eyr = true;
            else if (it->substr(0, 3) == "hcl") has_hcl = true;
            else if (it->substr(0, 3) == "ecl") has_ecl = true;
            else if (it->substr(0, 3) == "pid") has_pid = true;
            else if (it->substr(0, 3) == "cid") has_cid = true;
        }

        
        cl->printList(attributes);
        cl->print(std::to_string(has_byr) + std::to_string(has_iyr) + std::to_string(has_eyr) + std::to_string(has_hgt) + std::to_string(has_hcl) + std::to_string(has_ecl) + std::to_string(has_pid));
        cl->printLine();

        return has_byr
            && has_iyr
            && has_eyr
            && has_hgt
            && has_hcl
            && has_ecl
            && has_pid;
    }

    bool isValidPart2() {
        bool has_byr = false;
        bool has_iyr = false;
        bool has_eyr = false;
        bool has_hgt = false;
        bool has_hcl = false;
        bool has_ecl = false;
        bool has_pid = false;
        bool has_cid = true;

        for (auto it = attributes.begin(); it != attributes.end(); ++it) {
            if (std::regex_match(*it, byr)) has_byr = true;
            if (std::regex_match(*it, iyr)) has_iyr = true;
            if (std::regex_match(*it, eyr)) has_eyr = true;
            if (std::regex_match(*it, hgt)) has_hgt = true;
            if (std::regex_match(*it, hcl)) has_hcl = true;
            if (std::regex_match(*it, ecl)) has_ecl = true;
            if (std::regex_match(*it, pid)) has_pid = true;
            //else if (it->substr(0, 3) == "cid") has_cid = true;
        }

        
        cl->printList(attributes);
        cl->print(std::to_string(has_byr) + std::to_string(has_iyr) + std::to_string(has_eyr) + std::to_string(has_hgt) + std::to_string(has_hcl) + std::to_string(has_ecl) + std::to_string(has_pid));
        cl->printLine();

        return has_byr
            && has_iyr
            && has_eyr
            && has_hgt
            && has_hcl
            && has_ecl
            && has_pid;
    }
};

void day04(cli& c) {
    cl = &c;

    std::vector<std::string> input = c.getSplittedInput("please enter your input for Day 4 (https://adventofcode.com/2020/day/4)");
    input.erase(input.begin()); // for some reason there is a empty line at the beginning... ugly fix, but it works

    std::vector<Id> ids;

    std::string currentid;
    for (auto it = input.begin(); it != input.end(); ++it) {
        if (*it == "" && currentid != ""){
            ids.push_back(currentid);
            currentid = "";
            continue;
        }
        currentid += *it + " ";
    }

    int valid_count = 0;
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        if (it->isValidPart1()) valid_count++;
    }
    c.print("the solution of part 1 is: " + std::to_string(valid_count));

    valid_count = 0;
    for (auto it = ids.begin(); it != ids.end(); ++it) {
        if (it->isValidPart2()) valid_count++;
    }
    c.print("the solution of part 2 is: " + std::to_string(valid_count));



}