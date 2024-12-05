// https://leetcode.com/problems/design-circular-queue

#include <cassert>
#include <list>

class MyCircularQueue
{
 private:
  std::list<int> list;
  std::size_t max_size;

 public:
  MyCircularQueue(std::size_t k)
      : list{},
        max_size{k}
  {
  }

  bool enQueue(int value)
  {
    if (list.size() == max_size)
    {
      return false;
    }
    else
    {
      list.push_back(value);
      return true;
    }
  }

  bool deQueue()
  {
    if (list.empty())
    {
      return false;
    }
    else
    {
      list.pop_front();
      return true;
    }
  }

  int Front()
  {
    if (list.empty())
    {
      return -1;
    }
    else
    {
      return list.front();
    }
  }

  int Rear()
  {
    if (list.empty())
    {
      return -1;
    }
    else
    {
      return list.back();
    }
  }

  bool isEmpty() { return list.empty(); }

  bool isFull() { return list.size() == max_size; }
};

int main()
{
  auto myCircularQueue = MyCircularQueue{3};

  assert(myCircularQueue.enQueue(1) == true);
  assert(myCircularQueue.enQueue(2) == true);
  assert(myCircularQueue.enQueue(3) == true);
  assert(myCircularQueue.enQueue(4) == false);
  assert(myCircularQueue.Rear() == 3);
  assert(myCircularQueue.isFull() == true);
  assert(myCircularQueue.deQueue() == true);
  assert(myCircularQueue.enQueue(4) == true);
  assert(myCircularQueue.Rear() == 4);

  return 0;
}
