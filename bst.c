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


/*
Recursively adds a node
If the node is null, set the root to the new node
Else, check the data values and add it to the appropriate spot
*/ 
node* insert(node *root, int data, char *question, char *guess){
    if(root == NULL){
        node *newNode = malloc(sizeof(node));
        newNode->question = question;
        newNode->data = data;
        newNode->guess = guess;
        newNode->left = NULL;
        newNode->right = NULL;
        root = newNode;
        return root;
    }else if(root->data < data){
        root->left = insert(root->left, data, question, guess);
    }else{
        root->right = insert(root->right, data, question, guess);
    }

    return root;
}

/*
Just used to create the original tree, added because it was shown in the instruction set
*/
node* create_game_tree(){
    node* root = NULL;
    root = insert(root, 100, "Does it grow underground?", "");
    insert(root, 50, "Is it long in shape?", "");
    insert(root, 25, "Is it orange in color?", "");
    insert(root, 15, "", "It's a carrot!");
    insert(root, 35, "", "It's a parsnip!");
    insert(root, 75, "Is it red in color?", "");
    insert(root, 65, "", "It's a radish!");
    insert(root, 85, "", "It's a potato!");
    insert(root, 150, "Does it grow on a tree?", "");
    insert(root, 125, "Is it red in color?", "");
    insert(root, 115, "", "It's an apple!");
    insert(root, 135, "", "It's a peach!");
    insert(root, 175, "Is it red in color?", "");
    insert(root, 165, "", "It's a tomato!");
    insert(root, 185, "", "It's a pea!");
    return root;
}

/*
This was just for testing for me to make sure that everything was printing
Not used in the final code, but just prints the BST
*/
void printGameTree(node* root){
    if(root != NULL){
        printGameTree(root->right);
        printf("%s ", root->question);
        printGameTree(root->left);
    }
}

/*
This checks the node that we give it and sees if the guess is empty or the question is empty (One must always be empty)
It then prints out the one that isnt empty and returns an int value depending on which one it prints
*/

int printQuestionOrGuess(node *root){
    if(strcmp(root->guess, "") != 0){
        printf("%s\n", root->guess);
        return 1;
    }else if(strcmp(root->question, "") != 0){
        printf("%s\n", root->question);
        return 0;
    }else{
        return -1;
    }
}

/*
This is what we use to run the game
*/

void PlayGuessingGame(node* root){
    int gOrq = 0;
    char answer;
    printf("You think of a fruit or vegetable and I will try to guess it!\n");
    while(gOrq != 1){
        gOrq = printQuestionOrGuess(root);
        printf("y/n: ");
        scanf(" %c", &answer);

        if(answer == 'n' && root->left != NULL) root = root->left;
        else if(answer == 'y' && root->right != NULL) root = root->right;
    }
    switch(answer){
        case 'y':
            printf("I win!\n");
            break;
        case 'n':
            printf("You win!\n");
            // char *question[256];
            // char *guess[256];

            // printf("Please enter a question that will help me guess: ");
            // // scanf("%24[^\n]s", question);
            // // printf("Please enter the fruit or vegetable you were thinking of: ");
            // // scanf("%24[^\n]s", guess);

            // insert(root, root->data / 2, question, "");
            // insert(root, (root->data / 2) + (root -> data), "", guess);
        default:
            break;
    }
}

