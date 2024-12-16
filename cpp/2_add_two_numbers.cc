// https://leetcode.com/problems/add-two-numbers/description/

#include <cassert>
#include <iostream>

struct ListNode
{
  unsigned int val;
  ListNode* next;

  ListNode()
      : ListNode{0, nullptr}
  {
  }

  ListNode(unsigned int x)
      : ListNode{x, nullptr}
  {
  }

  ListNode(unsigned int x, ListNode* next)
      : val{x},
        next{next}
  {
  }
};

unsigned int list_to_int(ListNode* node)
{
  unsigned int result = 0;
  unsigned int digit = 1;
  while (node)
  {
    result = result + digit * node->val;
    digit *= 10;
    node = node->next;
  }
  return result;
}

class Solution
{
 public:
  ListNode* addTwoNumbers(ListNode* lhs, ListNode* rhs)
  {
    ListNode* result = new ListNode{};
    auto current_node = result;
    auto carry = 0;

    while (lhs != nullptr or rhs != nullptr or carry != 0)
    {
      const auto lhs_val = lhs == nullptr ? 0 : lhs->val;
      const auto rhs_val = rhs == nullptr ? 0 : rhs->val;
      const auto sum = lhs_val + rhs_val + carry;
      carry = sum / 10;

      lhs = lhs == nullptr ? nullptr : lhs->next;
      rhs = rhs == nullptr ? nullptr : rhs->next;

      current_node->next = new ListNode{sum % 10};
      current_node = current_node->next;
    }

    return result->next;
  }
};

int main()
{
  auto s = Solution{};

  auto _0 = new ListNode{0};
  auto _1 = new ListNode{1};
  auto _10 = new ListNode{0, _1};
  auto _342 = new ListNode{2, new ListNode{4, new ListNode{3}}};
  auto _465 = new ListNode{5, new ListNode{6, new ListNode{4}}};

  assert(list_to_int(s.addTwoNumbers(_0, _0)) == 0);
  assert(list_to_int(s.addTwoNumbers(_0, _1)) == 1);
  assert(list_to_int(s.addTwoNumbers(_1, _1)) == 2);
  assert(list_to_int(s.addTwoNumbers(_10, _0)) == 10);
  assert(list_to_int(s.addTwoNumbers(_342, _465)) == 807);

  return 0;
}
