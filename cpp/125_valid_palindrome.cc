// https://leetcode.com/problems/valid-palindrome

#include <cassert>
#include <cctype>
#include <iterator>
#include <string>

class Solution
{
 public:
  bool isPalindrome(std::string s)
  {
    // In-place modification of s to keep only alphanumeric characters.
    auto write_position = begin(s);
    for (const auto c : s)
    {
      if (std::isalnum(c))
      {
        *write_position = std::tolower(c);
        ++write_position;
      }
    }
    s.erase(write_position, end(s));

    return std::equal(cbegin(s), cbegin(s) + s.size() / 2, std::crbegin(s));

    // Manual version.
    //
    // auto s_prime = std::string{};
    // s_prime.reserve(s.size());
    //
    // for (auto c : s)
    // {
    //   if (std::isalnum(c))
    //   {
    //     s_prime.push_back(std::tolower(c));
    //   }
    // }
    //
    // auto head = cbegin(s_prime);
    // auto tail = crbegin(s_prime);

    // while (head != cend(s_prime))
    // {
    //   if (*head != *tail)
    //   {
    //     return false;
    //   }
    //   ++head;
    //   ++tail;
    // }
  }
};

int main()
{
  assert(Solution{}.isPalindrome("A man, a plan, a canal: Panama") == true);
  assert(Solution{}.isPalindrome("race a car") == false);
  assert(Solution{}.isPalindrome(" ") == true);
  return 0;
}
