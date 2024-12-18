// https://leetcode.com/problems/middle-of-the-linked-list

#include <cassert>

struct ListNode
{
  int val;
  ListNode* next;

  ListNode()
      : ListNode{0, nullptr}
  {
  }
  ListNode(int x)
      : ListNode{x, nullptr}

  {
  }
  ListNode(int x, ListNode* next)
      : val(x),
        next(next)
  {
  }
};

class Solution
{
 public:
  ListNode* middleNode(ListNode* head)
  {
    assert(head != nullptr);
    // return recurse(head, head);

    auto slow = head;
    auto fast = head;

    while (true)
    {
      if (fast->next == nullptr)
      {
        return slow;
      }
      else if (fast->next->next == nullptr)
      {
        return slow->next;
      }

      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

 private:
  ListNode* recurse(ListNode* slow, ListNode* fast)
  {
    assert(slow != nullptr);
    assert(fast != nullptr);

    if (fast->next == nullptr)
    {
      return slow;
    }
    else if (fast->next->next == nullptr)
    {
      return slow->next;
    }
    else
    {
      return recurse(slow->next, fast->next->next);
    }
  }
};

int main()
{
  const auto l0 = new ListNode{3, new ListNode{4, new ListNode{5}}};
  const auto l1 = new ListNode{1, new ListNode{2, l0}};

  assert(Solution{}.middleNode(l1) == l0);

  return 0;
}
