// https://leetcode.com/problems/valid-word-abbreviation

#include <cassert>
#include <charconv>
#include <iterator>
#include <string>

class Solution
{
 public:
  bool validWordAbbreviation(std::string word, std::string abbr)
  {
    if (word.size() < abbr.size())
    {
      return false;
    }

    if (word == abbr)
    {
      return true;
    }

    auto word_cit = cbegin(word);
    const auto word_cend = cend(word);

    auto abbr_data = abbr.c_str();

    while (*abbr_data != '\0' or word_cit != word_cend)
    {
      if (*abbr_data == '0')
      {
        return false;
      }

      auto value = std::size_t{};
      const auto [ptr, ec] = std::from_chars(abbr_data, abbr_data + abbr.size(), value);
      if (ec == std::errc{})
      {
        abbr_data = ptr;

        if (value > static_cast<std::size_t>(std::distance(word_cit, word_cend)))
        {
          return false;
        }

        word_cit += value;
      }
      else
      {
        if (*ptr != *word_cit)
        {
          return false;
        }
        word_cit += 1;
        abbr_data += 1;
      }
    }

    return true;
  }
};

int main()
{
  auto solution = Solution{};

  assert(solution.validWordAbbreviation("internationalization", "i12iz4n") == true);
  assert(solution.validWordAbbreviation("apple", "a2e") == false);
  assert(solution.validWordAbbreviation("abbde", "a1b01e") == false);
  assert(solution.validWordAbbreviation("a", "2") == false);
  assert(solution.validWordAbbreviation("hi", "hi1") == false);

  return 0;
}
