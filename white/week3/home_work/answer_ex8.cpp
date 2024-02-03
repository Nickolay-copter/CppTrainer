#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include <map>
#include <set>

struct Incognizable {
    int x = 0;
    int y = 0;
};

int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
