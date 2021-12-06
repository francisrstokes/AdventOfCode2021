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

std::vector<std::string> split(std::string const &str, std::string const delim) {
  std::string s {str};
  std::vector<std::string> out {};

  auto start = 0U;
  auto end = s.find(delim);
  while (end != std::string::npos) {
    out.push_back(s.substr(start, end - start));
    start = end + delim.length();
    end = s.find(delim, start);
  }

  if (start < s.size() - 1) {
    out.push_back(s.substr(start, end - start));
  }

  return out;
}

std::vector<std::string> splitByWhitespace(std::string const &str) {
  std::stringstream ss(str);
  std::vector<std::string> out{};

  std::string s{};
  while (std::getline(ss, s, ' ')) {
    if (s.length() > 0) {
      out.push_back(s);
    }
  }

  return out;
}

void printVecStr(std::vector<std::string> s, std::string sep) {
  for (auto x: s) {
    std::cout << x << sep;
  }
  std::cout << std::endl;
}
