#ifndef GAME_H
#define GAME_H

typedef struct Board{ // cada quadrado tem um mini board
    char mini_board[3][3];
    char winner; // saber qual o jogador que ganhou no respetivo quadrado
} Board;

Board *board_grid; // transformar isto para um array dinamico

typedef struct Jogadas no, *pno;

struct Jogadas{
    int player;
    int move_x,move_y;
    int board;
    pno next;
};

void show_rules();
int choose_gamemode();
void start_game();
int calculate_first_board();
void print_board();
void player_move(int,int*,int*);
int calculate_mini_board(int*,int*);
void opponent_move(int, int *, int*);
void pc_move(int, int*, int*);

void check_win_miniBoard(int);
char check_win();

void preenche(pno,int,int,int, int);
pno adicionaLista(pno,int,int,int,int);
void mostraLista(pno,int);
void guardaLista(pno p,int);
#endif
