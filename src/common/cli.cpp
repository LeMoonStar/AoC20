#include "cli.h"

#include <iostream>
#include "common.h"

cli::cli(int width) : width(width), cursorPos(0) {
}

void cli::print(const std::string& str) {
    // split string at newlines and loop trough lines
    std::vector<std::string> lines = split(str);
    for (auto line = lines.begin(); line != lines.end(); ++line) {
        if (cursorPos == 0) {
            std::cout << "# ";
            cursorPos = 2;
        }

        // check if string fits into the box
        if (line->size()+cursorPos < width) {
            std::cout << *line;
            cursorPos += line->size();
            // fill width with spaces and close box with a #
            while (cursorPos <= width-1) {
                std::cout << " ";
                ++cursorPos;
            }
            std::cout << "#" << std::endl;

            cursorPos = 0;
        } else {
            // split string into multiple lines
            size_t pos;
            if ((pos = line->rfind(" ", width-cursorPos)) != std::string::npos) {
                // could split string at the end of a word
                print(line->substr(0, pos));
                print(line->substr(pos+1, line->size()));
            } else {
                // need to split string in the middle of a word
                print(line->substr(0, width-cursorPos-2) + "-");
                print(line->substr(width-4, line->size()));
            }
        }

    }
}


void cli::printList(std::vector<std::string> list) {
    // get size of longest string
    int size_per_item = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (size_per_item < it->size())
            size_per_item = it->size();
    }

    size_per_item += 1;

    for (auto it = list.begin(); it != list.end(); ++it) {
        if (cursorPos == 0) {
            std::cout << "# ";
            cursorPos = 2;
        }
        if (cursorPos + size_per_item < width) {
            while (it->size() < size_per_item)
                (*it) += ' ';
            std::cout << *it;
            cursorPos += size_per_item;
            
        } else {
            // fill width with spaces and close box with a #
            while (cursorPos <= width-1) {
                std::cout << " ";
                ++cursorPos;
            }
            std::cout << "#" << std::endl;

            cursorPos = 0;
            --it;
        }
    }
    while (cursorPos <= width-1) {
                std::cout << " ";
                ++cursorPos;
            }
            std::cout << "#" << std::endl;

            cursorPos = 0;
}

std::string cli::getInput(const std::string& desc) {
    print(desc);
    print("press * and Enter to confirm the input");
    printLine();
    std::cout << ">";
    std::string input;
    char ch;
    while((ch = getchar()) != EOF) {
        if (ch == '*')
            break;

        input += ch;
    }
    printLine();
    return input;
}

std::string cli::getSingleLineInput(const std::string& desc) {
    print(desc);
    print("Enter ONE line, confirm with Enter");
    printLine();
    std::cout << ">";
    std::string input;
    std::cin >> input;
    printLine();
    return input;
}

std::vector<std::string> cli::getSplittedInput(const std::string& desc) {
    print(desc);
    print("press * and Enter to confirm the input");
    printLine();
    std::cout << ">";
    std::vector<std::string> input = {""};
    char ch;
    while((ch = getchar()) != EOF) {
        if (ch == '*')
            break;
        if (ch == '\n') {
            input.push_back("");
            continue;
        }
        if (ch == '\r')
            continue;

        input[input.size() -1] += ch;
    }
    printLine();
    return input;
}

void cli::printLine() {
    while (cursorPos <= width) {
        std::cout << "#";
        ++cursorPos;
    }
    std::cout << std::endl;
    cursorPos = 0;
}