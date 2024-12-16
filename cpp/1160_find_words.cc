// https://leetcode.com/problems/find-words-that-can-be-formed-by-characters

#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

class Solution
{
 public:
  int countCharacters(std::vector<std::string> words, std::string chars)
  {
    std::sort(begin(chars), end(chars));

    auto total_length = 0;

    for (auto word_cit = begin(words); word_cit != end(words); ++word_cit)
    {
      std::sort(begin(*word_cit), end(*word_cit));

      if (std::includes(cbegin(chars), cend(chars), cbegin(*word_cit), cend(*word_cit)))
      {
        total_length += word_cit->size();
      }
    }

    return total_length;
  }
};

int main()
{
  assert(Solution{}.countCharacters({"cat", "bt", "hat", "tree"}, "atach") == 6);
  return 0;
}
