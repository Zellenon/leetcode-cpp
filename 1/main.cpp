// Solution passes all tests with 3ms runtime (meets or beats 72.25% of
// competitors) and 14.87 memory (meets or beats 36.65% of competitors)

using std::vector;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> hmap = {};
    for (int i = 0; i < nums.size() - 1; i++) {
      int x = nums[i];
      int remainder = target - x;
      if (hmap.contains(remainder)) {
        return {i, hmap.at(remainder)};
      } else {
        hmap.insert({x, i});
      }
    }
    return {-1, -1};
  }
};
