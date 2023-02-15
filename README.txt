Evil Hangman
----------------------------------------------------------------------------------------------------------------------------------------

Evil Hangman is a game that cheats to prevent the player from winning by switching words. To accomplish this, the Evil Hangman project
utlizes vectors and a binary search tree implemented in C. In order to facilitate the switching, the current combination of selected letters
along with the guess is used to sort words into separate families.

For example:
- If the current chose combo (key) is a---- and the guess is p, the some potential families are
- app-- which works for apple, apply, appal, apple
- a--p- which works for adapt, adept

To give the program the best chance of success, only the largest families are chosen. These families are sorted using a binary search tree
with a generic vector of words which improves insertion time over other data structures such as lists.

A good strategy for this game is to guess all the vowels and fill in the blanks. Another strategy is to select a word length that is rare (29 for example).

Outcome: The game is sucessful in thwarting the player provided that the player selects a common word length and has a reasonable number of chances.

Issues:
    - a number of bytes are lost during the tree node insertion operation causing a memory leak

Files included:

main.C
generic.h
generic_vector.c
generic_vector.h
status_and_bool.h
my_string.c
my_string.h
my_tree.h
my_tree.c
test_def.c
unit_test.c
unit_test.h
Makefile
dictinary.txt
empty.txt
simple.txt


