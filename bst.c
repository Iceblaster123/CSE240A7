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

void printGameTree(node* root){
    if(root != NULL){
        printGameTree(root->right);
        printf("%s ", root->question);
        printGameTree(root->left);
    }
}

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
            // int c;
            // while ((c = getchar()) != '\n' && c != EOF);

            // char question[100];
            // printf("Please give me a question to help with the next rounds: ");
            // fgets(question, sizeof(question), stdin);
            // question[strcspn(question, "\n")] = 0; // remove newline

            // char guess[100];
            // printf("Please give me the fruit or vegetable that you were thinking of: ");
            // fgets(guess, sizeof(guess), stdin);
            // guess[strcspn(guess, "\n")] = 0; // remove newline

            // root->left = insert(root->left, root->data / 2, question, "");
            // root->left->right = insert(root->left->right, root->data / 2, "", guess);
            // break;
        default:
            break;
    }
}

