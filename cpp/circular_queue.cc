#include <array>
#include <cassert>
#include <optional>

struct queue
{
  static constexpr std::size_t capacity = 4;
  using queue_type = std::array<int, capacity>;

  queue_type queue_;
  std::size_t size_;
  std::size_t front_;
  std::size_t rear_;

  queue()
      : queue_{},
        size_{0},
        front_{0},
        rear_{0}
  {
  }

  bool enqueue(int value) noexcept
  {
    if (full())
    {
      return false;
    }

    queue_[rear_] = value;
    rear_ = (rear_ + 1) % capacity;
    size_ += 1;

    return true;
  }

  std::optional<int> dequeue() noexcept
  {
    if (empty())
    {
      return {};
    }

    const auto value = queue_[front_];
    front_ = (front_ + 1) % capacity;
    size_ -= 1;

    return value;
  }

  bool full() const noexcept { return size_ == capacity; }
  bool empty() const noexcept { return size_ == 0; }
  std::size_t size() const noexcept { return size_; }
};

int main()
{
  auto q = queue{};

  assert(q.size() == 0);
  assert(q.empty() == true);
  assert(q.full() == false);
  assert(q.dequeue().has_value() == false);

  assert(q.enqueue(1));
  assert(q.size() == 1);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.enqueue(2));
  assert(q.size() == 2);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.enqueue(3));
  assert(q.size() == 3);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.enqueue(4));
  assert(q.size() == 4);
  assert(q.empty() == false);
  assert(q.full() == true);

  assert(q.enqueue(5) == false);
  assert(q.size() == 4);
  assert(q.empty() == false);
  assert(q.full() == true);

  assert(q.dequeue() == 1);
  assert(q.size() == 3);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.dequeue() == 2);
  assert(q.size() == 2);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.dequeue() == 3);
  assert(q.size() == 1);
  assert(q.empty() == false);
  assert(q.full() == false);

  assert(q.dequeue() == 4);
  assert(q.size() == 0);
  assert(q.empty() == true);
  assert(q.full() == false);

  return 0;
}
