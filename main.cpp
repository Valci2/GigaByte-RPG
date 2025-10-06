#include <iostream>
#include "Personagem/Personagem.h"
#include "Historia/Historia.h"
#include "Lobby/Lobby.h"

// colar isso no clion para rodar o programa
/*
Personagem/Personagem.cpp
Historia/Historia.cpp
Lobby/Lobby.cpp
funcoesUteis/funcoesUteis.cpp
Personagem/Itens/Itens.cpp
Cenarios/INN.cpp
*/

int main() {
    Personagem jogador = apresentacao();
    historia01();
    lobby(jogador);

    return 0;
}