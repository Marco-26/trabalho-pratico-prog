#include <stdio.h>
#include <stdlib.h>
#include "game.h"

int main()
{
    int gamemode = choose_gamemode();
    start_game(gamemode);
    int mini_board = calculate_mini_board(); // calcular qual o mini board a jogar
    player_move(mini_board);                 // o primeiro jogador joga
                    // verificar se ganha alguma board

    return 0;
}
