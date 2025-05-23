// Solution passes all tests with 0ms runtime (meets or beats 100.00% of
// competitors) and 95.00MB memory (meets or beats 93.39% of competitors)
//
using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int total_len = nums1.size() + nums2.size();
    bool bridge_mids = total_len % 2 == 0;
    int next_num = 0;
    auto n1 = nums1.begin();
    auto n2 = nums2.begin();

    auto nextNum = [&]() {
      if (n1 != nums1.end()) {
        if (n2 != nums2.end()) {
          if (*n1 < *n2) {
            next_num = *n1;
            ++n1;
          } else {
            next_num = *n2;
            ++n2;
          }
        } else {
          next_num = *n1;
          ++n1;
        }
      } else {
        next_num = *n2;
        ++n2;
      }
      return next_num;
    };

    int i = 0;
    if (bridge_mids)
      i++;
    for (; i < total_len / 2; ++i)
      nextNum();

    if (bridge_mids) {
      float a = nextNum();
      float b = nextNum();
      return (a + b) / 2;
    } else {
      return nextNum();
    }
  }
};
