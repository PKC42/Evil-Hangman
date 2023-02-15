#include <stddef.h>
#include <string.h>
#include "unit_test.h"
#include <stdio.h>

//test1
//verify that default string init function returns a non null value 
Status test_init_default_returns_nonNULL(char* buffer, int length)
{
   MY_STRING hString = NULL;
   hString = my_string_init_default();
   if(hString == NULL){
     strncpy(buffer, "test_init_default_returns_nonNULL\n"
     "my_string_init_default returns NULL", length);
     return FAILURE;
   }
   else{
     my_string_destroy(&hString);
     strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
     return SUCCESS;
   }
}

//test2
//verify that the size of the default string init function string is 0
Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   hString = my_string_init_default();
   
   if(my_string_get_size(hString) != 0){
     status = FAILURE;
     printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
     strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
     "Did not receive 0 from get_size after init_default\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
     , length);
   }
   
   my_string_destroy(&hString);
   return status;
}

//test3
//verify that the default capacity of the string is 7
Status test_pkc_get_capacity_on_init_default_returns_7(char* buffer, int length)
{
   MY_STRING hString = NULL;
   Status status;
   hString = my_string_init_default();
   
   if(my_string_get_capacity(hString) != 7){
     status = FAILURE;
     printf("Expected a capacity of 7 but got %d\n", my_string_get_size(hString));
     strncpy(buffer, "test_pkc_get_capacity_on_init_default_returns_7\n"
     "Did not receive 7 from get_capacity after init_default\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_get_capacity_on_init_default_returns_7\n", length);
   }
   
   my_string_destroy(&hString);
   return status;
}

//test4
//verify that the c_string init function does not return a non null value when used to initialize "Hello"
Status test_pkc_c_string_init_not_null(char* buffer, int length){

   MY_STRING hString = my_string_init_c_string("Hello");
   Status status; 
   
   if(hString == NULL){
     status = FAILURE;
     printf("hString should not be null!\n");
     strncpy(buffer, "test_pkc_c_string_init_not_null\n"
     "String does not have a non-NULL value\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_c_string_init_not_null\n", length);
   }
   
   my_string_destroy(&hString);
   return status;

}

//test5
//verify that the get size function works by making sure that the size of "Hello" is five 
Status test_pkc_c_string_init_size(char* buffer, int length){

   MY_STRING hString = my_string_init_c_string("Hello");
   Status status; 
   
   if(my_string_get_size(hString) != 5){
     status = FAILURE;
     printf("Size fo hello should be 5!\n");
     strncpy(buffer, "test_pkc_c_string_init_size\n"
     "The string size for hello is incorrect!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_c_string_init_size\n", length);
   }
   
   my_string_destroy(&hString);
   return status;

}

//test6
//Make sure the correct capacity is returned. The capacity is just size +1 therefore with hello the capacity should be 6
Status test_pkc_c_string_init_capacity(char* buffer, int length){

   MY_STRING hString = my_string_init_c_string("Hello");
   Status status; 
  
   
   if(my_string_get_capacity(hString) != 6){
     status = FAILURE;
     printf("Capacity for hello should be 6 (One greater than size)!\n");
     strncpy(buffer, "test_pkc_c_string_init_capacity\n"
     "The string capacity for hello is incorrect!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_c_string_init_capacity\n", length);
   }
   
   my_string_destroy(&hString);
   return status;

}

//test7
//verify the the left string is greater than right string (Hello vs Hi)
Status test_pkc_string_compare_left_is_greater_than_right(char* buffer, int length){

  MY_STRING hLeft_string = my_string_init_c_string("Apple");
  MY_STRING hRight_string = my_string_init_c_string("App");
  
  
  Status status;
  
   if(my_string_compare(hLeft_string, hRight_string) != 1){
     status = FAILURE;
     printf("The returned value is not -1. This indicates that the left string is greater or equal to the right string. This is incorrect!\n");
     strncpy(buffer, "test_pkc_string_compare_left_is_greater_than_right\n"
     "The returned value is incorrect. The returned value should be -1.\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_string_compare_left_is_greater_than_right\n", length);
   }
   
   my_string_destroy(&hLeft_string);
   my_string_destroy(&hRight_string);
   return status;

}

//test8
//Verify that the right string is greater that the left string (Hi vs Hello)
Status test_pkc_string_compare_right_is_greater_than_left(char* buffer, int length){

  MY_STRING hLeft_string = my_string_init_c_string("App");
  MY_STRING hRight_string = my_string_init_c_string("Apple");
   
  Status status;
  
   if(my_string_compare(hLeft_string, hRight_string) != -1){
     status = FAILURE;
     printf("The returned value is not -1. This indicates that the right string is greater or equal to the left string. This is incorrect!\n");
     strncpy(buffer, "test_pkc_string_compare_right_is_greater_than_left\n"
     "The returned value is incorrect. The returned value should be -1.\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_string_compare_right_is_greater_than_left\n", length);
   }
   
   my_string_destroy(&hLeft_string);
   my_string_destroy(&hRight_string);
   return status;

}

//test9
//verify that the strings are the same (Hi vs Hi)
Status test_pkc_string_compare_strings_are_equal(char* buffer, int length){

  MY_STRING hLeft_string = my_string_init_c_string("Hi");
  MY_STRING hRight_string = my_string_init_c_string("Hi");
  
  Status status;
  
   if(my_string_compare(hLeft_string, hRight_string) != 0){
     status = FAILURE;
     printf("The returned value is not 0. This indicates that the right string is not equal to the left string. This is incorrect!\n");
     strncpy(buffer, "test_pkc_string_compare_strings_are_equal\n"
     "The returned value is incorrect. The returned value should be 0.\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_string_compare_strings_are_equal\n", length);
   }
   
   my_string_destroy(&hLeft_string);
   my_string_destroy(&hRight_string);
   return status;

}

//test10
//this function tests the comparison funciton when given two words of the same length that are different. Bob is greater than Ant as B>A therefore the return value should be 1.
Status test_pkc_string_compare_strings_are_equal_length_different_word(char* buffer, int length){

  MY_STRING hLeft_string = my_string_init_c_string("Ant");
  MY_STRING hRight_string = my_string_init_c_string("Bob");
  
  Status status;
  
   if(my_string_compare(hLeft_string, hRight_string) != -1){
     status = FAILURE;
     printf("The returned value is not -1. This indicates that the right string is less than or equal to the left string. This is incorrect!\n");
     strncpy(buffer, "test_pkc_string_compare_strings_are_equal\n"
     "The returned value is incorrect. The returned value should be -1.\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_string_compare_strings_are_equal_length_different_word\n", length);
   }
   
   my_string_destroy(&hLeft_string);
   my_string_destroy(&hRight_string);
   return status;



}


//test11
//make sure that the function is able to open the dictionary file and return success 
Status test_pkc_verify_my_string_extraction(char* buffer, int length){


   MY_STRING hString = my_string_init_default(); 
   Status status;
   FILE* fp = fopen("dictionary.txt", "r"); 
  
   if(my_string_extraction(hString, fp) == FAILURE){
     status = FAILURE;
     printf("The function failed. This may be due to the file being empty, unable to be opened or non-existent!\n");
     strncpy(buffer, "test_pkc_verify_my_string_extraction\n"
     "my_string_extraction function failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_verify_my_string_extraction\n", length);
   }
   
   fclose(fp); 
   my_string_destroy(&hString);
   
   return status;
}

//test12
//Verify that failure is returned when the string is empty
Status test_pkc_verify_my_string_extraction_empty(char* buffer, int length){

   MY_STRING hString = my_string_init_default(); 
   Status status;
   FILE* fp = fopen("empty.txt", "r"); 
  
   if(my_string_extraction(hString, fp) == SUCCESS){
     status = FAILURE;
     printf("The function should return failure as the file opened should be empty!\n");
     strncpy(buffer, "test_pkc_verify_my_string_extraction_empty\n"
     "test_pkc_verify_my_string_extraction_empty failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_verify_my_string_extraction_empty\n", length);
   }
   
   fclose(fp); 
   my_string_destroy(&hString);
   
   return status;
}

//test13
//this should verify that my string insertion should work if a non null string is passed as a parameter
Status test_pkc_verify_my_string_insertion_success_check(char* buffer, int length){
    
    MY_STRING hString = my_string_init_c_string("Hello");
    Status status;

   if(my_string_insertion(hString, stdout) == FAILURE){
     status = FAILURE;
     printf("The function should return success as the parameter is a valid string!\n");
     strncpy(buffer, "\ntest_pkc_verify_my_string_insertion_success_check\n"
     "test_pkc_verify_my_string_insertion_success_check failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "\ntest_pkc_verify_my_string_insertion_success_check\n", length);
   }
  
   my_string_destroy(&hString);
   
   return status;
}

//this should turn Apple to Apples by adding s. If successful, the my_string_compare function should return 0 therefore veryfying the my_string_push_back function 
Status test_pkc_my_string_push_back_apple_to_apples(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apple");
    MY_STRING copy = my_string_init_c_string("Apples");
    Status status;
    char item = 's'; 
    my_string_push_back(hString, item); 
    
    
    
   if(my_string_compare(hString, copy) != 0){
     status = FAILURE;
     printf("The push function did not change Apple to Apples therefore it did not work!\n");
     strncpy(buffer, "test_pkc_my_string_push_back_apple_to_apples\n"
     "test_pkc_my_string_push_back_apple_to_apples failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_push_back_two_letters\n", length);
   }
  
   my_string_destroy(&hString);
   my_string_destroy(&copy); 
   
   return status;
}

//this function should return failure if the string size pushed into the pop_back function is zero
Status test_pkc_my_string_pop_back_0(char* buffer, int length){

    MY_STRING hString = my_string_init_default();
    Status status;
    
   if(my_string_pop_back(hString) != FAILURE){
     status = FAILURE;
     printf("The pop function did not work as it did not return failure for popping back a string with size 0!\n");
     strncpy(buffer, "test_pkc_my_string_pop_back_0\n"
     "test_pkc_my_string_push_back_0 failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_pop_back_0\n", length);
   }
  
   my_string_destroy(&hString);
   
   return status;
}

//this function should change apples to apple using the my_string_pop_back function 
Status test_pkc_my_string_pop_back_apples_to_apple(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apples");
    MY_STRING copy = my_string_init_c_string("Apple");
    Status status;
    
    my_string_pop_back(hString);
    
    int result = my_string_compare(hString, copy); 
    
    
   if(result != 0){
     status = FAILURE;
     printf("The pop function did not change Apples to Apple therefore it did not work!\n");
     strncpy(buffer, "test_pkc_my_string_push_back_apples_to_apple\n"
     "test_pkc_my_string_push_back_apples_to_apple failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_push_back_apples_to_apple\n", length);
   }
  
   my_string_destroy(&hString);
   my_string_destroy(&copy); 
   
   return status;
}

//this function using pop and push in conjunction to verify that both work together without issue  
Status test_pkc_my_string_push_back_apple_to_apples_to_app(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apple");
    MY_STRING copy = my_string_init_c_string("App");
    Status status;
    char item = 's'; 
    
    my_string_push_back(hString, item);
    my_string_pop_back(hString);
    my_string_pop_back(hString);
    my_string_pop_back(hString);
    
    int result = my_string_compare(hString, copy); 
    
    
   if(result != 0){
     status = FAILURE;
     printf("Apple should have been changed to apples which should have been changed to app. An error occured and hString and App are not equal!\n");
     strncpy(buffer, "test_pkc_my_string_push_back_apple_to_apples_to_app\n"
     "test_pkc_my_string_push_back_apple_to_apples_to_app failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_push_back_apple_to_apples_to_app\n", length);
   }
  
   my_string_destroy(&hString);
   my_string_destroy(&copy); 
   
   return status;
}

//my_string_at should return the address at a particular index of a string. Since 10 is out of range, the returned value should be NULL
Status test_pkc_my_string_at_out_of_range(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apple");
    Status status;
    char* c = NULL;
    c = my_string_at(hString, 10);
   if(c != NULL){
     status = FAILURE;
     printf("Index 10 is out of range. The returned value should be NULL\n");
     strncpy(buffer, "test_pkc_my_string_at_out_of_range\n"
     "test_pkc_my_string_at_out_of_range failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_at_out_of_range\n", length);
   }
  
   my_string_destroy(&hString);
   return status;
  
}

//index 2 should be within range therefore a valid address should be returned 
Status test_pkc_my_string_at_within_range(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apple");
    Status status;
    
   if(my_string_at(hString, 2) == NULL){
     status = FAILURE;
     printf("Index 2 is within range. The returned value should not be NULL\n");
     strncpy(buffer, "test_pkc_my_string_at_within_range\n"
     "test_pkc_my_string_at_within_range failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_at_within_range\n", length);
   }
  
   my_string_destroy(&hString);
  
   return status;
  
}

//if the returned address is not NULL, the function works. Else, the function does not work 
Status test_pkc_my_string_c_str_first_index_address_return(char* buffer, int length){

    MY_STRING hString = my_string_init_c_string("Apple");
    Status status;
    
   if(my_string_c_str(hString) == NULL){
     status = FAILURE;
     printf("The input size and capacity are incorrect.\n");
     strncpy(buffer, "test_pkc_my_string_c_str_first_index_address_return\n"
     "test_pkc_my_string_c_str_first_index_address_return failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_my_string_c_str_first_index_address_return\n", length);
   }
  
   my_string_destroy(&hString);
  
   return status;
   
}

//concate apple and pie to form apple pie 
Status test_pkc_concat_apple_pie(char* buffer, int length){

   MY_STRING hResult = my_string_init_c_string("Apple");
   MY_STRING hAppend = my_string_init_c_string(" Pie");
   MY_STRING copy = my_string_init_c_string("Apple Pie");
 
    Status status;
    
    my_string_concat(hResult, hAppend);   

   if(my_string_compare(hResult, copy) != 0){
     status = FAILURE;
     printf("The concat function failed to properly append the strings together to form apple pie!\n");
     strncpy(buffer, "test_pkc_concat_apple_pie\n"
     "test_pkc_concat_apple_pie failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_concat_apple_pie\n", length);
   }
  
   my_string_destroy(&hResult);
   my_string_destroy(&hAppend);
   my_string_destroy(&copy);
  
   return status;

}

//this function will concat apple and pie and push a ! to the end. This will make sure that the sizing is correct after the functions execute
Status test_pkc_concat_and_push(char* buffer, int length){

   MY_STRING hResult = my_string_init_c_string("Apple");
   MY_STRING hAppend = my_string_init_c_string(" Pie");
   MY_STRING copy = my_string_init_c_string("Apple Pie!");
 
    Status status;
    
    my_string_concat(hResult, hAppend);   
    my_string_push_back(hResult, '!');

   if(my_string_compare(hResult, copy) != 0){
     status = FAILURE;
     printf("Either the concat function or push function failed to properly resize so that compare will return 0 confirming a match.\n");
     strncpy(buffer, "test_pkc_concat_and_push\n"
     "test_pkc_concat_and_push failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_concat_and_push\n", length);
   }
  
   my_string_destroy(&hResult);
   my_string_destroy(&hAppend);
   my_string_destroy(&copy);
  
   return status;

}

//Test is string is empty 
Status test_pkc_is_string_empty(char* buffer, int length){

  MY_STRING hString = my_string_init_default(); 
  Status status;
  
  if(my_string_empty(hString) == FALSE){
     status = FAILURE;
     printf("It should return true as the string is empty.\n");
     strncpy(buffer, "test_pkc_is_string_empty\n"
     "test_pkc_is_string_empty failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_is_string_empty\n", length);
   }
  
  
   my_string_destroy(&hString);
  
   return status;
  
}

//this function checks if the string is not empty 
Status test_pkc_is_string_not_empty(char* buffer, int length){

  MY_STRING hString = my_string_init_c_string("Stuff");; 
  Status status;
  
  if(my_string_empty(hString) == TRUE){
     status = FAILURE;
     printf("It should return False as the string is not empty.\n");
     strncpy(buffer, "test_pkc_is_string_not_empty\n"
     "test_pkc_is_string_not_empty failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_is_string_not_empty\n", length);
   }
  
  
   my_string_destroy(&hString);
  
   return status;
  
}

//check if string has been properly destroyed (must equal NULL)
Status test_pkc_is_string_destroyed(char* buffer, int length){

  MY_STRING hString = my_string_init_c_string("Stuff");
  Status status;
  
  my_string_destroy(&hString);
  
  if(hString != NULL){
     status = FAILURE;
     printf("The string is not NULL. The string has not been destroyed.\n");
     strncpy(buffer, "test_pkc_is_string_destroyed\n"
     "test_pkc_is_string_destroyed failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_is_string_destroyed\n", length);
   }

  return status;  

}

Status test_pkc_is_find_key_check(char* buffer, int length){

  Status status;
  MY_STRING current_word_family, new_key, word = NULL;

  word = my_string_init_c_string("applepie");
  current_word_family = my_string_init_c_string("a--le-ie");
  new_key = my_string_init_default();


  get_word_key_value(current_word_family, new_key, word, 'p');

  

  if(my_string_compare(new_key, word) != 0){
     status = FAILURE;
     printf("Strings do not match\n");
     strncpy(buffer, "test_pkc_is_find_key_check\n"
     "test_pkc_is_find_key_check failed!\n", length);
   }
   else{
     status = SUCCESS;
     strncpy(buffer, "test_pkc_is_find_key_check\n", length);
   }

   printf("\nResult: ");
   my_string_insertion(new_key, stdout);
   printf("\n");

   return status;
}



