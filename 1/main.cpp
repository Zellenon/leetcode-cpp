// Solution passes all tests with 0ms runtime (meets or beats 100.00% of
// competitors) and 14.96 memory (meets or beats 21.46% of competitors)

using std::vector;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    std::unordered_map<int, int> hmap = {};
    for (int i = 0; i < nums.size() - 1; i++) {
      int remainder = target - nums[i];
      if (hmap.count(remainder)) {
        return {i, hmap.at(remainder)};
      } else {
        hmap.insert({nums[i], i});
      }
    }
    return {};
  }
};
