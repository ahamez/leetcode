// https://leetcode.com/problems/number-of-recent-calls

#include <cassert>
#include <deque>

class RecentCounter final
{
  std::deque<int> queue_{};

 public:
  int ping(int t) noexcept
  {
    queue_.emplace_back(t);

    while (queue_.front() < (t - 3000))
    {
      queue_.pop_front();
    }

    return queue_.size();
  }
};

int main()
{
  auto counter = RecentCounter{};

  assert(counter.ping(1) == 1);
  assert(counter.ping(100) == 2);
  assert(counter.ping(3001) == 3);
  assert(counter.ping(3002) == 3);

  return 0;
}
