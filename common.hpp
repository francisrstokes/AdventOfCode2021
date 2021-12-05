#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <exception>

std::vector<std::string> readLines(std::string filename);
int toInt(std::string s);
std::vector<std::string> split(std::string const &str, const char delim);
std::vector<std::string> splitByWhitespace(std::string const &str);

void printVecStr(std::vector<std::string> s, std::string sep);