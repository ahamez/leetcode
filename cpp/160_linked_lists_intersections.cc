// https://leetcode.com/problems/intersection-of-two-linked-lists

#include <cassert>

struct ListNode
{
  int val;
  const ListNode* next;
  ListNode(int x)
      : ListNode{x, nullptr}
  {
  }
  ListNode(int x, const ListNode* next)
      : val{x},
        next{next}
  {
  }
};

class Solution
{
 public:
  const ListNode* getIntersectionNode(const ListNode* headA, const ListNode* headB)
  {
    if (headA == nullptr || headB == nullptr)
    {
      return nullptr;
    }

    auto pA = headA;
    auto pB = headB;

    while (pA != pB)
    {
      pA = (pA == nullptr) ? headB : pA->next;
      pB = (pB == nullptr) ? headA : pB->next;
    }

    return pA;
  }
};

int main()
{
  const auto c3 = ListNode{5};
  const auto c2 = ListNode{4, &c3};
  const auto c1 = ListNode{8, &c2};

  const auto b3 = ListNode{1, &c1};
  const auto b2 = ListNode{6, &b3};
  const auto b1 = ListNode{5, &b2};

  const auto a2 = ListNode{1, &c1};
  const auto a1 = ListNode{4, &a2};

  assert(Solution{}.getIntersectionNode(&a1, &b1) == &c1);

  return 0;
}
