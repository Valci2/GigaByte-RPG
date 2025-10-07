#include <iostream>
#include "Personagem/Personagem.h"
#include "Historia/Historia.h"
#include "Lobby/Lobby.h"

// colar isso no clion para rodar o programa
/*
Historia/Historia.cpp
Historia/funcoesDaHistoria.cpp
Lobby/Lobby.cpp
funcoesUteis/funcoesUteis.cpp
Personagem/Itens/Itens.cpp
Personagem/Personagem.cpp
Cenarios/INN/INN.cpp
Cenarios/Loja/Loja.cpp
*/

int main() {
    Personagem jogador = apresentacao(); // apresenta o jogador ao mundo, e jogador é criado lá dentro
    historia01(); // função que conta a primeira parte da historia do jogo
    lobby(jogador); // leva o jogador até o lobby

    return 0;
}