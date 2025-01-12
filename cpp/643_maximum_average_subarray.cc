// https://leetcode.com/problems/maximum-average-subarray-i

#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <vector>

class Solution
{
 public:
  double findMaxAverage(std::vector<int> nums, std::size_t k)
  {
    const auto k_as_double = static_cast<double>(k);

    std::partial_sum(cbegin(nums), cend(nums), begin(nums));

    auto max_average = nums[k - 1] / k_as_double;
    for (auto i = k; i < nums.size(); ++i)
    {
      max_average = std::max(max_average, (nums[i] - nums[i - k]) / k_as_double);
    }

    return max_average;
  }
};

int main()
{
  assert(Solution{}.findMaxAverage({1, 1}, 2) == 1);
  assert(Solution{}.findMaxAverage({1, 12, -5, -6, 50, 3}, 4) == 12.75);
  assert(Solution{}.findMaxAverage({5}, 1) == 5.0);
  assert(Solution{}.findMaxAverage({0, 1, 1, 3, 3}, 4) == 2.00);

  return 0;
}
