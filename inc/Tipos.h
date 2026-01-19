#ifndef TIPOS_H
#define TIPOS_H

#include <string>

enum class TipoPocao {
    PocaoCura,
    PocaoCuraForte,
    PocaoMana,
    PocaoManaForte
};

enum class TipoItem {
    Arma,
    Armadura,
    Pocao
};

struct Item
{
    std::string nome;
    int poder;
};

#endif