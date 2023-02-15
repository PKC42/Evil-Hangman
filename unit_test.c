#include <stdio.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
   {
     test_init_default_returns_nonNULL,
     test_get_size_on_init_default_returns_0,
     test_pkc_get_capacity_on_init_default_returns_7,
     test_pkc_c_string_init_not_null,
     test_pkc_c_string_init_size,
     test_pkc_c_string_init_capacity,
     test_pkc_string_compare_left_is_greater_than_right,
     test_pkc_string_compare_right_is_greater_than_left,
     test_pkc_string_compare_strings_are_equal,
     test_pkc_string_compare_strings_are_equal_length_different_word,
     test_pkc_verify_my_string_extraction,
     test_pkc_verify_my_string_extraction_empty,
     test_pkc_verify_my_string_insertion_success_check,
     test_pkc_my_string_push_back_apple_to_apples,
     test_pkc_my_string_pop_back_0,
     test_pkc_my_string_pop_back_apples_to_apple,
     test_pkc_my_string_push_back_apple_to_apples_to_app,
     test_pkc_my_string_at_out_of_range,
     test_pkc_my_string_at_within_range,
     test_pkc_my_string_c_str_first_index_address_return,
     test_pkc_concat_apple_pie,
     test_pkc_concat_and_push,
     test_pkc_is_string_empty,
     test_pkc_is_string_not_empty,
     test_pkc_is_string_destroyed,
     test_pkc_is_find_key_check
   };
   
   int number_of_functions = sizeof(tests) / sizeof(tests[0]);
   int i;
   char buffer[500];
   int success_count = 0;
   int failure_count = 0;
 
   for(i=0; i<number_of_functions; i++){
     if(tests[i](buffer, 500) == FAILURE){
       printf("FAILED: Test %d failed miserably\n",i);
       printf("\t%s\n", buffer);
       failure_count++;
       }
     else{
       printf("PASS: Test %d passed\n", i);
       printf("\t%s\n", buffer);
       success_count++;
       }
     }
 
   printf("Total number of tests: %d\n", number_of_functions);
   printf("%d/%d Pass, %d/%d Failure\n", success_count,
   number_of_functions, failure_count, number_of_functions);
   return 0;
}