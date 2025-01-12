// https://leetcode.com/problems/find-the-highest-altitude

#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <vector>

class Solution
{
 public:
  int largestAltitude(std::vector<int> gain)
  {
    std::partial_sum(begin(gain), end(gain), begin(gain));
    // All altitudes may be negative, in which case we return 0;
    return std::max(0, *std::ranges::max_element(gain));
  };
};

int main()
{
  assert(Solution{}.largestAltitude({-5, 1, 5, 0, -7}) == 1);
  assert(Solution{}.largestAltitude({-4, -3, -2, -1, 4, 3, 2}) == 0);

  return 0;
}
