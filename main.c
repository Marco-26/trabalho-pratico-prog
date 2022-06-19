#include <stdio.h>
#include <stdlib.h>
#include "game.h"

char winner = ' ';

int main()
{
    int seeMoves = 0, gamemode, mini_board;
    int first_turn = 1;

    pno lista = NULL;
    pno aux = NULL;

    show_rules();
    gamemode = choose_gamemode();

    start_game(board_grid);

    if(gamemode == 3){
        lista = leLista(lista);
        aux = lista;
        if(lista!=NULL){
            printf("Jogadas guardadas: \n");
            while(lista!=NULL){
                printf("Jogador: %d, Jogada (%d|%d), Board:%d \n",lista->player,lista->move_x,lista->move_y,lista->board);
                if(lista->player==1) board_grid[lista->board].mini_board[lista->move_x][lista->move_y] = 'X';
                else board_grid[lista->board].mini_board[lista->move_x][lista->move_y] = 'O';
                lista = lista->next;
            }
            lista = aux; // voltar a por a lista a apontar para o primeiro node
        }
        else{
            printf("Nao existe ficheiro com dados guardados\n");
        }
    }

    mini_board = calculate_first_board(); // calcular primeiro mini-tabuleiro
    print_board();

    while(winner == ' '){
        // vez do primeiro jogador
        int px = 0, py = 0; // guardar posicao da ultima jogada do jogador

        if(first_turn==0){
            do{
                printf("Quer ver as ultimas jogadas, se sim, quantas (1-10) (0=Nao)?\n");
                scanf("%d",&seeMoves);
                fflush(stdin);
            }
            while(!(seeMoves>=0 && seeMoves<=10));

            mostraLista(lista,seeMoves);
        }

        player_move(mini_board, &px,&py);
        lista = adicionaLista(lista,1,px,py,mini_board);

        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c\n", winner);
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
            do{
                printf("Quer ver as ultimas jogadas, se sim, quantas (1-10) (0=Nao)?\n");
                scanf("%d",&seeMoves);
                fflush(stdin);
            }
            while(!(seeMoves>=0 && seeMoves<=10));

            mostraLista(lista,seeMoves);

            opponent_move(mini_board,&ox,&oy);
        }
        lista = adicionaLista(lista,2,ox,oy,mini_board);
        check_win_miniBoard(mini_board);
        winner = check_win();
        if(winner != ' '){
            // existe um vencedor
            printf("Vencedor: %c\n", winner);
            break;
        }
        mini_board = calculate_mini_board(&ox,&oy);
        while(board_grid[mini_board].winner != ' '){
            printf("Esta mini-board ja tem vencedor, por isso, foi escolhida outra.\n");
            mini_board++;
        }
        first_turn = 0;
    }

    char nomefich[100];
    printf("Nome do ficheiro para guardar as jogadas: ");
    scanf("%s",&nomefich);
    guardaJogadas(lista,nomefich);
    free(board_grid);

    return 0;
}
