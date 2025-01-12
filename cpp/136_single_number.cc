// https://leetcode.com/problems/single-number

#include <cassert>
#include <functional>
#include <numeric>
#include <vector>

class Solution
{
 public:
  int singleNumber(std::vector<int> nums)
  {
    // a ^ a = 0
    // a ^ 0 = a
    // a ^ b ^ a => (a ^ a) ^ b => 0 ^ b => b
    return std::accumulate(cbegin(nums), cend(nums), 0, std::bit_xor{});
  };
};

int main()
{
  assert(Solution{}.singleNumber({2, 2, 1}) == 1);
  assert(Solution{}.singleNumber({4, 1, 2, 1, 2}) == 4);
  assert(Solution{}.singleNumber({1}) == 1);

  return 0;
}
