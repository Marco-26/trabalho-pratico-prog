#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    int gamemode = choose_gamemode();
    start_game(gamemode);
    int mini_board = calculate_mini_board();
    do{
        int px = 0, py = 0; // guardar posicao da ultima jogada
        player_move(mini_board, &px,&py);
        int mini_board = calculate_mini_board(); // calcular qual o proximo mini board para o adversario jogar
    }
    while(winner == ' ');


    return 0;
}
