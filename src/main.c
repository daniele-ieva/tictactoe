#include "game.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    game_t game = {
        .board = {{0}},
        .turn_player = X, 
    };
    bool over = false;
    while (!over) {
        #ifndef DEBUG
            system("clear");
        #endif 
        print_game(&game);
        pos_t pos = get_move();
        set_piece(&game, pos);
        over = game_over(&game, pos);
    }
    #ifndef DEBUG
        system("clear");
    #endif
    print_game(&game);
    printf("%c Won!\n", get_code(-game.turn_player));
    return 0;
}

