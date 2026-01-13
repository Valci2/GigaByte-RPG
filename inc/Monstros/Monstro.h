#pragma once
#include <string>

#include "Entidade.h"

class Monstro : public Entidade {
private:
    int capibas;
public:
    Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP, int capibas);
    virtual ~Monstro() = default;

    int getCapibas();

    void setCapibas(int capibas);
};