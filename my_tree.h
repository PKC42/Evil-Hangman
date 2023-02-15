#ifndef my_tree_h
#define my_tree_h

#include <stdio.h>

#include "my_string.h"
#include "generic_vector.h"


typedef void *TREE;

typedef struct node Node;

struct node{
    Node* left_child;
    Node* right_child;
    MY_STRING key;
    GENERIC_VECTOR words;
};

typedef struct my_tree{
    Node *root;
} my_tree;

TREE my_tree_init_default(void);

void my_tree_insert(TREE _tree, MY_STRING key, MY_STRING word);

void my_tree_destroy_tree(TREE *_tree);

void destroy_tree_node(Node* node);

GENERIC_VECTOR my_tree_return_largest_family(TREE _tree);

GENERIC_VECTOR my_tree_return_largest_family_search(Node* node);

void print_tree(TREE _tree);

void print_node(Node* node);

#endif