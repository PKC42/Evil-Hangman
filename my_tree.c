#include "my_tree.h"

// initialize the root node
TREE my_tree_init_default(void){
    my_tree* tree = (my_tree*)malloc(sizeof(my_tree));
    
    if(tree == NULL){
        printf("Unable to allocate memory for tree initialization!");
        exit(1);
    }

    tree->root = NULL;
    return tree;
}


// add nodes to tree
// add to root first if root is null
void my_tree_insert(TREE _tree, MY_STRING key, MY_STRING word){
    my_tree* tree = (my_tree*)_tree;
    if(tree->root == NULL){
        tree->root = (Node*)malloc(sizeof(Node));
        if(tree->root == NULL){
            printf("Unable to allocate memory for tree node!");
            exit(1);
        }
        
        (tree->root)->left_child = NULL;
        (tree->root)->right_child = NULL;
        (tree->root)->words = generic_vector_init_default(my_string_assignment, my_string_destroy);
        (tree->root)->key = my_string_init_c_string(my_string_c_str(key));
        generic_vector_push_back(tree->root->words, word);
    }
    else{

        if(my_string_compare((tree->root)->key, key) == -1){
            my_tree_insert(&(tree->root)->left_child, key, word);
        }

        if(my_string_compare((tree->root)->key, key) == 0){
            generic_vector_push_back((tree->root)->words, word);
        }

        if(my_string_compare((tree->root)->key, key) == 1){
            my_tree_insert(&(tree->root)->right_child, key, word);
        }
    }
}

// destroy the full tree
void my_tree_destroy_tree(TREE *_tree){
    my_tree* tree = (my_tree*) *_tree;

    if(tree->root != NULL){
        if((tree->root)->left_child != NULL){
            destroy_tree_node((tree->root)->left_child);
        }

        if((tree->root)->right_child != NULL){
            destroy_tree_node((tree->root)->right_child);
        }

        my_string_destroy(&tree->root->key);
        generic_vector_destroy(&tree->root->words);
        free(tree->root);
    }

    free(tree);
    tree = NULL;
}

// destroy each node (to be used as a helper function for my_tree_destroy_tree)
void destroy_tree_node(Node* node){
    if(node == NULL){
        return;
    }

    if(node->words != NULL){
        generic_vector_destroy(&node->words);
    }

    destroy_tree_node(node->left_child);
    destroy_tree_node(node->right_child);

    free(node);
    node = NULL;
}


// return the largest family from the tree
GENERIC_VECTOR my_tree_return_largest_family(TREE _tree){
    my_tree *tree = (my_tree*)_tree;
    return my_tree_return_largest_family_search(tree->root);
}

// traverse the tree using recursion
GENERIC_VECTOR my_tree_return_largest_family_search(Node* node){
    GENERIC_VECTOR returned_vector = NULL;

    if(node != NULL){

            if(node->left_child != NULL){
                returned_vector = my_tree_return_largest_family_search(node->left_child);
                if(returned_vector != NULL){
                    if(generic_vector_get_size(returned_vector) < generic_vector_get_size(node->words)){
                        returned_vector = node->words;
                    }
                }
                else{
                    returned_vector = node->words;
                }
            }
            
            if(node->right_child != NULL){
                returned_vector = my_tree_return_largest_family_search(node->right_child);
                if(returned_vector != NULL){
                    if(generic_vector_get_size(returned_vector) < generic_vector_get_size(node->words)){
                        returned_vector = node->words;
                    }
                }
                else{
                    returned_vector = node->words;
                }
            }
            
            if(returned_vector != NULL){
                if(generic_vector_get_size(returned_vector) < generic_vector_get_size(node->words)){
                    returned_vector = node->words;
                }
            }
            else{
                    return node->words;
            }
    }

    return returned_vector;
}

// function to see tree nodes (for testing purposes)
void print_tree(TREE _tree){
    my_tree *tree = (my_tree*) _tree;
    
    if(tree->root == NULL){
        return;
    }

    if(tree->root->left_child != NULL){
        print_node(tree->root->left_child);
    }

    if(tree->root->right_child != NULL){
        print_node(tree->root->right_child);
    }

    my_string_insertion(tree->root->key, stdout);
    printf(" Size: %d\n", generic_vector_get_size(tree->root->words));

}

// helper function for print_tree(TREE _tree);
void print_node(Node* node){
    my_string_insertion(node->key, stdout);
    printf(" Size: %d\n", generic_vector_get_size(node->words));
    printf("\n");

    if(node->left_child != NULL){
        print_node(node->left_child);
    }

    if(node->right_child != NULL){
        print_node(node->right_child);
    }

}
