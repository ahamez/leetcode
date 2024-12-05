// https://leetcode.com/problems/unique-number-of-occurrences

#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solution
{
 public:
  bool uniqueOccurrences(std::vector<int> arr)
  {
    auto occurrences = std::unordered_map<int, std::size_t>{};
    for (const auto value : arr)
    {
      auto [it, _inserted] = occurrences.emplace(value, 0);
      it->second += 1;
    };

    auto occurrences_count = std::unordered_set<std::size_t>{};
    for (const auto [value, count] : occurrences)
    {
      if (auto [_it, inserted] = occurrences_count.emplace(count); not inserted)
      {
        return false;
      }
    };

    return true;
  }
};

int main()
{
  auto solution = Solution{};

  assert(solution.uniqueOccurrences({1, 2, 2, 1, 1, 3}) == true);

  return 0;
}
