// https://leetcode.com/problems/min-stack/

#include <vector>

class MinStack
{
 private:
  std::vector<int> stack;
  std::vector<int> min_stack;

 public:
  MinStack()
  {
    stack.reserve(1024);
    min_stack.reserve(512);
  }

  void push(int val)
  {
    stack.push_back(val);

    if (min_stack.size() == 0 or min_stack.back() >= val)
    {
      min_stack.push_back(val);
    }
  }

  void pop()
  {
    const auto val = stack.back();
    stack.pop_back();

    if (min_stack.back() == val)
    {
      min_stack.pop_back();
    }
  }

  int top() { return stack.back(); }

  int getMin() { return min_stack.back(); }
};

int main()
{
  return 0;
}
