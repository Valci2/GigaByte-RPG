#pragma once
#include "Monstro.h"
#include "Personagem.h"
#include <vector>

class Combate {
public:
    Combate();
    ~Combate();

    void iniciarCombate(Personagem& jogador, Monstro& monstro);
    void comecar(Personagem& jogador, int fase, int parte);
    void gerenciamentoDeMonstro(Personagem& jogador, std::vector<Monstro>& monstros, int parte);
};


