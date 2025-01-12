// https://leetcode.com/problems/reverse-linked-list

struct ListNode
{
  int val;
  ListNode* next;
  ListNode()
      : val(0),
        next(nullptr)
  {
  }
  ListNode(int x)
      : val(x),
        next(nullptr)
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
  ListNode* reverseList(ListNode* node)
  {
    if (node == nullptr or node->next == nullptr)
    {
      return node;
    }
    else
    {
      return rec(nullptr, node);
    }

    // Iterative version.

    // ListNode* previous = nullptr;
    // ListNode* current = node;

    // while (current != nullptr)
    // {
    //   auto next = current->next;
    //   current->next = previous;
    //   previous = current;
    //   current = next;
    // }

    // return previous;
  }

 private:
  ListNode* rec(ListNode* new_next, ListNode* current_node)
  {
    if (current_node->next != nullptr)
    {
      auto new_head = rec(current_node, current_node->next);
      current_node->next = new_next;
      return new_head;
    }
    else
    {
      current_node->next = new_next;
      return current_node;
    }
  }
};

int main()
{
  return 0;
}
