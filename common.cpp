#include "common.hpp"

std::vector<std::string> readLines(std::string filename) {
  std::ifstream contents(filename);

  if(!contents) {
    throw std::runtime_error("Cannot open file: " + filename);
  }

  std::string line;
  std::vector<std::string> vec;

  while (std::getline(contents, line)) {
    vec.push_back(line);
  }

  return vec;
}

int toInt(std::string s) {
  std::stringstream ss{s};
  int numberOut{};
  ss >> numberOut;
  return numberOut;
}

std::vector<std::string> split(std::string const &str, const char delim) {
  std::stringstream ss(str);
  std::vector<std::string> out{};

  std::string s{};
  while (std::getline(ss, s, delim)) {
      out.push_back(s);
  }

  return out;
}
