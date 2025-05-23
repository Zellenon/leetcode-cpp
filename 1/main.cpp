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
