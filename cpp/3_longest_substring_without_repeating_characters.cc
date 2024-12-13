// https://leetcode.com/problems/longest-substring-without-repeating-characters

#include <array>
#include <cassert>
#include <string>

class Solution
{
 public:
  int lengthOfLongestSubstring(std::string s) const noexcept
  {
    auto seen = std::array<decltype(cbegin(s)), 256>{};
    seen.fill(cend(s));
    auto longest = 0l;
    auto l = cbegin(s);

    for (auto r = cbegin(s); r != cend(s); ++r)
    {
      const auto current_char = *r;
      if (seen[current_char] != cend(s) and seen[current_char] >= l)
      {
        l = seen[current_char] + 1;
      }
      else
      {
        const auto substring_length = r - l + 1;
        longest = std::max(substring_length, longest);
      }
      seen[current_char] = r;
    }
    return longest;
  }
};

int main()
{
  assert(Solution{}.lengthOfLongestSubstring("") == 0);
  assert(Solution{}.lengthOfLongestSubstring("a") == 1);
  assert(Solution{}.lengthOfLongestSubstring("abcabcbb") == 3);
  assert(Solution{}.lengthOfLongestSubstring("bbbbb") == 1);
  assert(Solution{}.lengthOfLongestSubstring("pwwkew") == 3);
  assert(Solution{}.lengthOfLongestSubstring("aab") == 2);
  assert(Solution{}.lengthOfLongestSubstring("dvdf") == 3);
  assert(Solution{}.lengthOfLongestSubstring("asjrgapa") == 6);

  return 0;
}
