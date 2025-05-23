// I was fascinated by Leetcode's assertion that under 1% of submissions were
// able to solve the problem consuming 10x less memory than my main solution, so
// this is me experimenting.

// Solution passes all tests with 0ms runtime (meets or beats 100.00% of
// competitors) and 76.68 memory (meets or beats 96.37% of competitors)

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int listLength(ListNode *l) {
  int i = 0;
  while (l) {
    l = l->next;
    i++;
  }
  return i;
}

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int len1 = listLength(l1);
    int len2 = listLength(l2);
    ListNode *start;
    ListNode *other;

    if (len1 > len2) {
      start = l1;
      other = l2;
    } else {
      start = l2;
      other = l1;
    }

    ListNode *current_node = start;
    int total = 0;
    int next_digit = 0;

    while (current_node != nullptr || other != nullptr || next_digit != 0) {
      total = next_digit;
      if (current_node != nullptr) {
        total += current_node->val;
      }
      if (other != nullptr) {
        total += other->val;
        other = other->next;
      }

      next_digit = total / 10;
      current_node->val = total % 10;
      if (!current_node->next && next_digit) {
        current_node->next = new ListNode(next_digit);
        return start;
      }
      current_node = current_node->next;
    }

    return start;
  }
};
