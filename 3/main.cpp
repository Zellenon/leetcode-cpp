#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int mapMax(unordered_map<char, int> m) {
  int buffer = 0;
  for (auto i = m.begin(); i != m.end(); ++i) {
    if (i->second > buffer) {
      buffer = i->second;
    }
  }
  return buffer;
}

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int index = 0;
    int longest = 0;
    int max_len = s.length();
    unordered_map<char, int> char_set = {};

    while (index + longest < max_len) {
      char next_letter = s.at(index + longest);
      auto temp = char_set.emplace(next_letter, 0);
      temp.second += 1;

      if (mapMax(char_set) > 1) {
        char_set[s.at(index)]--;
        index++;
      } else {
        longest++;
      }
    }
    return longest;
  }
};
