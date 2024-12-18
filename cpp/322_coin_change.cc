// https://leetcode.com/problems/coin-change

#include <algorithm>
#include <cassert>
#include <vector>

class Solution
{
 public:
  int coinChange(std::vector<int> coins, int total_amount)
  {
    constexpr auto max_coin_value = 10'000;
    auto cache = std::vector<int>(total_amount + 1, max_coin_value + 1);
    cache[0] = 0;

    for (const auto coin : coins)
    {
      for (auto amount = coin; amount <= total_amount; ++amount)
      {
        const auto dont_use_coin = cache[amount];
        const auto use_coin = cache[amount - coin] + 1;

        // Choose best scenario.
        cache[amount] = std::min(dont_use_coin, use_coin);
      }
    }

    return cache[total_amount] > max_coin_value ? -1 : cache[total_amount];
  }
};

int main()
{
  assert(Solution{}.coinChange({2, 1, 5}, 11) == 3);
  assert(Solution{}.coinChange({2}, 3) == -1);
  assert(Solution{}.coinChange({1}, 0) == 0);

  return 0;
}
