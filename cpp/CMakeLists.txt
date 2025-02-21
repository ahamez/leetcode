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
add_executable(17_phone_number_letter_combinations 17_phone_number_letter_combinations.cc)
add_executable(104_maximum_binary_tree_depth 104_maximum_binary_tree_depth.cc)
add_executable(125_valid_palindrome 125_valid_palindrome.cc)
add_executable(136_single_number 136_single_number.cc)
add_executable(155_min_stack 155_min_stack.cc)
add_executable(160_linked_lists_intersections 160_linked_lists_intersections.cc)
add_executable(206_reverse_linked_list 206_reverse_linked_list.cc)
add_executable(211_word_data_structure 211_word_data_structure.cc)
add_executable(242_valid_anagram 242_valid_anagram.cc)
add_executable(288_move_zeroes 288_move_zeroes.cc)
add_executable(322_coin_change 322_coin_change.cc)
add_executable(338_counting_bits 338_counting_bits.cc)
add_executable(345_reverse_string_vowels 345_reverse_string_vowels.cc)
add_executable(392_is_subsequence 392_is_subsequence.cc)
add_executable(408_valid_word_abbreviation 408_valid_word_abbreviation.cc)
add_executable(435_non_overlapping_intervals 435_non_overlapping_intervals.cc)
add_executable(622_circular_queue 622_circular_queue.cc)
add_executable(643_maximum_average_subarray 643_maximum_average_subarray.cc)
add_executable(700_search_in_a_bst 700_search_in_a_bst.cc)
add_executable(760_find_anagram_mappings 760_find_anagram_mappings.cc)
add_executable(876_linked_list_middle 876_linked_list_middle.cc)
add_executable(916_word_subsets 916_word_subsets.cc)
add_executable(933_number_of_recent_calls 933_number_of_recent_calls.cc)
add_executable(1071_greatest_common_divisor_of_strings 1071_greatest_common_divisor_of_strings.cc)
add_executable(1160_find_words 1160_find_words.cc)
add_executable(1207_unique_number_of_occurrences 1207_unique_number_of_occurrences.cc)
add_executable(1452_favorite_company 1452_favorite_company.cc)
add_executable(1732_highest_altitude 1732_highest_altitude.cc)
add_executable(1768_merge_strings_alernately 1768_merge_strings_alernately.cc)
add_executable(2095_delete_middle_node 2095_delete_middle_node.cc)
add_executable(2215_difference_of_two_arrays 2215_difference_of_two_arrays.cc)
add_executable(2390_removing_stars_from_a_string 2390_removing_stars_from_a_string.cc)
add_executable(2451_odd_string_difference 2451_odd_string_difference.cc)
add_executable(2981_longest_special_substring 2981_longest_special_substring.cc)

add_executable(custom custom.cc)
add_executable(circular_queue circular_queue.cc)
add_executable(logs logs.cc)
add_executable(sliding_window_sum sliding_window_sum.cc)
target_include_directories(logs PRIVATE ${Boost_INCLUDE_DIRS})
