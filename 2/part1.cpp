#include "../common.hpp"

int main() {
  auto lines = readLines("input.txt");

  int horizontal = 0;
  int depth = 0;

  for (auto line : lines) {
    auto parts = split(line, ' ');

    if (parts[0] == "forward") {
      horizontal += std::stoi(parts[1]);
    } else if (parts[0] == "down") {
      depth += std::stoi(parts[1]);
    } else if (parts[0] == "up") {
      depth -= std::stoi(parts[1]);
    }
  }

  std::cout << horizontal * depth << std::endl;

  return 0;
}
