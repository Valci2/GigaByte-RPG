#pragma once
#include "../../Personagem/Personagem.h"

class INN {
public:
    INN() = default; // gera um construtor padrão
    void entrar(Personagem &jogador);
    void dormir(Personagem &jogador);
};