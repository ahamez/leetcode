// https://leetcode.com/problems/merge-strings-alternately

#include <algorithm>
#include <cassert>
#include <iterator>
#include <string>

class Solution
{
 public:
  std::string mergeAlternately(std::string w1, std::string w2)
  {
    auto result = std::string{};
    result.reserve(w1.size() + w2.size());
    auto result_it = std::back_inserter(result);

    auto w1_cit = cbegin(w1);
    auto w2_cit = cbegin(w2);

    while (w1_cit != cend(w1) and w2_cit != cend(w2))
    {
      *result_it = *w1_cit;
      *result_it = *w2_cit;

      ++w1_cit;
      ++w2_cit;
      ++result_it;
    }

    std::copy(w1_cit, cend(w1), result_it);
    std::copy(w2_cit, cend(w2), result_it);

    return result;
  }
};

int main()
{
  assert(Solution{}.mergeAlternately("abc", "pqr") == "apbqcr");
  assert(Solution{}.mergeAlternately("abc", "") == "abc");
  assert(Solution{}.mergeAlternately("", "pqr") == "pqr");
  assert(Solution{}.mergeAlternately("", "") == "");
  assert(Solution{}.mergeAlternately("ab", "pqrs") == "apbqrs");
  assert(Solution{}.mergeAlternately("abcd", "pq") == "apbqcd");

  return 0;
}
