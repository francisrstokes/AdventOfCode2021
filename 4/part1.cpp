#include "../common.hpp"

using std::vector;

struct Board {
  vector<vector<std::string>> rows{};
  vector<vector<bool>> markers{
    {false, false, false, false, false},
    {false, false, false, false, false},
    {false, false, false, false, false},
    {false, false, false, false, false},
    {false, false, false, false, false},
  };

  vector<std::string>::iterator parseBoard(const vector<std::string> &lines, vector<std::string>::iterator iter) {
    for (; iter != lines.end(); ++iter) {
      auto line = *iter;
      if (*iter != "") {
        rows.push_back(splitByWhitespace(line));
        if (rows.size() == 5)
          break;
      }
    }
    return iter + 1;
  }

  vector<bool> getRow(size_t index) {
    return markers[index];
  }

  vector<bool> getColumn(size_t index) {
    vector<bool> col{};
    for (auto row : markers) {
      col.push_back(row[index]);
    }
    return col;
  }

  void print() {
    for (size_t y = 0; y < rows.size(); y++) {
      for (size_t x = 0; x < rows.size(); x++) {
        std::cout << rows[y][x] << '{' << (markers[y][x] ? 'T' : 'F') << '}' << ',';
      }
      std::cout << '\n';
    }
    std::cout << std::endl;
  }

  bool markAndCheckForWin(std::string call) {
    for (size_t y = 0; y < rows.size(); y++) {
      for (size_t x = 0; x < rows.size(); x++) {
        if (rows[y][x] == call) {
          markers[y][x] = true;
          return checkForWin();
        }
      }
    }
    return false;
  }

  bool checkForWin() {
    for (size_t i = 0; i < rows.size(); i++) {
      auto col = getColumn(i);
      if (col[0] && col[1] && col[2] && col[3] && col[4]) {
        return true;
      }
      auto row = getRow(i);
      if (row[0] && row[1] && row[2] && row[3] && row[4]) {
        return true;
      }
    }
    return false;
  }

  unsigned int getScore() {
    unsigned int score {0};
    for (size_t y = 0; y < rows.size(); y++) {
      for (size_t x = 0; x < rows.size(); x++) {
        if (!markers[y][x]) {
          score += stoi(rows[y][x]);
        }
      }
    }
    return score;
  }
};

int main() {
  auto lines = readLines("input.txt");

  vector<std::string> calls{split(lines[0], ',')};

  auto iter = lines.begin() + 1;
  vector<Board> boards{};

  while (iter != lines.end()) {
    Board b{};
    iter = b.parseBoard(lines, iter);
    boards.push_back(b);
  }

  for (auto call : calls) {
    for (auto &b: boards) {
      if (b.markAndCheckForWin(call)) {
        b.print();
        std::cout << stoi(call) << std::endl;
        unsigned int callValue = stoi(call);
        std::cout << callValue * b.getScore() << std::endl;
        return 0;
      }
    }
  }

  std::cout << "No win found" << std::endl;
  return 0;
}
