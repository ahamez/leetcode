// https://leetcode.com/problems/find-the-difference-of-two-arrays

#include <algorithm>
#include <cassert>
#include <iterator>
#include <set>
#include <unordered_set>
#include <vector>

class Solution
{
 public:
  std::vector<std::vector<int>> findDifference(std::vector<int> xs, std::vector<int> ys)
  {
    const auto xs_set = std::unordered_set<int>{cbegin(xs), cend(xs)};
    const auto ys_set = std::unordered_set<int>{cbegin(ys), cend(ys)};

    auto xs_not_in_ys = std::vector<int>{};
    xs_not_in_ys.reserve(xs.size());
    auto ys_not_in_xs = std::vector<int>{};
    ys_not_in_xs.reserve(ys.size());

    std::ranges::copy_if(xs_set, std::back_inserter(xs_not_in_ys), [&](auto x) { return not ys_set.contains(x); });
    std::ranges::copy_if(ys_set, std::back_inserter(ys_not_in_xs), [&](auto y) { return not xs_set.contains(y); });

    return {xs_not_in_ys, ys_not_in_xs};

    // Version using ordered sets and set_difference. Seems to be a little slower.
    // const auto xs_set = std::set<int>{cbegin(xs), cend(xs)};
    // const auto ys_set = std::set<int>{cbegin(ys), cend(ys)};

    // auto xs_not_in_ys = std::vector<int>{};
    // xs_not_in_ys.reserve(xs.size());
    // auto ys_not_in_xs = std::vector<int>{};
    // ys_not_in_xs.reserve(ys.size());

    // std::ranges::set_difference(xs_set, ys_set, std::back_inserter(xs_not_in_ys));
    // std::ranges::set_difference(ys_set, xs_set, std::back_inserter(ys_not_in_xs));

    // return {xs_not_in_ys, ys_not_in_xs};
  }
};

int main()
{
  assert((Solution{}.findDifference({1, 2, 3}, {2, 4, 6}) == std::vector<std::vector<int>>{{1, 3}, {4, 6}}));
  assert((Solution{}.findDifference({1, 2, 3, 3}, {1, 1, 2, 2}) == std::vector<std::vector<int>>{{3}, {}}));

  return 0;
}
