// https://leetcode.com/problems/removing-stars-from-a-string

#include <cassert>
#include <string>

class Solution final
{
 public:
  std::string removeStars(std::string s)
  {
    // Version 1. In-place modification of the string.

    auto write_position = begin(s);

    for (const auto c : s)
    {
      if (c == '*')
      {
        --write_position;
      }
      else
      {
        *write_position = c;
        ++write_position;
      }
    }

    s.erase(std::next(write_position), end(s));
    return s;

    // Version2. Use an explicit stack.

    // auto stack = std::string{};
    // stack.reserve(s.size());

    // for (auto c : s)
    // {
    //   if (c == '*' and stack.size() > 0)
    //   {
    //     stack.pop_back();
    //   }
    //   else
    //   {
    //     stack.push_back(c);
    //   }
    // }

    // return stack;
  }
};

int main()
{
  assert(Solution{}.removeStars("leet**cod*e") == "lecoe");
  assert(Solution{}.removeStars("erase*****") == "");

  return 0;
}
