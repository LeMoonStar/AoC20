#pragma once

#include <string>
#include <vector>

/**
 * @brief a function to split a string into multiple sub-strings using one seperator
 * 
 * @param str the original string to be split
 * @param seperator the sequence of characters the string (str) should be split at
 * @return std::vector<std::string> all sub-strings
 */
std::vector<std::string> split(std::string str, const std::string& seperator);

/**
 * @brief a function to split a string into multiple sub-strings using multiple seperators
 * 
 * @param str the original string to be split
 * @param seperators a vector of all character sequences the string should be split at; defaults to newline(n r nr rn)
 * @return std::vector<std::string> all sub-strings
 */
std::vector<std::string> split(const std::string& str, const std::vector<std::string>& seperators = {"\n", "\r", "\n\r", "\r\n"});

/**
 * @brief checks if the string only contains digits 
 * 
 * @param str the string to be checked
 * @return true the string contains only digits
 * @return false the string contains other characters too OR the string is empty
 */
bool isNumber(const std::string& str);

/**
 * @brief splits a string into it's chars
 * 
 * @param str the string to be splitted
 * @param ignore_list a vector of chars to be ignored
 * @return std::vector<char> a vector of the characters from the string
 */
std::vector<char> splitToChars(const std::string& str, const std::vector<char>& ignore_list = {' ', '\n', '\r'});