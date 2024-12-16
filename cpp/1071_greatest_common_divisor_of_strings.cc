// https://leetcode.com/problems/greatest-common-divisor-of-strings

#include <cassert>
#include <numeric>
#include <string>

class Solution
{
 public:
  std::string gcdOfStrings(std::string str1, std::string str2) const
  {
    if (str1 + str2 == str2 + str1)
    {
      const auto gcd = std::gcd(str1.size(), str2.size());
      return str1.substr(0, gcd);
    }
    else
    {
      return "";
    }
  }
};

int main()
{
  auto solution = Solution{};

  assert(solution.gcdOfStrings("ABC", "ABC") == "ABC");
  assert(solution.gcdOfStrings("ABCABC", "ABC") == "ABC");
  assert(solution.gcdOfStrings("ABABAB", "AB") == "AB");
  assert(solution.gcdOfStrings("LEET", "CODE") == "");
  assert(solution.gcdOfStrings("ABABAB", "ABAB") == "AB");

  return 0;
}
