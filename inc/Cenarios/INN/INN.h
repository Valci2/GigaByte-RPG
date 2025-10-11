#pragma once
#include "../../Personagem/Personagem.h"

class INN {
private:
    void dormir(Personagem &jogador);

public:
    INN() = default; // gera um construtor padrão
    void entrar(Personagem &jogador);
};