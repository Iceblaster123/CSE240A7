#include <stdio.h>
#include "bst.h"

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
}