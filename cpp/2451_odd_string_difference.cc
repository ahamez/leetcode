// https://leetcode.com/problems/odd-string-difference

#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
 public:
  std::string oddString(std::vector<std::string> words)
  {
    struct VectorHash
    {
      auto operator()(const std::vector<int>& v) const noexcept
      {
        return std::accumulate(v.begin(), v.end(), 0,
                               [](const auto prev, const auto curr) { return prev ^ std::hash<int>{}(curr); });
      }
    };

    std::unordered_map<std::vector<int>, std::vector<std::string>, VectorHash> map;
    for (const auto& word : words)
    {
      auto difference = std::vector<int>{};
      difference.reserve(word.size() - 1);

      for (auto i = std::size_t{1}; i < word.size(); ++i)
      {
        difference.push_back(word[i] - word[i - 1]);
      }

      if (const auto [it, inserted] = map.emplace(difference, std::vector<std::string>{word}); not inserted)
      {
        it->second.push_back(word);
      }
    }

    const auto search = std::ranges::find_if(map, [](const auto& pair) { return pair.second.size() == 1; });
    assert(search != cend(map));

    return search->second.front();
  }
};

int main()
{
  auto s = Solution{};

  assert(s.oddString({"aaa", "bob", "ccc", "ddd"}) == "bob");

  return 0;
}
