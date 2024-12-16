#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Iterator>
void reverse(Iterator first, Iterator last)
{
  const auto distance = (last - first) / 2;
  for (auto i = 0; i < distance; ++i)
  {
    std::iter_swap(first + i, last - i - 1);
  }
}

std::vector<int> merge(std::vector<int> lhs, std::vector<int> rhs)
{
  auto res = std::vector<int>{};
  res.reserve(lhs.size() + rhs.size());

  auto lhs_cit = cbegin(lhs);
  auto lhs_cend = cend(lhs);
  auto rhs_cit = cbegin(rhs);
  auto rhs_cend = cend(rhs);

  while (lhs_cit != lhs_cend and rhs_cit != rhs_cend)
  {
    if (*lhs_cit < *rhs_cit)
    {
      res.emplace_back(*lhs_cit);
      ++lhs_cit;
    }
    else
    {
      res.emplace_back(*rhs_cit);
      ++rhs_cit;
    }
  }

  std::copy(lhs_cit, lhs_cend, std::back_insert_iterator<decltype(res)>{res});
  std::copy(rhs_cit, rhs_cend, std::back_insert_iterator<decltype(res)>{res});

  return res;
}

int main()
{
  {
    auto a = std::array<int, 5>{1, 2, 3, 4, 5};
    std::copy(cbegin(a), cend(a), std::ostream_iterator<int>{std::cout, ","});
    reverse(begin(a), end(a));
    std::cout << '\n';
    std::copy(cbegin(a), cend(a), std::ostream_iterator<int>{std::cout, ","});
    std::cout << '\n';
  }
  {
    auto a = std::array<int, 4>{1, 2, 3, 4};
    std::copy(cbegin(a), cend(a), std::ostream_iterator<int>{std::cout, ","});
    reverse(begin(a), end(a));
    std::cout << '\n';
    std::copy(cbegin(a), cend(a), std::ostream_iterator<int>{std::cout, ","});
    std::cout << '\n';
  }
  {
    auto v1 = std::vector<int>{1, 1, 2, 3, 5};
    auto v2 = std::vector<int>{1, 1, 2, 3, 5};
    const auto res = merge(v1, v2);
    std::copy(cbegin(res), cend(res), std::ostream_iterator<int>{std::cout, ","});
    std::cout << '\n';
  }
  {
    auto v1 = std::vector<int>{1, 1, 2, 3, 5};
    auto v2 = std::vector<int>{};
    const auto res = merge(v1, v2);
    std::copy(cbegin(res), cend(res), std::ostream_iterator<int>{std::cout, ","});
    std::cout << '\n';
  }
  {
    auto v1 = std::vector<int>{1, 3, 5, 7, 9};
    auto v2 = std::vector<int>{0, 2, 4, 6, 8};
    const auto res = merge(v1, v2);
    std::copy(cbegin(res), cend(res), std::ostream_iterator<int>{std::cout, ","});
    std::cout << '\n';
  }
  return 0;
}
