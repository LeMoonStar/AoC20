#pragma once

#include <string>
#include <vector>

class cli {
    int width;
    int cursorPos;
public:
    /**
     * @brief Construct a new cli object
     * 
     * @param width 
     */
    cli(int width = 65);

    /**
     * @brief a function to print text inside the cli box
     * 
     * @param str the string to be printed
     */
    void print(const std::string& str);
    /**
     * @brief a function to print nicely formatted lists
     * 
     * @param list the list to be printed
     */
    void printList(std::vector<std::string> list);

    /**
     * @brief get multiline Input from the user
     * 
     * @param desc a description to be shown to the user
     * @return std::string the text inputted by the user
     */
    std::string getInput(const std::string& desc);
    /**
     * @brief get a single line of input from  the user
     * 
     * @param desc a description to be shown to the user
     * @return std::string the text inputted by the user
     */
    std::string getSingleLineInput(const std::string& desc);

    /**
     * @brief get Input from the user splitted by lines.
     *        Unlike split(cli::getInput("desc")) DOES include empty lines.
     * 
     * @param desc a description to be shown to the user
     * @return std::vector<std::string> a vector of the lines inputted by the user
     */
    std::vector<std::string> getSplittedInput(const std::string& desc);

    /**
     * @brief draw a seperator line
     * 
     */
    void printLine();
};