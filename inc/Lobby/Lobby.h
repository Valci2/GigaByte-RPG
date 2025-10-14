#pragma once
#include "../Personagem/Personagem.h"
#include "../Cenarios/INN/INN.h"
#include "../Cenarios/Loja/Loja.h"
#include "../Cenarios/Fases/Fases.h"

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