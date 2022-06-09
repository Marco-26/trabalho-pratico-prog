#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "game.h"
#include "matdin.h"

// variavel para detetar se e a primeira jogada do jogo
bool first_play = true;

void show_rules(){
    printf("Regra especial do jogo: \n");
    printf("Caso um mini-tabuleiro tiver um vencedor, e este for escolhido outra vez, o programa escolhe o seguinte mini-tabuleiro.\n");
}

int choose_gamemode(){
    // jogar contra o computador ou contra outro jogador
    // 1 - contra computador
    // 2 - contra outro jogador
    int gamemode;
    do{
        printf("\nQual o modo de jogo que deseja jogar: 1(Jogador vs PC) ou 2 (Jogador vs Jogador) ");
        scanf("%d", &gamemode);
    }
    while(gamemode != 1 && gamemode != 2);
    return gamemode;
}

void start_game(){
    //Board board_grid[8]; // transformar isto para um array dinamico
    //board_grid = malloc(sizeof(board_grid) * 8);

    for(int i = 0; i < 9; i++){ // loop para percorrer array board_grid
        for(int j = 0; j < 3; j++){ // loop para percorrer linhas de cada board
            for(int k = 0; k < 3; k++){ // loop para percorrer colunas de cada board
                board_grid[i].mini_board[j][k] = ' ';
                board_grid[i].winner = ' ';
            }
        }
    }
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
    printf("\n");

}

int calculate_first_board(){
    if(first_play){
        first_play = false;
        srand(time(0));
        return rand()%9;
    }
}

int calculate_mini_board(int *x, int*y){
    if(*x==0 && *y==0) return 0;
    if(*x==0 && *y==1) return 1;
    if(*x==0 && *y==2) return 2;
    if(*x==1 && *y==0) return 3;
    if(*x==1 && *y==1) return 4;
    if(*x==1 && *y==2) return 5;
    if(*x==2 && *y==0) return 6;
    if(*x==2 && *y==1) return 7;
    if(*x==2 && *y==2) return 8;
}

void player_move(int mini_board_number, int *px, int *py){
    int x,y;
    do{
        do{
            printf("(Mini-board %d) Espaço a preencher: ", mini_board_number+1);
            scanf("%d %d", &x, &y);
        }
        while(!(x>=1 && x<=3 && y>=1 && y<=3));
        // tirar um valor pq se trata de index
        x--,y--;
        *px = x, *py = y;
        if(board_grid[mini_board_number].mini_board[x][y] != ' '){
            printf("Tente outra vez\n");
        }
        else{
            board_grid[mini_board_number].mini_board[x][y] = 'X';
            print_board();
            break;
        }
    }
    while(board_grid[mini_board_number].mini_board[x][y] != ' ');
}

void opponent_move(int mini_board_number, int *ox, int *oy){
    int x,y;
    do{
        do{
            printf("(Mini-board %d) Espaço a preencher: ", mini_board_number+1);
            scanf("%d %d", &x, &y);
        }
        while(!(x>=1 && x<=3 && y>=1 && y<=3));
        // tirar um valor pq se trata de index
        x--,y--;
        *ox = x, *oy = y;
        if(board_grid[mini_board_number].mini_board[x][y] != ' '){
            printf("Tente outra vez\n");
        }
        else{
            board_grid[mini_board_number].mini_board[x][y] = 'O';
            print_board();
            break;
        }
    }
    while(board_grid[mini_board_number].mini_board[x][y] != ' ');
}

void pc_move(int mini_board_number, int *ox, int *oy){
    srand(time(0));
    int x,y;
    do{
        // criar um valor entre 0 e 2 random
        x = rand()%3;
        y = rand()%3;
        *ox = x, *oy = y;
        if(board_grid[mini_board_number].mini_board[x][y] != ' '){
            continue;
        }
        else{
            board_grid[mini_board_number].mini_board[x][y] = 'O';
            print_board();
            break;
        }
    }
    while(board_grid[mini_board_number].mini_board[x][y] != ' ');
}


void check_win_miniBoard(int miniBoardNumber){

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

char check_win(){
    // linhas
    if(board_grid[0].winner != ' ' && board_grid[0].winner == board_grid[1].winner && board_grid[0].winner == board_grid[2].winner){
        return board_grid[0].winner;
    }
    if(board_grid[3].winner != ' ' && board_grid[3].winner == board_grid[4].winner && board_grid[3].winner == board_grid[5].winner){
        return board_grid[3].winner;
    }
    if(board_grid[6].winner != ' ' && board_grid[6].winner == board_grid[7].winner && board_grid[6].winner == board_grid[8].winner){
        return board_grid[6].winner;
    }
    // colunas
    if(board_grid[0].winner != ' ' && board_grid[0].winner == board_grid[3].winner && board_grid[0].winner == board_grid[6].winner){
        return board_grid[0].winner;
    }
    if(board_grid[1].winner != ' ' && board_grid[1].winner == board_grid[4].winner && board_grid[1].winner == board_grid[7].winner){
        return board_grid[1].winner;
    }
    if(board_grid[2].winner != ' ' && board_grid[2].winner == board_grid[5].winner && board_grid[2].winner == board_grid[8].winner){
        return board_grid[2].winner;
    }
    // diagonais
    if(board_grid[0].winner != ' ' && board_grid[0].winner == board_grid[4].winner && board_grid[0].winner == board_grid[8].winner){
        return board_grid[0].winner;
    }
    if(board_grid[2].winner != ' ' && board_grid[2].winner == board_grid[4].winner && board_grid[2].winner == board_grid[6].winner){
        return board_grid[2].winner;
    }

    return ' ';
}

// Lista ligada

void preenche(pno p,int player,int move_x,int move_y, int board){
    p->player = player;
    p->move_x= move_x;
    p->move_y = move_y;
    p->board = board;
    p->next = NULL;
}

pno adicionaLista(pno p,int player,int move_x,int move_y, int board){
    move_x++,move_y++,board++; // aumentar um valor devido aos index
    pno novo, aux;

    novo = malloc(sizeof(no));
    if(novo == NULL) return p;
    preenche(novo, player, move_x,move_y, board);
    if(p == NULL)
        p = novo;
    else{
        aux = p;
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = novo;
    }
    return p;
}

void mostraLista(pno p,int moves){
    pno novo = p;
    int count =0,i=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    printf("Ultimas %d jogada/s\n",moves);
    if(count<moves){
        while(i!=count){
            printf("Jogador: %d, Jogada (%d|%d), Tabuleiro %d\n",
                    p->player, p->move_x, p->move_y,p->board);

            novo=novo->next;
            i++;
        }
    }
    else{
        while(i!=(count-moves)){
            novo=novo->next;
            i++;
        }
        while(i!=count){
            printf("Jogador: %d, Jogada (%d|%d), Tabuleiro %d\n",
                    novo->player, novo->move_x, novo->move_y,novo->board);
            novo=novo->next;
            i++;
        }
    }
}

