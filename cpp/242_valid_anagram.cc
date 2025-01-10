#include <algorithm>
#include <cassert>
#include <string>

class Solution
{
 public:
  bool isAnagram(std::string s, std::string t)
  {
    if (s.size() != t.size())
    {
      return false;
    }

    std::ranges::sort(s);
    std::ranges::sort(t);

    return std::ranges::equal(s, t);
  }
};

int main()
{
  assert(Solution{}.isAnagram("anagram", "nagaram") == true);
  assert(Solution{}.isAnagram("anagram", "") == false);
  assert(Solution{}.isAnagram("", "") == true);
  assert(Solution{}.isAnagram("anagram", "anagram") == true);
  assert(Solution{}.isAnagram("anagram", "anagra") == false);

  return 0;
}
