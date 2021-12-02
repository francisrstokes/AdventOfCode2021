#include "../common.hpp"

int main() {
  auto lines = readLines("input.txt");

  int horizontal = 0;
  int depth = 0;
  int aim = 0;

  for (auto line : lines) {
    auto parts = split(line, ' ');

    if (parts[0] == "forward") {
      auto x = std::stoi(parts[1]);
      horizontal += x;
      depth += aim * x;
    } else if (parts[0] == "down") {
      aim += std::stoi(parts[1]);
    } else if (parts[0] == "up") {
      aim -= std::stoi(parts[1]);
    }
  }

  std::cout << horizontal * depth << std::endl;

  return 0;
}
