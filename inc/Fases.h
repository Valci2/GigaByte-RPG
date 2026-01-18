#pragma once
#include "Personagem.h"
#include "Combate.h"
#include <vector>

class Fases {
private:
    Combate* combate;
public:
    Fases() = default;

    void entrar(Personagem &jogador);
    void menuDasFases();
    void menuDasPartes(const std::vector<std::string> &fases);
};