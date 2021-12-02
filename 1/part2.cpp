#include "../common.hpp"

int main() {
  auto lines = readLines("input.txt");

  int last = -1;
  int increaseCount = -1;
  for (size_t i = 2; i < lines.size(); i++) {
    auto a = toInt(lines[i - 2]);
    auto b = toInt(lines[i - 1]);
    auto c = toInt(lines[i - 0]);

    if ((a + b + c) > last) {
      increaseCount++;
    }
    last = a + b + c;
  }

  std::cout << increaseCount << std::endl;

  return 0;
}
