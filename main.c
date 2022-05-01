#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    //int gamemode = choose_gamemode();
    start_game(2);
    int mini_board = calculate_first_board(); // calcular primeiro mini-tabuleiro
    print_board();
    winner = ' ';
    while(winner == ' '){
        winner = ' ';
        int px = 0, py = 0; // guardar posicao da ultima jogada do jogador
        player_move(mini_board, &px,&py);
        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c", winner);
            break;
        }
        mini_board = calculate_mini_board(&px,&py);

        /*int ox = 0, oy = 0;  // guardar posicao da ultima jogada do adversario
        player_move(mini_board, &ox,&oy);
        mini_board = calculate_mini_board(&ox,&oy);
        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != '\0'){
            // existe um vencedor
            printf("Vencedor: %c", winner);
            break;
        }*/
    }

    return 0;
}
