// https://leetcode.com/problems/reverse-vowels-of-a-string

#include <algorithm>
#include <cassert>
#include <string>

class Solution
{
 public:
  std::string reverseVowels(std::string s)
  {
    if (s.empty())
    {
      return s;
    }

    auto forward_it = begin(s);
    auto backward_it = rbegin(s);

    while (forward_it < backward_it.base())
    {
      while (forward_it != end(s) and not is_vowel(*forward_it))
      {
        ++forward_it;
      }

      while (backward_it != rend(s) and not is_vowel(*backward_it))
      {
        ++backward_it;
      }

      if (forward_it < backward_it.base())
      {
        std::iter_swap(forward_it, backward_it);

        ++forward_it;
        ++backward_it;
      }
    }

    return s;
  }

 private:
  static bool is_vowel(char c) noexcept
  {
    switch (c)
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case 'A':
      case 'E':
      case 'I':
      case 'O':
      case 'U':
        return true;
      default:
        return false;
    }
  }
};

int main()
{
  assert(Solution{}.reverseVowels("") == "");
  assert(Solution{}.reverseVowels("ai") == "ia");
  assert(Solution{}.reverseVowels("IceCreAm") == "AceCreIm");
  assert(Solution{}.reverseVowels("leetcode") == "leotcede");
  assert(Solution{}.reverseVowels("Marge, let's \"went.\" I await news telegram.") ==
         "Marge, let's \"went.\" i awaIt news telegram.");
  assert(Solution{}.reverseVowels("Tide-net safe, soon, Allin. A manilla noose fastened it.") ==
         "Tide-net safe, soon, allin. a mAnillA noose fastened it.");

  return 0;
}
