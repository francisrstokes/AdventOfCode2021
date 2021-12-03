#include "../common.hpp"

int main() {
  auto lines = readLines("input.txt");

  int gamma = 0;
  int epsilion = 0;

  std::vector<std::vector<char>> lineBits{};
  for (auto line : lines) {
    std::vector<char> bits(line.begin(), line.end());
    lineBits.push_back(bits);
  }

  unsigned int bitCount[12]{};
  for (auto bits : lineBits) {
    for (size_t i = 0; i < bits.size(); i++) {
      if (bits[i] == '1') {
        bitCount[i]++;
      }
    }
  }

  std::string gammaStr{};
  std::string epsilonStr{};
  for (size_t i = 0; i < 12; i++) {
    gammaStr += (bitCount[i] > lines.size() / 2) ? "1" : "0";
    epsilonStr += (bitCount[i] > lines.size() / 2) ? "0" : "1";
  }

  gamma = std::stoi(gammaStr, nullptr, 2);
  epsilion = std::stoi(epsilonStr, nullptr, 2);

  std::cout << gamma * epsilion << std::endl;

  return 0;
}
