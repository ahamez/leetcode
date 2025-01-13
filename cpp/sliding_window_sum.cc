/*

We are given an input list containing datapoints for a metric that we receive
from our customers. The input will be an object. containing: tags, a timestamp
and a value.

input_points= [
  {"tags": ["env:dev"], "timestamp": 0, "value": 1},
  {"tags": ["env:dev"], "timestamp": 1, "value": 3},
  {"tags": ["env:prod","host:a"], "timestamp": 2, "value": 5},
  {"tags": ["env:dev"], "timestamp": 3, "value": -1},
  {"tags": ["env:dev","host:a"], "timestamp": 6, "value": -3},
  {"tags": ["env:dev"], "timestamp": 7, "value": 5},
  {"tags": ["env:staging","host:a"], "timestamp": 9, "value": -3},
  {"tags": ["env:dev"], "timestamp": 10, "value": -4},
  {"tags": ["env:dev"],"timestamp": 11, "value": 6},
  {"tags": ["env:dev"], "timestamp": 14, "value": -1},
  {"tags": ["env:staging"],"timestamp": 15, "value": 10}
]

Write a function that takes an input-list of datapoints, a tag t, and an
integer k (window length in number of points) and return the computed sums of
each consecutive window of size k for all-datapoints associated with tag t.
A datapoint is associated with a tag if the tag is included along with the
datapoint

For example, if k=3 and tag=env:dev, we can consider the sliding windows of
size 3 moving across these points as:

#[(0, 1), (1, 3), (3, -1), (6, -3), (7, 5), (10, -4), (11, 6), (14, -1)]
# [---------------------]
#[(0, 1), (1, 3), (3, -1), (6, -3), (7, 5), (10, -4), (11, 6) , (14, -1)]
#         [----------------------]
#[(0, 1), (1, 3), (3, -1), (6, -3), (7, 5), (10, -4), (11, 6), (14, -1)]
#                 [----------------------]
#[(0, 1), (1, 3), (3, -1), (6, -3), (7, 5), (10, -4), (11, 6), (14, -1)]
#                         [------------------------]
#[(0, 1), (1,3), (3, -1), (6, -3), (7, 5), (10, -4) , (11, 6) , (14, -1)]
#                                  [------------------------]
#[(0, 1), (1, 3), (3, -1), (6, -3), (7, 5), (10, -4), (11, 6), (14, -1)]
#                                            [------------------------]

In the above example, the output should be [3, -1, 1, -2, 7, 1] for k=3 and
tag=env: dev
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <string>
#include <vector>

struct DataPoint
{
  std::vector<std::string> tags;
  int timestamp;
  int value;
};

bool has_tag(const std::vector<std::string>& tags, const std::string& tag)
{
  return std::ranges::find(tags, tag) != cend(tags);
}

std::vector<int> slidingWindowSums(const std::vector<DataPoint>& points, const std::string& tag, std::size_t k)
{
  auto filtered_points_view = points | std::views::filter([&](const auto& dp) { return has_tag(dp.tags, tag); }) |
                              std::views::transform([](const auto& dp) { return dp.value; });

  auto values = std::vector<int>{filtered_points_view.begin(), filtered_points_view.end()};

  if (k > values.size())
  {
    return {};
  }

  std::partial_sum(begin(values), end(values), begin(values));

  auto result = std::vector<int>{};
  result.reserve(values.size() - k + 1);

  auto left = begin(values);
  auto right = begin(values) + k;

  result.push_back(*(right - 1));
  for (; right != end(values); ++left, ++right)
  {
    result.push_back(*right - *left);
  }

  return result;
}

int main()
{
  const auto input_points = std::vector<DataPoint>{{{"env:dev"}, 0, 1},
                                                   {{"env:dev"}, 1, 3},
                                                   {{"env:prod", "host:a"}, 2, 5},
                                                   {{"env:dev"}, 3, -1},
                                                   {{"env:dev", "host:a"}, 6, -3},
                                                   {{"env:dev"}, 7, 5},
                                                   {{"env:staging", "host:a"}, 9, -3},
                                                   {{"env:dev"}, 10, -4},
                                                   {{"env:dev"}, 11, 6},
                                                   {{"env:dev"}, 14, -1},
                                                   {{"env:staging"}, 15, 10}};

  const auto sums = slidingWindowSums(input_points, "env:dev", 3);

  std::ranges::copy(sums, std::ostream_iterator<int>(std::cout, " "));
  std::cout << "\n";

  return 0;
}
