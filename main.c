#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#include "generic_vector.h"
#include "my_tree.h"



int main(int argc, char* argv[]) {

    // generic vector declarations
    GENERIC_VECTOR dictionary_vector[30] = {NULL};
    GENERIC_VECTOR selected_words, temp;

    // word length -> length of the scanned words
    // scan_check -> verification for scanf
    // chances -> track chances
    int word_length, scan_check, chances;

    // binary search tree declaration
    TREE key_tree;

    //string objects
    MY_STRING current_key = my_string_init_default();
    MY_STRING new_key = my_string_init_default();
    MY_STRING guess_vector;
    MY_STRING word = my_string_init_default();

    char choice, guess;

    // welcome message
    printf("Welcome to Evil Hangman!\n");

    // dictionary init vector
    FILE* fp = fopen("dictionary.txt", "r");
    
    if(fp == NULL){
        printf("No dictionary file found!");
        exit(1);
    }

    for(int i = 0;i < 30; i++){
        dictionary_vector[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    }
    
    while(my_string_extraction(word, fp)){
        word_length = my_string_get_size(word);
        generic_vector_push_back(dictionary_vector[word_length], word);
    }

    
    // game code
    choice = 'y';
    while(choice == 'y'){

        printf("What word length do you wish to use?\n");
        printf("The length should be between 2 and 29 letters with the exception of lengths 25, 26 and 27.\n");
        scan_check = scanf("%d", &word_length);
        while(scan_check == 0 || word_length > 29 || word_length < 2 || word_length == 25 || word_length == 26 || word_length == 27){
            clearKeyboardBuffer();
            printf("Please enter a valid word length!\n");
            printf("What word length do you wish to use?\n");
            printf("The length should be between 2 and 29 letters with the exception of lengths 25, 26 and 27.\n");
            scan_check = scanf("%d", &word_length);
        }

        // configure key length
        for(int i = 0; i < word_length; i++){
            my_string_push_back(current_key, '-');
        }
        
        printf("How many chances do you wish to have? Please enter a number greater than a zero.\n");
        scan_check = scanf("%d", &chances);
        while(scan_check == 0 || chances <= 0){
            clearKeyboardBuffer();
            printf("Please enter a valid chance count (greater than 0)!\n");
            printf("How many chances do you wish to have? Please enter a number greater than a zero.\n");
            scan_check = scanf("%d", &chances);
        }

        // load words
        selected_words = generic_vector_init_default(my_string_assignment, my_string_destroy);
        for(int i = 0; i < generic_vector_get_size(dictionary_vector[word_length]); i++){
            generic_vector_push_back(selected_words, generic_vector_at(dictionary_vector[word_length], i));
        }
        
        // init guess string
        guess_vector = my_string_init_default();

        // actual game loop
        while(chances != 0){

            // init key tree 
            key_tree = my_tree_init_default();

            // message prompt
            my_string_insertion(current_key, stdout);
            printf("\nUsed letters: ");
            my_string_insertion(guess_vector, stdout);
            printf("\nChances Left: %d\n", chances);
            printf("Take a guess: ");

            // error loop
            clearKeyboardBuffer();
            scan_check = scanf("%c", &guess);
            while(scan_check == 0){
                clearKeyboardBuffer();
                printf("\nPlease enter a valid guess: ");
                scan_check = scanf("%c", &guess);
                printf("\n");
            }
            printf("\n");

            // push guess into guess vector
            my_string_push_back(guess_vector, guess);
            my_string_push_back(guess_vector, ' ');

            // populate the tree 
            for(int i = 0; i < generic_vector_get_size(selected_words); i++){
                get_word_key_value(current_key, new_key, generic_vector_at(selected_words, i), guess);
                my_tree_insert(key_tree, new_key, generic_vector_at(selected_words, i));
            }

            // print_tree(key_tree);

            // return largest family
            temp = my_tree_return_largest_family(key_tree);

            // delete all words in selected_words
            while(generic_vector_pop_back(selected_words));

            // replace selected_words with temp
            for(int i = 0; i < generic_vector_get_size(temp); i++){
                generic_vector_push_back(selected_words, generic_vector_at(temp, i));
            }

            // update current key
            get_word_key_value(current_key, new_key, generic_vector_at(selected_words, 0), guess);

            // if the current key has not been updates, the guess is wrong
            if(my_string_compare(current_key, new_key) == 0){
                printf("Sorry. Your guess is incorrect!\n");
                chances--;
            }

            my_string_destroy(&current_key);
            current_key = my_string_init_c_string(my_string_c_str(new_key));

            // destroy tree
            my_tree_destroy_tree(&key_tree);

        
            // if the current key is the same as the word, the player successfully guessed the word
            if(my_string_compare(current_key, generic_vector_at(selected_words, 0)) == 0){
                printf("Congratulations! You sucessfully guessed: ");
                my_string_insertion(current_key, stdout);
                printf("\nYou win!!!\n\n");
                break;
            }

            // if the player ran out of chances, the word is revealed and the loop breaks
            if(chances == 0){
                printf("Sorry! You lose! The word was: ");
                my_string_insertion(generic_vector_at(selected_words, 0), stdout);
                printf("\n");
                break;
            }
        }

        

        while(my_string_pop_back(guess_vector));
        while(my_string_pop_back(current_key));
        while(my_string_pop_back(new_key));

        printf("Play again? Enter y for yes and any other letter key for no.\n");
        clearKeyboardBuffer();
        scanf("%c", &choice);
    }

    // destroy string objects
    my_string_destroy(&current_key);
    my_string_destroy(&new_key);
    my_string_destroy(&guess_vector);
    my_string_destroy(&word);

    //destroy generic vector
    generic_vector_destroy(&selected_words);

    // destroy generic vector objects
    for(int i = 0;i < 30; i++){
        generic_vector_destroy(&dictionary_vector[i]);
    }
    
    // close file pointer
    fclose(fp);
    return 0;
}

