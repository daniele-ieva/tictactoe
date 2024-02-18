#include "game.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint8_t get_col(pos_t pos) {
    return (pos & 0xF0) >> 4;
}

uint8_t get_row(pos_t pos) {
    return pos & 0x0F;
}

void set_piece(game_t *game , pos_t position) {
    uint8_t row = get_row(position);
    uint8_t col = get_col(position);
    if (game->board[row][col] != 0 || row > 2|| col > 2) {
        fprintf(stderr, "Invalid Move, retry\n");
        return;
    }
    game->board[row][col] = game->turn_player;
    game->turn_player = -game->turn_player;
}


bool game_over(const game_t* game, pos_t move) {
    player_t player = -game->turn_player;
    #ifdef DEBUG
    printf("%d\n", player);
    #endif
   
    uint8_t row = get_row(move);
    uint8_t col = get_col(move);
    // Check if row is complete
    bool over = true;
    for(int offset = 1; offset <= 2; offset++) {
        if (game->board[col][(row + offset) % 3] != player) {
            over = false;
            break;
        }
    }
    if (over) {
        return over;
    }
    
    // Check if column is complete
    over = true;
    for(int offset = 1; offset <= 2; offset++) {
        if (game->board[(col + offset) % 3][row] != player) {
            over = false;
            break;
        }
    }
    if (over) {
        return over;
    }

    // Check if diagonal is complete
    if (row == col) {
        over = true;
        for (int coord = 0; coord < 3; coord++) {
            if (game->board[coord][coord] != player) {
                over = false;
                break;
            }
        }
        if (over) {
            return true;
        }
    }

    // Check if antidiagonal is complete
    if (row + col == 2) {
        over = true;
        for (int coord = 0; coord < 3; coord++) {
            if (game->board[coord][2 - coord] != player) {
                over = false;
            }
        }
        if (over) {
            return over;
        }
    }
    return over;
}
