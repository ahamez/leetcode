// https://leetcode.com/problems/middle-of-the-linked-list/description/

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
  ListNode* deleteMiddle_rec(ListNode* head)
  {
    assert(head != nullptr);
    return recurse(head, head);
  }

  ListNode* deleteMiddle(ListNode* head)
  {
    assert(head != nullptr);

    if (head->next == nullptr)
    {
      return nullptr;
    }

    auto slow = head;
    auto fast = head;
    auto prev = head;

    while (fast != nullptr and fast->next != nullptr)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = slow->next;

    return head;
  }

 private:
  ListNode* recurse(ListNode* slow, ListNode* fast)
  {
    assert(slow != nullptr);
    assert(fast != nullptr);

    if (fast->next == nullptr)
    {
      return slow->next;
    }
    else if (fast->next->next == nullptr)
    {
      slow->next = slow->next->next;
      return slow;
    }
    else
    {
      auto ret = recurse(slow->next, fast->next->next);
      slow->next = ret;
      return slow;
    }
  }
};

int main()
{
  const auto l0 = new ListNode{1, new ListNode{2, new ListNode{3, new ListNode{4}}}};
  Solution{}.deleteMiddle(l0);

  return 0;
}
