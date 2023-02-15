#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length);
Status test_get_size_on_init_default_returns_0(char* buffer, int length);
Status test_pkc_get_capacity_on_init_default_returns_7(char* buffer, int length);
Status test_pkc_c_string_init_not_null(char* buffer, int length);
Status test_pkc_c_string_init_size(char* buffer, int length);
Status test_pkc_c_string_init_capacity(char* buffer, int length);
Status test_pkc_string_compare_left_is_greater_than_right(char* buffer, int length);
Status test_pkc_string_compare_right_is_greater_than_left(char* buffer, int length);
Status test_pkc_string_compare_strings_are_equal(char* buffer, int length);
Status test_pkc_string_compare_strings_are_equal_length_different_word(char* buffer, int length);
Status test_pkc_verify_my_string_extraction(char* buffer, int length);
Status test_pkc_verify_my_string_extraction_empty(char* buffer, int length);
Status test_pkc_verify_my_string_insertion_success_check(char* buffer, int length);
Status test_pkc_my_string_push_back_apple_to_apples(char* buffer, int length);
Status test_pkc_my_string_pop_back_0(char* buffer, int length);
Status test_pkc_my_string_pop_back_apples_to_apple(char* buffer, int length);
Status test_pkc_my_string_push_back_apple_to_apples_to_app(char* buffer, int length);
Status test_pkc_my_string_at_out_of_range(char* buffer, int length);
Status test_pkc_my_string_at_within_range(char* buffer, int length);
Status test_pkc_my_string_c_str_first_index_address_return(char* buffer, int length);
Status test_pkc_concat_apple_pie(char* buffer, int length);
Status test_pkc_concat_and_push(char* buffer, int length);
Status test_pkc_is_string_empty(char* buffer, int length);
Status test_pkc_is_string_not_empty(char* buffer, int length);
Status test_pkc_is_string_destroyed(char* buffer, int length);
Status test_pkc_is_find_key_check(char* bufer, int length);

#endif