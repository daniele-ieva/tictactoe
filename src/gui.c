#include "game.h"
#include <stdio.h>

char get_code(player_t p) {
    switch (p) {
        case O:
            return 'O';
            break;
        case X:
            return 'X';
            break;
        case NONE:
            return ' ';
        default:
            return 'E';
    }
}

void print_game(const game_t *game){
    for (int y = 0; y < 2; y++) {
        for (int x = 0; x < 2; x++) {
            printf("%c|", get_code(game->board[y][x]));
        }
        printf("%c\n-----\n", get_code(game->board[y][2]));
    }
    for (int x = 0; x < 2; x++) {
        printf("%c|", get_code(game->board[2][x]));
    }
    printf("%c\n", get_code(game->board[2][2]));
}

pos_t get_move() {
    pos_t out, in;
    printf("Insert column (1-3):\t");
    scanf("%2hhu", &in);
    out = (in - 1) << 4;
    printf("Insert row (1-3):\t");
    scanf("%2hhu", &in);
    out = out | ((in - 1) & 0x0F);
    printf("\n");
    return out;
}

