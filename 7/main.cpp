// Solution passes all tests with 0ms runtime (meets or beats 100.00% of
// competitors) and 8.54MB memory (meets or beats 54.03% of competitors)
#include <limits>;

class Solution {
public:
  int reverse(int x) {
    bool neg = x < 0;
    int val = 0;
    int max = std::numeric_limits<int>::max() / 10 + 2;

    if (neg) {
      if (x < (max - 2) * -10)
        return 0;

      x *= -1;
    }
    while (x > 0) {
      if (val < max) {
        val *= 10;
      } else {
        return 0;
      }
      val += x % 10;
      x /= 10;
    }
    if (neg) {
      val *= -1;
    }
    return val;
  }
};
