#include "../common.hpp"
#include <cstdint>
#include <numeric>

using std::vector;

static constexpr size_t NUM_DAYS = 256;

int main() {
  auto lines = readLines("input.txt");

  auto strTimers = split(lines[0], ',');
  vector<uint64_t> ages = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (auto timer : strTimers) {
    ages[stoi(timer)]++;
  }


  for (size_t days = 0; days < NUM_DAYS; days++) {
    // Keep track of the laternfish ready to give birth today
    uint64_t zeros = ages[0];

    // shift down the age counter
    for (size_t i = 1; i < ages.size(); i++) {
      ages[i - 1] = ages[i];
    }
    // Explicitly reset this counter
    ages[ages.size() - 1] = 0;

    ages[6] += zeros;
    ages[8] += zeros;
  }

  uint64_t total = std::accumulate(ages.begin(), ages.end(), 0UL);
  std::cout << total << std::endl;

  return 0;
}
