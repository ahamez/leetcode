// https://leetcode.com/problems/design-add-and-search-words-data-structure

#include <algorithm>
#include <array>
#include <cassert>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

struct WordDictionary
{
  std::array<std::unique_ptr<WordDictionary>, 27> children;

  void addWord(std::string str) noexcept { addWord(cbegin(str), cend(str)); }

  void addWord(std::string::const_iterator word_cit, std::string::const_iterator word_cend) noexcept
  {
    if (word_cit == word_cend)
    {
      children[26] = std::make_unique<WordDictionary>();
    }
    else
    {
      const auto index_for_char = index_for(*word_cit);
      if (children[index_for_char] == nullptr)
      {
        children[index_for_char] = std::make_unique<WordDictionary>();
      }
      children[index_for_char]->addWord(std::next(word_cit), word_cend);
    }
  }

  bool search(std::string word) const noexcept { return search(cbegin(word), cend(word)); }

  bool search(std::string::const_iterator word_cit, std::string::const_iterator word_cend) const noexcept
  {
    if (word_cit == word_cend)
    {
      return children[26] ? true : false;
    }
    else if (*word_cit == '.')
    {
      return std::any_of(cbegin(children), cend(children),
                         [&](const auto& child)
                         {
                           if (child)
                           {
                             return child->search(std::next(word_cit), word_cend);
                           }
                           else
                           {
                             return false;
                           }
                         });
    }
    else
    {
      const auto index_for_char = index_for(*word_cit);
      if (children[index_for_char])
      {
        return children[index_for_char]->search(std::next(word_cit), word_cend);
      }
      else
      {
        return false;
      }
    }
  }

  auto words() const
  {
    auto words = std::vector<std::string>{};
    all_words(std::back_inserter(words), std::string{});
    return words;
  }

 private:
  std::size_t index_for(char c) const noexcept
  {
    assert(c >= 'a' and c <= 'z');
    return c - 'a';
  }
  std::size_t char_for_index(std::size_t index) const noexcept { return index + 'a'; }

  void all_words(auto back_inserter, std::string prefix) const
  {
    for (auto index = std::size_t{0}; index < 26; ++index)
    {
      const auto child = children[index].get();
      if (child)
      {
        const auto new_prefix = prefix + std::string(1, char_for_index(index));
        child->all_words(back_inserter, new_prefix);
      }
    }

    if (children[26])
    {
      back_inserter = std::move(prefix);
    }
  }
};

int main()
{
  auto wd = WordDictionary{};

  wd.addWord("leetcode");
  wd.addWord("leetcode");
  wd.addWord("leetui");
  wd.addWord("apple");

  assert(wd.words().size() == 3);

  assert(wd.search("leetcode") == true);
  assert(wd.search("le.e") == false);
  assert(wd.search("a...e") == true);
  assert(wd.search("apple") == true);
  assert(wd.search("a") == false);
  assert(wd.search("leetui") == true);
  assert(wd.search("ap") == false);

  return 0;
}
