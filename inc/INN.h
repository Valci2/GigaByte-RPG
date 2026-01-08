#pragma once
#include "Personagem.h"

class INN {
public:
    INN() = default; // gera um construtor padrão
    void entrar(Personagem &jogador);
};