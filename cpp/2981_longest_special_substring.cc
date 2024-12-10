// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

#include <cassert>
#include <string>

class Solution
{
 public:
  int maximumLength(std::string s) noexcept
  {
    int ans = -1;
    auto substring = std::string(s.size(), 'a');

    for (auto c = 'a'; c <= 'z'; ++c)
    {
      for (auto len = std::size_t{1}; len <= s.size(); ++len)
      {
        substring.clear();
        substring.assign(len, c);

        auto count = 0u;

        for (auto start = 0u; start + len <= s.size(); ++start)
        {
          if (s.compare(start, len, substring) == 0)
          {
            ++count;
          }
        }

        if (count >= 3)
        {
          ans = std::max(ans, static_cast<int>(len));
        }
      }
    }

    return ans;
  }
};

int main()
{
  auto s = Solution{};

  assert(s.maximumLength("aaaa") == 2);
  assert(s.maximumLength("abcdef") == -1);
  assert(s.maximumLength("abcaba") == 1);

  return 0;
}
