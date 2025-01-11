#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
 public:
  std::vector<int> anagramMappings(std::vector<int> x, std::vector<int> y)
  {
    assert(x.size() == y.size());
    auto answer = std::vector<int>{};
    answer.reserve(x.size());

    auto y_indexes = [&]()
    {
      auto indexes = std::vector<int>(100'000, -1);
      for (auto index = std::size_t{0}; index < y.size(); ++index)
      {
        indexes[y[index]] = index;
      }
      return indexes;
    }();

    for (auto value : x)
    {
      assert(y_indexes[static_cast<std::size_t>(value)] != -1);
      answer.emplace_back(y_indexes[static_cast<std::size_t>(value)]);
    }

    return answer;
  }
};

int main()
{
  const auto ans1 = Solution{}.anagramMappings({12, 28, 46, 32, 50}, {50, 12, 32, 46, 28});
  const auto res1 = {1, 4, 3, 2, 0};
  assert(ans1.size() == res1.size() and std::ranges::equal(ans1, res1) == true);
  return 0;
}
