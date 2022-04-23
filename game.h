#ifndef GAME_H
#define GAME_H

typedef struct Board{ // cada quadrado tem um mini board
    char mini_board[3][3];
    char winner; // saber qual o jogador que ganhou no respetivo quadrado
} Board;

typedef struct PlayerMove{
    int x;
    int y;
} PlayerMove;

Board board_grid[8];
PlayerMove lastPlayerMove;

int choose_gamemode();
void start_game(int);
void print_board();
int calculate_square();
void player_move(int);

void check_win(int);
#endif
