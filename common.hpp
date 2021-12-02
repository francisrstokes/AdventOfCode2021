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