#pragma once
#include "Monstro.h"
#include "Personagem.h"
#include <vector>

class Combate {
public:
    Combate();
    ~Combate();

    void gerenciamentoDeCombate(Personagem& jogador, int fase, int parte);
    void escolhaDoMonstro(Personagem& jogador, std::vector<Monstro>& monstros, int parte);
};


