#include <stdio.h>
#include "bst.h"

/*
Basic main function that allows us to keep running the same loop unless the use presses 'q'
*/
int main(){
    node *gameTree = create_game_tree();
    char quit = 'a';
    printf("Welcome! Press 'q' to quit or any other key to continue:\n");
    scanf(" %c", &quit);

    while(quit != 'q'){
        PlayGuessingGame(gameTree);
        printf("Press 'q' to quit or any other key to continue:\n");
        scanf(" %c", &quit);
    }

    printf("Bye Bye!\n");
}   