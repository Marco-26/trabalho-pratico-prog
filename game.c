#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "game.h"

// variavel para detetar se e a primeira jogada do jogo
bool first_play = true;

int choose_gamemode(){
    // jogar contra o computador ou contra outro jogador
    // 1 - contra computador
    // 2 - contra outro jogador
    int gamemode;
    do{
        printf("Qual o modo de jogo que deseja jogar: 1(Jogador vs PC) ou 2 (Jogador vs Jogador) ");
        scanf("%d", &gamemode);
    }
    while(gamemode != 1 && gamemode != 2);
    return gamemode;
}

void start_game(int gamemode){
    for(int i = 0; i < 9; i++){ // loop para percorrer array board_grid
        for(int j = 0; j < 3; j++){ // loop para percorrer linhas de cada board
            for(int k = 0; k < 3; k++){ // loop para percorrer colunas de cada board
                board_grid[i].mini_board[j][k] = ' ';
            }
        }
    }
    // nesta fun��o vai ser ainda decidido qual o tipo de jogo, usando a variavel gamemode

    print_board();
}

void print_board(){

    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[0].mini_board[0][0],board_grid[0].mini_board[0][1],board_grid[0].mini_board[0][2],
                                                               board_grid[1].mini_board[0][0],board_grid[1].mini_board[0][1],board_grid[1].mini_board[0][2],
                                                               board_grid[2].mini_board[0][0],board_grid[2].mini_board[0][1],board_grid[2].mini_board[0][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[0].mini_board[1][0],board_grid[0].mini_board[1][1],board_grid[0].mini_board[1][2],
                                                               board_grid[1].mini_board[1][0],board_grid[1].mini_board[1][1],board_grid[1].mini_board[1][2],
                                                               board_grid[2].mini_board[1][0],board_grid[2].mini_board[1][1],board_grid[2].mini_board[1][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[0].mini_board[2][0],board_grid[0].mini_board[2][1],board_grid[0].mini_board[2][2],
                                                               board_grid[1].mini_board[2][0],board_grid[1].mini_board[2][1],board_grid[1].mini_board[2][2],
                                                               board_grid[2].mini_board[2][0],board_grid[2].mini_board[2][1],board_grid[2].mini_board[2][2]);
    printf("-----------||-----------||-----------\n");
    printf("-----------||-----------||-----------\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[3].mini_board[0][0],board_grid[3].mini_board[0][1],board_grid[3].mini_board[0][2],
                                                               board_grid[4].mini_board[0][0],board_grid[4].mini_board[0][1],board_grid[4].mini_board[0][2],
                                                               board_grid[5].mini_board[0][0],board_grid[5].mini_board[0][1],board_grid[5].mini_board[0][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[3].mini_board[1][0],board_grid[3].mini_board[1][1],board_grid[3].mini_board[1][2],
                                                               board_grid[4].mini_board[1][0],board_grid[4].mini_board[1][1],board_grid[4].mini_board[1][2],
                                                               board_grid[5].mini_board[1][0],board_grid[5].mini_board[1][1],board_grid[5].mini_board[1][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[3].mini_board[2][0],board_grid[3].mini_board[2][1],board_grid[3].mini_board[2][2],
                                                               board_grid[4].mini_board[2][0],board_grid[4].mini_board[2][1],board_grid[4].mini_board[2][2],
                                                               board_grid[5].mini_board[2][0],board_grid[5].mini_board[2][1],board_grid[5].mini_board[2][2]);
    printf("-----------||-----------||-----------\n");
    printf("-----------||-----------||-----------\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[6].mini_board[0][0],board_grid[6].mini_board[0][1],board_grid[6].mini_board[0][2],
                                                               board_grid[7].mini_board[0][0],board_grid[7].mini_board[0][1],board_grid[7].mini_board[0][2],
                                                               board_grid[8].mini_board[0][0],board_grid[8].mini_board[0][1],board_grid[8].mini_board[0][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[6].mini_board[1][0],board_grid[6].mini_board[1][1],board_grid[6].mini_board[1][2],
                                                               board_grid[7].mini_board[1][0],board_grid[7].mini_board[1][1],board_grid[7].mini_board[1][2],
                                                               board_grid[8].mini_board[1][0],board_grid[8].mini_board[1][1],board_grid[8].mini_board[1][2]);
    printf("---|---|---||---|---|---||---|---|---\n");
    printf(" %c | %c | %c || %c | %c | %c || %c | %c | %c \n", board_grid[6].mini_board[2][0],board_grid[6].mini_board[2][1],board_grid[6].mini_board[2][2],
                                                               board_grid[7].mini_board[2][0],board_grid[7].mini_board[2][1],board_grid[7].mini_board[2][2],
                                                               board_grid[8].mini_board[2][0],board_grid[8].mini_board[2][1],board_grid[8].mini_board[2][2]);
}

int calculate_mini_board(){
    //TODO: Arranjar maneira de passar as coordenadas da ultima jogada para esta funcao
    if(first_play){
        srand(time(0));
        return rand()%9;
        first_play = false;
    }
    else{
        printf("%d", lastPlayerMove.x);
        printf("%d", lastPlayerMove.y);
    }
}

void player_move(int mini_board){
    //TODO: Limitar o numero da linha e coluna ate 3 e verificar se o lugar ja esta preenchido
    //TODO:
    int x,y;
    printf("(Mini-board %d) Espaço a preencher: ", mini_board);
    scanf("%d %d", &x, &y);
    // tirar um valor pq se trata de index
    x--;
    y--;
    lastPlayerMove.x = x;
    lastPlayerMove.y = y;
    board_grid[mini_board].mini_board[x][y] = 'X';
    print_board();
}

void check_win(int miniBoardNumber){
    // linhas
    for (int i = 0; i < 3; i++)
    {
        if(board_grid[miniBoardNumber].mini_board[i][0] == board_grid[miniBoardNumber].mini_board[i][1] && board_grid[miniBoardNumber].mini_board[i][0]==board_grid[miniBoardNumber].mini_board[i][2]){
            board_grid[miniBoardNumber].winner = board_grid[miniBoardNumber].mini_board[i][0];
            break;
        }
    }
    // colunas
    for (int j = 0; j < 3; j++)
    {
        if(board_grid[miniBoardNumber].mini_board[0][j] == board_grid[miniBoardNumber].mini_board[1][j] && board_grid[miniBoardNumber].mini_board[0][j]==board_grid[miniBoardNumber].mini_board[2][j]){
            board_grid[miniBoardNumber].winner = board_grid[miniBoardNumber].mini_board[0][j];
            break;
        }
    }
    // diagonal
    if(board_grid[miniBoardNumber].mini_board[0][0] == board_grid[miniBoardNumber].mini_board[1][1] && board_grid[miniBoardNumber].mini_board[0][0]==board_grid[miniBoardNumber].mini_board[2][2]){
            board_grid[miniBoardNumber].winner = board_grid[miniBoardNumber].mini_board[0][0];
    }
    // diagonal
    if(board_grid[miniBoardNumber].mini_board[0][2] == board_grid[miniBoardNumber].mini_board[1][1] && board_grid[miniBoardNumber].mini_board[0][2]==board_grid[miniBoardNumber].mini_board[2][0]){
            board_grid[miniBoardNumber].winner = board_grid[miniBoardNumber].mini_board[0][2];
    }
}
