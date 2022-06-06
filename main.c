#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    pno lista = NULL;
    show_rules();
    int gamemode = choose_gamemode();
    start_game();
    int mini_board = calculate_first_board(); // calcular primeiro mini-tabuleiro
    print_board();
    winner = ' ';

    while(winner == ' '){
        // vez do primeiro jogador
        int px = 0, py = 0; // guardar posicao da ultima jogada do jogador
        // mostrar as ultimas 10 jogadas do jogador
        player_move(mini_board, &px,&py);
        lista = adicionaLista(lista,1,px,py,mini_board);
        mostraLista(lista);
        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c", winner);
            break;
        }
        mini_board = calculate_mini_board(&px,&py);
        // verificar se a mini board j� n�o tem vencedor
        while(board_grid[mini_board].winner != ' '){
            printf("Esta mini-board ja tem vencedor, por isso, foi escolhida outra.");
            mini_board++;
        }

        // vez do segundo jogador
        int ox = 0, oy = 0;
        // mostrar as ultimas 10 jogadas do jogador
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
