#include <stdint.h>
#include <stdint.h>
#include <stdbool.h>
#ifndef _GAME_H_
    #define _GAME_H_

typedef uint8_t pos_t;

enum player {
    NONE = 0,
    X = 1,
    O = -1,
};

typedef enum player player_t;

typedef struct {
    player_t board[3][3];
    player_t turn_player;
} game_t;

void print_game(const game_t*); 
void set_piece(game_t*, pos_t);
pos_t get_move(void); 
bool game_over(const game_t*, pos_t);
char get_code(player_t);
#endif
