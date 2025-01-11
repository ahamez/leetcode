#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>

static constexpr size_t ALPHABET_SIZE = 26;

class Solution
{
 public:
  std::vector<std::string> wordSubsets(std::vector<std::string> words1, std::vector<std::string> words2)
  {
    auto result = std::vector<std::string>{};
    result.reserve(words1.size());

    auto max_frequencies = std::array<std::size_t, ALPHABET_SIZE>{};

    for (const auto& word2 : words2)
    {
      const auto word2_frequencies = frequencies(word2);
      std::ranges::transform(max_frequencies, word2_frequencies, begin(max_frequencies),
                             [](auto a, auto b) { return std::max(a, b); });
    }

    for (auto& word1 : words1)
    {
      const auto word1_frequencies = frequencies(word1);
      const auto word1_is_universal = std::ranges::all_of(std::views::iota(std::size_t{0}, ALPHABET_SIZE), [&](auto i)
                                                          { return word1_frequencies[i] >= max_frequencies[i]; });

      if (word1_is_universal)
      {
        result.emplace_back(std::move(word1));
      }
    }

    return result;
  }

 private:
  std::array<std::size_t, ALPHABET_SIZE> frequencies(const std::string& word)
  {
    auto frequencies = std::array<std::size_t, ALPHABET_SIZE>{};
    for (auto c : word)
    {
      frequencies[c - 'a'] += 1;
    }
    return frequencies;
  }
};

int main()
{
  {
    const auto ans = Solution{}.wordSubsets({"amazon", "apple", "facebook", "google", "leetcode"}, {"e", "o"});
    const auto res = {"facebook", "google", "leetcode"};
    assert(ans.size() == res.size());
    assert(std::ranges::equal(ans, res));
  }
  {
    const auto ans = Solution{}.wordSubsets({"amazon", "apple", "facebook", "google", "leetcode"}, {"lc", "eo"});
    const auto res = {"leetcode"};
    assert(ans.size() == res.size());
    assert(std::ranges::equal(ans, res));
  }
  {
    const auto ans = Solution{}.wordSubsets({"acaac", "cccbb", "aacbb", "caacc", "bcbbb"}, {"c", "cc", "b"});
    const auto res = {"cccbb"};
    assert(ans.size() == res.size());
    assert(std::ranges::equal(ans, res));
  }
}
