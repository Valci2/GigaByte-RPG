#pragma once

#include "Monstro.h"
#include "Personagem.h"
#include "FabricaDeMonstros.h"

// enum para organização do switch
enum Acao {
    Atacar = 1,
    Defender,
    Magia,
    Item,
    Fugir
};

class Combate {
private:
    FabricaDeMonstros fabricaDeMonstros;
public:
    Combate();
    ~Combate();

    void comecar(Personagem& jogador, int fase, int parte);
    void iniciarCombate(Personagem& jogador, Monstro monstro);
    bool turnoDoJogador(Personagem& jogador, Monstro& monstro);
    void turnoDoMonstro(Personagem& jogador, Monstro& monstro);
    void fimDeCombate(Personagem &jogador, Monstro &monstro);
};


