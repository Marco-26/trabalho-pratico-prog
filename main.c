#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    int gamemode = choose_gamemode();
    start_game(gamemode);
    int mini_board = calculate_mini_board(&px, &py);
    do{
        print_board();
        int px = 0, py = 0; // guardar posicao da ultima jogada
        player_move(mini_board, &px,&py);
        //print_board();
        check_win_miniBoard(mini_board);
        //winner = check_win(mini_board);
        /*if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c", winner);
            break;
        }*/
        int mini_board = calculate_mini_board(&px,&py); // calcular qual o proximo mini board para o adversario jogar
        //player_move(mini_board, &px,&py);
    }
    while(winner == ' ');

    return 0;
}
