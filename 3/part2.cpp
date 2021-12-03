#include "../common.hpp"
#include <cmath>

int getMostCommonBit(const std::vector<std::string> &binStrings, size_t index) {
  unsigned int halfLines = round(binStrings.size() / 2.0);
  unsigned int bitCount = 0;

  for (auto binString : binStrings) {
    if (binString[index] == '1') {
      bitCount++;
    }
  }

  if (bitCount == halfLines) {
    return -1;
  } else if (bitCount > halfLines) {
    return 1;
  }
  return 0;
};

int main() {
  auto lines = readLines("input.txt");
  size_t NUM_BITS = lines[0].size();

  std::vector<std::vector<char>> lineBits{};
  for (auto line : lines) {
    std::vector<char> bits(line.begin(), line.end());
    lineBits.push_back(bits);
  }

  std::vector<std::string> oxygenVec{lines.begin(), lines.end()};
  std::vector<std::string> working{};
  std::vector<std::string> c02Vec{lines.begin(), lines.end()};

  for (size_t i = 0; i < NUM_BITS; i++) {
    if (oxygenVec.size() <= 1) break;

    auto mostCommonBit = getMostCommonBit(oxygenVec, i);

    for (auto bitLine : oxygenVec) {
      if (
         ( (mostCommonBit == 1 && bitLine[i] == '1')
        || (mostCommonBit == 0 && bitLine[i] == '0')
        || (mostCommonBit == -1 && bitLine[i] == '1'))
      ) {
        working.push_back(bitLine);
      }
    }

    oxygenVec = working;
    working.clear();
  }

  for (size_t i = 0; i < NUM_BITS; i++) {
    if (c02Vec.size() <= 1) break;

    auto mostCommonBit = getMostCommonBit(c02Vec, i);

    for (auto bitLine : c02Vec) {
      if (
         ( (mostCommonBit == 1 && bitLine[i] == '0')
        || (mostCommonBit == 0 && bitLine[i] == '1')
        || (mostCommonBit == -1 && bitLine[i] == '0'))
      ) {
        working.push_back(bitLine);
      }
    }

    c02Vec = working;
    working.clear();
  }

  int oxygenRating = std::stoi(oxygenVec[0], nullptr, 2);
  int c02Scrubber = std::stoi(c02Vec[0], nullptr, 2);;

  std::cout << oxygenRating * c02Scrubber << std::endl;

  return 0;
}
