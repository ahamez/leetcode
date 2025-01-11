// https://leetcode.com/problems/is-subsequence

#include <cassert>
#include <string>

class Solution
{
 public:
  bool isSubsequence(std::string s, std::string t)
  {
    auto s_cit = cbegin(s);
    auto t_cit = cbegin(t);

    while (s_cit != cend(s) and t_cit != cend(t))
    {
      if (*s_cit == *t_cit)
      {
        ++s_cit;
      }
      ++t_cit;
    }

    return s_cit == cend(s);
  }
};

int main()
{
  assert(Solution{}.isSubsequence("abc", "ahbgdc") == true);
  assert(Solution{}.isSubsequence("axc", "ahbgdc") == false);

  return 0;
}
