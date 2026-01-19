#pragma once

#include "monstros/Monstro.h"
#include <string>
#include <vector>

struct TemplateMonstro {
    std::string nome;

    int hpBase;
    int manaBase;
    int forcaBase;
    int inteligenciaBase;
    int defesaBase;

    int xpMin, xpMax;
    int capibasMin, capibasMax;
};

class FabricaDeMonstros
{
private:
    static std::vector<TemplateMonstro> monstrosFaseUm;
    static std::vector<TemplateMonstro> monstrosFaseDois;
    static std::vector<TemplateMonstro> monstrosFaseTres;

public:
    FabricaDeMonstros();
    ~FabricaDeMonstros();

    static Monstro fabricar(int fase, int parte);
};