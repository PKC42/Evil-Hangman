#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 


void clearKeyboardBuffer(void) {							
    char ch;
    int ret;
    ret = scanf("%c", &ch);
    while (ret == 1 && ch != '\n' && ch != '\0') {
        ret = scanf("%c", &ch);
    }
}

MY_STRING my_string_init_default(void){

    My_String* string = (My_String*)malloc(sizeof(My_String));

    if(string != NULL){
        string->size = 0;
        string->capacity = 7;
        string->data = (char*)calloc(string->capacity, sizeof(char));
        if(string->data == NULL){
            printf("Memory Allocation Failed!\n");
            free(string->data);
            free(string);
            exit(1);
        }
        return (MY_STRING)string; 
    }
    else{
        printf("Memory Allocation Failed!\n");
        free(string);
        exit(1);
    }
}

void my_string_destroy(Item* pItem){
    My_String* string = (My_String*) * pItem;
    free(string->data);
    free(string);
    *pItem = NULL;
}

MY_STRING  my_string_init_c_string(const char* c_string){
    My_String* string = (My_String*)malloc(sizeof(My_String));
    
    int size = 0; 

    for(int i = 0; c_string[i] != '\0'; i++){
        size++;
    }
    if(string != NULL){
        string->size = size;
        string->capacity = size + 1;
        string->data = (char*)calloc(string->capacity, sizeof(char));
        if(string->data == NULL){
            printf("Memory Allocation Failed!\n");
            free(string->data);
            free(string);
            exit(1);
        }
        
        for(int i = 0; i < string->size; i++){
            string->data[i] = c_string[i];
        }

        string->data[string->size] = '\0';

        return (MY_STRING)string; 
    }
    else{
        printf("Memory Allocation Failed!\n");
        free(string);
        exit(1);
    }
}

int my_string_get_capacity(MY_STRING hMy_string){
    My_String* string = (My_String*)hMy_string;
    return string->capacity;
}

int my_string_get_size(MY_STRING hMy_string){
    My_String* string = (My_String*)hMy_string;
    return string->size;
}

int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string){
    My_String* left_string = (My_String*)hLeft_string;
    My_String* right_string = (My_String*)hRight_string; 

    for(int i = 0; i < left_string->size && i < right_string->size; i++){
        if(left_string->data[i] < right_string->data[i]){
            return -1; 
        }
        else if(left_string->data[i] > right_string->data[i]){
            return 1; 
        }
    }

    if(left_string->size < right_string->size){
        return -1;
    }

    if(left_string->size > right_string->size){
        return 1; 
    }

    return 0;
}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp){
    My_String* string = (My_String*)hMy_string;
    char c = fgetc(fp);
    
    // reset string size
    string->size = 0;

    // consume all leading white spaces
    while(c == ' '){
        c = fgetc(fp);
    }

    if(c == EOF){
        return FAILURE;
    }
    
    while(c != ' ' && c != '\n' && c != EOF){
        my_string_push_back(hMy_string, c);
        c = fgetc(fp);

    }

    // ungetc(c, fp);
    // my_string_c_str(hMy_string);
    
    return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp){
    My_String* string = (My_String*)hMy_string;

    if(string == NULL){
        return FAILURE;
    }

    if(string->size == 0 || string->data == NULL){
        return FAILURE; 
    }
    else {
        for(int i = 0; i < string->size; i++){
            fprintf(fp, "%c", string->data[i]);
        }
    }
    return SUCCESS;
}

Status my_string_push_back(MY_STRING hMy_string, char item){
    My_String* string = (My_String*)hMy_string;
    
    if(string->size >= string->capacity){
            string->data = (char*)realloc(string->data, string->capacity*2);
            string->capacity *= 2;
            if (string->data == NULL) {
                printf("Memory Allocation Failed!\n");
                exit(1);
            }
    }

    string->size += 1;
    string->data[string->size-1] = item;

    for(int i = string->size; i < string->capacity; i++){
        string->data[i] = '\0';
    }

    return SUCCESS;
}

Status my_string_pop_back(MY_STRING hMy_string){
    My_String* string =(My_String*) hMy_string;
    if(string->size == 0){
        return FAILURE;
    }
    string->size -= 1;
    my_string_c_str(hMy_string);
    return SUCCESS;
}

char* my_string_at(MY_STRING hMy_string, int index){
    My_String* string =(My_String*) hMy_string;
    printf("This is the index: %d This is the string size: %d\n", index, string->size);
    if(index >= string->size){
        return NULL;
    }

    return &(string->data[index]);
}

char* my_string_c_str(MY_STRING hMy_string){
    My_String* string = (My_String*)hMy_string;

    string->data[string->size] = '\0';
    return &(string->data[0]);
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend){
    My_String* result = (My_String*)hResult;
    My_String* append = (My_String*)hAppend;
    int sum = result->size + append->size;

    if(sum >= result->capacity){
        result->data = (char*)realloc(result->data, result->capacity + append->size + 1);
            result->capacity += append->size + 1;
            if (result->data == NULL) {
                printf("Memory Allocation Failed!\n");
                exit(1);
            }
    }

    for(int i = 0; i < append->size; i++){
        my_string_push_back(hResult, append->data[i]);
    }

    return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string){
    
    if(my_string_get_size(hMy_string) != 0){
        return FALSE;
    }
    else {
        return TRUE;
    }
}

void my_string_assignment(Item* pLeft, Item Right){
	My_String* left = (My_String*)*pLeft;
	My_String* right = (My_String*)Right;

	if(left == NULL){
		left = (My_String*)malloc(sizeof(My_String));
        left->size = right->size;
		left->capacity = right->capacity;
		left->data = (char*)malloc(sizeof(char) * left->capacity);
		if(left->data == NULL){
			free(left->data);
			return;
		}

		for(int i = 0; i < left->size; i++){
			left->data[i] = right->data[i];
		}
		*pLeft = left;
	}
}


Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess){
    My_String* cKey = (My_String*)current_word_family;
    My_String* nKey = (My_String*)new_key;
    My_String* cWord = (My_String*)word;

    Status status;

    nKey->size = 0;

    for(int i = 0; i < cKey->size; i++){
       status = my_string_push_back(new_key, cKey->data[i]);
       if(status == FAILURE){
            return FAILURE;
       }
    }

    for(int i = 0; i < cWord->size; i++){
        if(cWord->data[i] == guess){
            nKey->data[i] = cWord->data[i];
        }
    }

    return SUCCESS;
}

char my_string_at2(MY_STRING word, int i){
    My_String *string = (My_String*)word;
    return string->data[i];
}