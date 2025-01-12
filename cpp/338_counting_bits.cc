// https://leetcode.com/problems/counting-bits

#include <bit>
#include <cassert>
#include <vector>

class Solution
{
 public:
  std::vector<int> countBits(int n)
  {
    auto res = std::vector<int>(n + 1, 0);

    for (auto i = 0; i <= n; ++i)
    {
      res[i] = std::popcount(static_cast<unsigned int>(i));

      // Manual version
      // auto tmp = i;
      // auto count = 0;
      // while (tmp != 0)
      // {
      //   count += tmp % 2;
      //   tmp >>= 1;  // or tmp /= 1;
      // }
      // res[i] = count;
    }

    return res;
  }
};

int main()
{
  assert((Solution{}.countBits(2) == std::vector<int>{0, 1, 1}));
  assert((Solution{}.countBits(5) == std::vector<int>{0, 1, 1, 2, 1, 2}));

  return 0;
}
