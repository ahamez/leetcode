#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <boost/algorithm/string.hpp>

const auto input = R"(
L : event1 event2
Q1 : EVENT1; Q2:EVENT3
L: event3 event4 foo bar
L: event event
L: event1
Q3: event
L: event5 event6 EvEnt7 event3
)";

using query_id = std::string;

std::vector<query_id> matches(const std::string& log_line,
                              const std::vector<std::tuple<query_id, std::string>>& queries)
{
  auto matching_queries = std::vector<query_id>{};

  for (const auto& [id, query] : queries)
  {
    if (boost::icontains(log_line, query))
    {
      matching_queries.emplace_back(id);
    }
  }

  return matching_queries;
}

int main()
{
  auto queries = std::vector<std::tuple<query_id, std::string>>{};
  auto queries_split = std::vector<std::string>{};
  auto query_split = std::vector<std::string>{};

  auto stream = std::istringstream{input};
  auto line = std::string{};

  while (std::getline(stream, line))
  {
    switch (line[0])
    {
      case 'L':
      {
        if (const auto queries_id = matches(line, queries); queries_id.size() > 0)
        {
          std::cout << "Line " << line << "\nMatching queries: ";
          std::ranges::copy(queries_id, std::ostream_iterator<query_id>{std::cout, ","});
          std::cout << '\n';
        }
        break;
      }

      case 'Q':
      {
        boost::split(queries_split, line, boost::is_any_of(";"), boost::token_compress_on);

        for (const auto& query : queries_split)
        {
          boost::split(query_split, query, boost::is_any_of(":"), boost::token_compress_on);
          for (auto& part : query_split)
          {
            boost::algorithm::trim(part);
          }
          const auto query_id = query_split[0];
          const auto query_content = query_split[1];

          queries.emplace_back(query_id, query_content);
        }
      }
    }
  }

  return 0;
}
