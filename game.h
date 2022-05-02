#ifndef GAME_H
#define GAME_H

typedef struct Board{ // cada quadrado tem um mini board
    char mini_board[3][3];
    char winner; // saber qual o jogador que ganhou no respetivo quadrado
} Board;

Board board_grid[8];

int choose_gamemode();
void start_game(int);
void print_board();
int calculate_mini_board(int*,int*);
void player_move(int,int*,int*);

void check_win_miniBoard(int);
void fill_spaces();
char check_win();
#endif
