// https://leetcode.com/problems/letter-combinations-of-a-phone-number

#include <algorithm>
#include <cassert>
#include <iterator>
#include <string>
#include <vector>

static auto mapping = std::vector<std::string>{/* 0 => */ " ",
                                               /* 1 => */ "",
                                               /* 2 => */ "abc",
                                               /* 3 => */ "def",
                                               /* 4 => */ "ghi",
                                               /* 5 => */ "jkl",
                                               /* 6 => */ "mno",
                                               /* 7 => */ "pqrs",
                                               /* 8 => */ "tuv",
                                               /* 9 => */ "wxyz"};
static constexpr auto max_combinations = 3 * 3 * 3 * 3 * 3 * 4 * 3 * 4;

class Solution final
{
 public:
  std::vector<std::string> letterCombinations(std::string digits)
  {
    if (digits.empty())
    {
      return {};
    }

    auto acc = std::vector<std::string>{};
    acc.reserve(max_combinations);
    rec(acc, /* path = */ std::string{}, cbegin(digits), cend(digits));
    return acc;
  }

 private:
  void rec(std::vector<std::string>& acc, std::string path, auto digits_cit, auto digits_cend) noexcept
  {
    if (digits_cit == digits_cend)
    {
      acc.emplace_back(path);
    }
    else
    {
      const auto current_digit = *digits_cit;
      ++digits_cit;

      for (const auto letter : mapping[current_digit - '0'])
      {
        rec(acc, path + letter, digits_cit, digits_cend);
      }
    }
  }
};

int main()
{
  assert(std::ranges::equal(Solution{}.letterCombinations("23"),
                            std::vector<std::string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));

  assert(std::ranges::equal(Solution{}.letterCombinations(""), std::vector<std::string>{}));

  return 0;
}
