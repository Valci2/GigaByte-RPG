#include "../inc/Personagem/Personagem.h"
#include "../inc/Historia/Historia.h"
#include "../inc/Lobby/Lobby.h"

// colar isso no clion para rodar o programa
/*
src/Historia/Historia.cpp
src/Lobby/Lobby.cpp
src/funcoesUteis/funcoesUteis.cpp
src/Personagem/Itens/Itens.cpp
src/Personagem/Personagem.cpp
src/Cenarios/INN/INN.cpp
src/Cenarios/Loja/Loja.cpp
*/

int main() {

    // Personagem jogador = apresentacao(); // apresenta o jogador ao mundo, e jogador é criado lá dentro
    // historia01(); // função que conta a primeira parte da historia do jogo
    Personagem jogador("Pablito");
    Lobby lobby(jogador);
    lobby.iniciar();

    return 0;
}