#pragma once
#include "Monstro.h"
#include "Personagem.h"

class Combate {
private:
    Personagem& jogador;
    Monstro monstro;

public:
    Combate(Personagem& jogador);

    ~Combate();
};


