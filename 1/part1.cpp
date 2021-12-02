#include "../common.hpp"

int main() {
  auto lines = readLines("input.txt");

  int last = -1;
  int increaseCount = -1;
  for (auto line : lines) {
    auto num = toInt(line);
    if (num > last) {
      increaseCount++;
    }
    last = num;
  }

  std::cout << increaseCount << std::endl;

  return 0;
}
