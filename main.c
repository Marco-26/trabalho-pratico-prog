#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    pno lista = NULL;
    show_rules();
    int gamemode;

    do{
        gamemode = choose_gamemode();
    }
    while(gamemode != 1 && gamemode != 2);

    start_game();
    int mini_board = calculate_first_board(); // calcular primeiro mini-tabuleiro
    print_board();
    winner = ' ';
    int seeMoves = 0;
    while(winner == ' '){
        // vez do primeiro jogador
        int px = 0, py = 0; // guardar posicao da ultima jogada do jogador
        // mostrar as ultimas 10 jogadas do jogador
        printf("Quer ver as ultimas jogadas, se sim, quantas (1-10) (0=Nao)?\n");
        scanf("%d",&seeMoves);
        if(seeMoves >=1 && seeMoves<=10){
            // chamar funcao para mostrar a lista ligada
            printf("O jogador quer ver as ultimas %d jogadas\n", seeMoves);
        }
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
            printf("Esta mini-board ja tem vencedor, por isso, foi escolhida outra.\n");
            mini_board++;
        }

        // vez do segundo jogador
        int ox = 0, oy = 0;
        // mostrar as ultimas 10 jogadas do jogador
        if(gamemode == 1) pc_move(mini_board, &ox,&oy);
        else {
            printf("Quer ver as ultimas jogadas, se sim, quantas (1-10) (0=Nao)?\n");
            scanf("%d",&seeMoves);
            if(seeMoves >=1 && seeMoves<=10){
                // chamar funcao para mostrar a lista ligada
                printf("O jogador quer ver as ultimas %d jogadas\n", seeMoves);
            }
            opponent_move(mini_board,&ox,&oy);
        }
        lista = adicionaLista(lista,2,ox,oy,mini_board);
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
