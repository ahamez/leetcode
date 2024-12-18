// https://leetcode.com/problems/move-zeroes/

#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
 public:
  void moveZeroes(std::vector<int>& vec)
  {
    auto left = begin(vec);
    for (auto right = begin(vec); right != cend(vec); ++right)
    {
      if (*right != 0)
      {
        std::iter_swap(left, right);
        ++left;
      }
    }
  }
};

int main()
{
  {
    auto vec = std::vector<int>{4, 2, 4, 0, 0, 3, 0, 5, 1, 0};
    auto ref = std::vector<int>{4, 2, 4, 3, 5, 1, 0, 0, 0, 0};
    Solution{}.moveZeroes(vec);
    assert(std::ranges::equal(vec, ref));
  }

  {
    auto vec = std::vector<int>{0, 0, 1};
    auto ref = std::vector<int>{1, 0, 0};
    Solution{}.moveZeroes(vec);
    assert(std::ranges::equal(vec, ref));
  }

  {
    auto vec = std::vector<int>{1, 0};
    auto ref = std::vector<int>{1, 0};
    Solution{}.moveZeroes(vec);
    assert(std::ranges::equal(vec, ref));
  }

  {
    auto vec = std::vector<int>{0, 1};
    auto ref = std::vector<int>{1, 0};
    Solution{}.moveZeroes(vec);
    assert(std::ranges::equal(vec, ref));
  }

  {
    auto vec = std::vector<int>{0, 1, 0, 3, 12};
    auto ref = std::vector<int>{1, 3, 12, 0, 0};
    Solution{}.moveZeroes(vec);
    assert(std::ranges::equal(vec, ref));
  }

  return 0;
}
