#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    //int gamemode = choose_gamemode();
    //start_game(gamemode);
    //int mini_board = calculate_mini_board();
    //do{
    //    print_board();
        int px = 0, py = 0; // guardar posicao da ultima jogada
    //    player_move(mini_board, &px,&py);
    //    check_win_miniBoard(mini_board);
    //    int mini_board = calculate_mini_board(&px,&py); // calcular qual o proximo mini board para o adversario jogar
    //}
    //while(winner == ' ');

    //int px = 1, py = 1; // guardar posicao da ultima jogada
    //int mini_board = calculate_mini_board(&px,&py); // calcular qual o proximo mini board para o adversario jogar

    //printf("%d",mini_board);
    start_game(0);
    player_move(0,&px,&py);
    player_move(0,&px,&py);
    return 0;
}
