#pragma once
#include "Personagem.h"
#include <vector>


class Fases {
public:
    Fases() = default;

    void entrar(Personagem &jogador);
    void menuDeFases();
    void menuDasPartes(const std::vector<std::string> &fases);
};