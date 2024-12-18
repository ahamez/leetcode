// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list

#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
 public:
  std::vector<int> peopleIndexes(std::vector<std::vector<std::string>> favoriteCompanies)
  {
    auto mapping = std::unordered_map<std::string, std::size_t>();
    auto counter = std::size_t{0};

    for (const auto& companies : favoriteCompanies)
    {
      for (const auto& company : companies)
      {
        if (auto [it, inserted] = mapping.emplace(company, counter); inserted)
        {
          ++counter;
        }
      };
    }

    auto favorite_companies_hash = std::vector<std::vector<std::size_t>>{};
    favorite_companies_hash.reserve(favoriteCompanies.size());
    std::ranges::transform(favoriteCompanies, std::back_inserter(favorite_companies_hash),
                           [&](const auto& companies)
                           {
                             auto company_hashes = std::vector<std::size_t>{};
                             company_hashes.reserve(companies.size());
                             std::ranges::transform(companies, std::back_inserter(company_hashes),
                                                    [&](const auto& company) { return mapping.at(company); });
                             std::ranges::sort(company_hashes);
                             return company_hashes;
                           });

    auto excluded_indices = std::vector<int>{};
    excluded_indices.reserve(favorite_companies_hash.size());
    for (std::size_t i = 0; i < favorite_companies_hash.size(); ++i)
    {
      for (std::size_t j = 0; j < favorite_companies_hash.size(); ++j)
      {
        if (i == j)
        {
          continue;
        }

        const auto& ci = favorite_companies_hash[i];
        const auto& cj = favorite_companies_hash[j];

        if (std::ranges::includes(cj, ci))
        {
          excluded_indices.push_back(i);
          break;
        }
      }
    }

    auto diff = std::vector<int>();
    diff.reserve(favoriteCompanies.size());

    auto all_indices = std::vector<int>(favoriteCompanies.size());
    std::iota(begin(all_indices), end(all_indices), 0);

    std::ranges::set_difference(all_indices, excluded_indices, std::back_inserter(diff));

    return diff;
  }
};

int main()
{
  auto fv = Solution{};

  {
    const auto companies = std::vector<std::vector<std::string>>{
        {{"leetcode", "google", "facebook"}, {"google", "microsoft"}, {"google", "facebook"}, {"google"}, {"amazon"}},
    };

    auto t0 = fv.peopleIndexes(companies);
    auto r0 = std::vector<int>({0, 1, 4});

    assert(t0.size() == r0.size());
    assert(std::equal(cbegin(t0), cend(t0), cbegin(r0)));
  }

  {
    const auto companies =
        std::vector<std::vector<std::string>>{{"arrtztkotazhufrsfczr", "knzgidixqgtnahamebxf", "zibvccaoayyihidztflj"},
                                              {"cffiqfviuwjowkppdajm", "owqvnrhuzwqohquamvsz"},
                                              {"knzgidixqgtnahamebxf", "owqvnrhuzwqohquamvsz", "qzeqyrgnbplsrgqnplnl"},
                                              {"arrtztkotazhufrsfczr", "cffiqfviuwjowkppdajm"},
                                              {"arrtztkotazhufrsfczr", "knzgidixqgtnahamebxf", "owqvnrhuzwqohquamvsz",
                                               "qzeqyrgnbplsrgqnplnl", "zibvccaoayyihidztflj"}};

    auto t0 = fv.peopleIndexes(companies);
    auto r0 = std::vector<int>({1, 3, 4});

    assert(t0.size() == r0.size());
    assert(std::equal(cbegin(t0), cend(t0), cbegin(r0)));
  }

  return 0;
}
