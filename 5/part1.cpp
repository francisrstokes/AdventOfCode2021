#include "../common.hpp"
#include <map>
#include <cstdint>

using std::vector;

struct Point2d {
  int x;
  int y;

  Point2d() : x{}, y{} {};
  Point2d(int _x, int _y) : x{_x}, y{_y} {};
  Point2d(std::string _x, std::string _y) : x{stoi(_x)}, y{stoi(_y)} {};

  std::string getCoordinateKey() {
    return std::to_string(x) + "," + std::to_string(y);
  }
};

struct PointPair {
  Point2d p1;
  Point2d p2;

  PointPair(Point2d _p1, Point2d _p2) : p1{_p1}, p2{_p2} {};

  bool isHorizontalLine() { return p1.y == p2.y; }
  bool isVerticalLine() { return p1.x == p2.x; }

  vector<Point2d> getHorizontalPoints() {
    vector<Point2d> out {};
    for (auto ix = std::min(p1.x, p2.x); ix <= std::max(p1.x, p2.x); ix++) {
      out.push_back({ix, p1.y});
    }
    return out;
  }

  vector<Point2d> getVerticalPoints() {
    vector<Point2d> out {};
    for (auto iy = std::min(p1.y, p2.y); iy <= std::max(p1.y, p2.y); iy++) {
      out.push_back({p1.x, iy});
    }
    return out;
  }
};

int main() {
  auto lines = readLines("input.txt");
  vector<PointPair> pointPairs {};
  std::map<std::string, uint64_t> pointsCovered {};

  // Lines -> PointPairs
  for (auto line : lines) {
    auto rawPoints = split(line, " -> ");
    auto p1 = split(rawPoints[0], ',');
    auto p2 = split(rawPoints[1], ',');
    PointPair p {
      Point2d {p1[0], p1[1]},
      Point2d {p2[0], p2[1]}
    };
    pointPairs.push_back(p);
  }


  for (auto pointPair : pointPairs) {
    if (pointPair.isHorizontalLine()) {
      auto points = pointPair.getHorizontalPoints();
      for (auto point : points) {
        auto key = point.getCoordinateKey();
        if (pointsCovered.count(key)) {
          pointsCovered[key]++;
        } else {
          pointsCovered[key] = 1;
        }
      }
    } else if (pointPair.isVerticalLine()) {
      auto points = pointPair.getVerticalPoints();
      for (auto point : points) {
        auto key = point.getCoordinateKey();
        if (pointsCovered.count(key)) {
          pointsCovered[key]++;
        } else {
          pointsCovered[key] = 1;
        }
      }
    }
  }

  // for (auto x : pointsCovered) {
  //   std::cout << x.first << ": " << x.second << '\n';
  // }
  // std::cout << std::flush;

  int moreThan2 {};
  for (auto x : pointsCovered) {
    if (x.second >= 2) {
      moreThan2++;
    }
  }

  std::cout << moreThan2 << std::endl;
  return 0;
}
