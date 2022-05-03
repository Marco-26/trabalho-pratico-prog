#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    show_rules();
    int gamemode = choose_gamemode();
    start_game(2);
    int mini_board = calculate_first_board(); // calcular primeiro mini-tabuleiro
    print_board();
    winner = ' ';

    while(winner == ' '){
        // vez do primeiro jogador
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
        // verificar se a mini board já não tem vencedor
        while(board_grid[mini_board].winner != ' '){
            printf("Esta mini-board ja tem vencedor, por isso, foi escolhida outra.");
            mini_board++;
        }

        // vez do segundo jogador
        int ox = 0, oy = 0;
        if(gamemode == 1) pc_move(mini_board, &ox,&oy);
        else opponent_move(mini_board,&ox,&oy);
        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c", winner);
            break;
        }
        mini_board = calculate_mini_board(&ox,&oy);
        while(board_grid[mini_board].winner != ' '){
            printf("Esta mini-board ja tem vencedor, por isso, foi escolhida outra.\n");
            mini_board++;
        }
    }
    return 0;
}
