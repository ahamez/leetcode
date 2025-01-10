cmake_minimum_required(VERSION 3.20)

project(LeetCode VERSION 1.0 LANGUAGES CXX)

find_package(Boost NO_MODULE)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-fsanitize=address -fno-omit-frame-pointer -g)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")
add_compile_options(-Wall -Wextra -Wpedantic -Wunused -Werror)

add_executable(2_add_two_numbers 2_add_two_numbers.cc)
add_executable(3_longest_substring_without_repeating_characters 3_longest_substring_without_repeating_characters.cc)
add_executable(155_min_stack 155_min_stack.cc)
add_executable(160_linked_lists_intersections 160_linked_lists_intersections.cc)
add_executable(211_word_data_structure 211_word_data_structure.cc)
add_executable(288_move_zeroes 288_move_zeroes.cc)
add_executable(322_coin_change 322_coin_change.cc)
add_executable(408_valid_word_abbreviation 408_valid_word_abbreviation.cc)
add_executable(622_circular_queue 622_circular_queue.cc)
add_executable(876_linked_list_middle 876_linked_list_middle.cc)
add_executable(1071_greatest_common_divisor_of_strings 1071_greatest_common_divisor_of_strings.cc)
add_executable(1160_find_words 1160_find_words.cc)
add_executable(1207_unique_number_of_occurrences 1207_unique_number_of_occurrences.cc)
add_executable(1452_favorite_company 1452_favorite_company.cc)
add_executable(2095_delete_middle_node 2095_delete_middle_node.cc)
add_executable(2451_odd_string_difference 2451_odd_string_difference.cc)
add_executable(2981_longest_special_substring 2981_longest_special_substring.cc)

add_executable(custom custom.cc)
add_executable(circular_queue circular_queue.cc)
add_executable(logs logs.cc)
target_include_directories(logs PRIVATE ${Boost_INCLUDE_DIRS})

add_custom_target(run)
add_dependencies(run
  2_add_two_numbers
                3_longest_substring_without_repeating_characters
                155_min_stack
                160_linked_lists_intersections
                211_word_data_structure
                288_move_zeroes
                322_coin_change
                408_valid_word_abbreviation
                622_circular_queue
                876_linked_list_middle
                1071_greatest_common_divisor_of_strings
                1160_find_words
                1207_unique_number_of_occurrences
                1452_favorite_company
                2095_delete_middle_node
                2451_odd_string_difference
                2981_longest_special_substring)
add_custom_command(TARGET run POST_BUILD
                   COMMAND 2_add_two_numbers
                   COMMAND 3_longest_substring_without_repeating_characters
                   COMMAND 155_min_stack
                   COMMAND 160_linked_lists_intersections
                   COMMAND 211_word_data_structure
                   COMMAND 288_move_zeroes
                   COMMAND 322_coin_change
                   COMMAND 408_valid_word_abbreviation
                   COMMAND 622_circular_queue
                   COMMAND 876_linked_list_middle
                   COMMAND 1071_greatest_common_divisor_of_strings
                   COMMAND 1160_find_words
                   COMMAND 1207_unique_number_of_occurrences
                   COMMAND 1452_favorite_company
                   COMMAND 2095_delete_middle_node
                   COMMAND 2451_odd_string_difference
                   COMMAND 2981_longest_special_substring)
