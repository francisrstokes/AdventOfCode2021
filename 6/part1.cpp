#include "../common.hpp"
#include <cstdint>

using std::vector;

int main() {
  auto lines = readLines("input.txt");

  auto v = split(lines[0], ',');
  vector<uint64_t> laternfish {};
  for (auto vf : v) {
    laternfish.push_back(stoi(vf));
  }

  for (auto days = 0; days < 80; days++) {
    auto size = laternfish.size();
    for (size_t i = 0; i < size; i++) {
      if (laternfish[i] == 0) {
        laternfish[i] = 6;
        laternfish.push_back(8);
      } else {
        laternfish[i]--;
      }
    }
  }

  std::cout << laternfish.size() << std::endl;

  return 0;
}
