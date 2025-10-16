#ifndef bst
#define bst
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int data;
    char* question;
    char* guess;
    struct node *right;
    struct node *left;
}node;

node* insert(node *root, int data, char *question, char *guess);

node* create_game_tree();

void printGameTree(node* root);

int printQuestionOrGuess(node *root);

void PlayGuessingGame(node* root);

#endif