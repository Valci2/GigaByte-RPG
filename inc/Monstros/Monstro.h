#pragma once
#include <string>

#include "Entidade.h"

class Monstro : public Entidade {
public:
    Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP);
    virtual ~Monstro() = default;
};