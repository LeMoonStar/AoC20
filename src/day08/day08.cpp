#include "day08.h"

#include <common.h>
#include <cli.h>
#include <utility>

enum Instructions {
    NOP = 0,
    JMP,
    ACC
};

Instructions getInstructionFromString(const std::string& str) {
    if (str == "nop") return Instructions::NOP;
    else if (str == "jmp") return Instructions::JMP;
    else if (str == "acc") return Instructions::ACC;

    return Instructions::NOP;
}

std::string getInstructionDescription(Instructions i) {
    switch (i) {
    case Instructions::NOP:
        return "NOP";
        break;
    case Instructions::JMP:
        return "JMP";
        break;
    case Instructions::ACC:
        return "ACC";
        break;
    default:
        return "---";
    }
}

struct Instruction {
    Instructions i;
    int arg;

    Instruction() = default;
    Instruction(Instructions i, int arg) : i(i), arg(arg) {
    }

    Instruction(const std::string& str) {
        i = getInstructionFromString(str.substr(0, 3));
        arg = std::stoi(str.substr(4, str.size()-4));
    }

    std::string describe() const {
        return getInstructionDescription(i) + " " + std::to_string(arg);
    }
};

class Program {
    std::vector<Instruction> instructions;

public:
    Program(const std::string& str) {
        std::vector<std::string> splitted = split(str);
        for (auto it = splitted.begin(); it != splitted.end(); ++it) {
            if (*it != "")
                instructions.push_back(Instruction(*it));
        }
    }

    void describe(cli& c) const {
        for (auto it = instructions.begin(); it != instructions.end(); ++it) {
            c.print(it->describe());
        }
    }

    std::pair<int, bool> execute(cli& c) {
        std::map<int, Instruction> map;
        return execute(c, map);
    }

    std::pair<int, bool> execute(cli& c, std::map<int, Instruction>& overwrites) const {
        int i = 0, acc = 0;
        std::map<int, int> calls;
        while (true) {
            if (i > instructions.size()) return std::make_pair(acc, true);
            if(calls[i] >= 1) return std::make_pair(acc, false);

            Instruction inst;
            if (overwrites.find(i) != overwrites.end())
                inst = overwrites[i];
            else
                inst = instructions[i];

            calls[i]++;
            switch (inst.i) {
            case Instructions::NOP:
                i++;
                continue;
            case Instructions::JMP:
                i += inst.arg;
                continue;
            case Instructions::ACC:
                acc += inst.arg;
                i++;
                continue;
            }
        }
    }

    int part2(cli& c) {
        for (int i = 0; i < instructions.size(); ++i) {
            std::map<int, Instruction> overwrites;
            std::pair<int, bool> ret;

            switch (instructions[i].i) {
            case Instructions::JMP:
                overwrites = {{i,Instruction(Instructions::NOP, instructions[i].arg)}};
                ret = execute(c, overwrites);
                if (ret.second) {
                    return ret.first;
                }
                break;
            case Instructions::NOP:
                overwrites = {{i,Instruction(Instructions::JMP, instructions[i].arg)}};
                ret = execute(c, overwrites);
                if (ret.second) {
                    return ret.first;
                }
                break;
            default:
                continue;
            }
        }
        return -1;
    }
};

void day08(cli& c) {
    std::string data = c.getInput("please enter your input for Day 8 (https://adventofcode.com/2020/day/8)");
    Program p = Program(data);
    c.print("the solution to part 1 is: " + std::to_string(p.execute(c).first));
    c.print("the solution to part 2 is: " + std::to_string(p.part2(c)));
}