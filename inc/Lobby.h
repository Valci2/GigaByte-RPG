#pragma once
#include "Personagem.h"
#include "INN.h"
#include "Loja.h"
#include "Fases.h"

class Lobby {
private:
    Personagem& jogador;
    INN inn;
    Loja loja;
    Fases fases;
public:
    Lobby(Personagem &jogador);
    void mostrarMenu() const;
    void processarEscolha(int escolha);
    void iniciar();
};