#include "INN.h"
#include <iostream>

#include "../Personagem/Personagem.h"

int dentroDoINN(Personagem &jogador) {
    std::cout << "Ola meu chapa " << jogador.getNome() << "acho que voce merece um descanco" << std::endl;
    return 0;
}

void Dormir(Personagem &jogador) {
    jogador.setHP(jogador.getMaxHP());
    jogador.setMana(jogador.getMaxMana());
}