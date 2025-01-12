// https://leetcode.com/problems/non-overlapping-intervals

#include <cassert>
#include <vector>

class Solution
{
 public:
  int eraseOverlapIntervals(std::vector<std::vector<int>> intervals)
  {
    std::ranges::sort(intervals, [](const auto& i1, const auto& i2) { return interval_end(i1) < interval_end(i2); });

    auto removed = 0;

    auto last_end = interval_end(intervals.front());

    for (auto cit = std::next(cbegin(intervals)); cit != cend(intervals); ++cit)
    {
      if (interval_start(*cit) < last_end)
      {
        removed += 1;
      }
      else
      {
        last_end = interval_end(*cit);
      }
    }

    return removed;
  }

 private:
  static int interval_start(const std::vector<int> interval) noexcept { return interval[0]; }
  static int interval_end(const std::vector<int> interval) noexcept { return interval[1]; }
};

int main()
{
  assert(Solution{}.eraseOverlapIntervals({{1, 2}, {2, 3}, {3, 4}, {1, 3}}) == 1);
  assert(Solution{}.eraseOverlapIntervals({{1, 2}, {1, 2}, {1, 2}}) == 2);
  assert(Solution{}.eraseOverlapIntervals({{1, 2}, {2, 3}}) == 0);

  return 0;
}
