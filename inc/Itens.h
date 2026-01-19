#pragma once
#include "Tipos.h"

#include <vector>
#include <string>

class Itens {
private:
    int capiba = 0;
    int pocaoDeCura = 0;
    int pocaoDeCuraForte = 0;
    int pocaoDeMana = 0;
    int pocaoDeManaForte = 0;
    std::string armaEquipada;
    std::string armaduraEquipada;
    std::vector<Item> armas;
    std::vector<Item> armaduras;

public:
    // construtor
    Itens();

    // metodos
    void adicionarPocao(const std::string &nome, int quantidade);

    // setter
    void setCapiba(int capiba);
    void setPocaoDeCura(int pocaoDeCura);
    void setPocaoDeCuraForte(int pocaoDeCuraForte);
    void setPocaoDeMana(int pocaoDeMana);
    void setPocaoDeManaForte(int pocaoDeManaForte);


    // getter
    int getCapiba();
    int getPocaoDeCura();
    int getPocaoDeCuraForte();
    int getPocaoDeMana();
    int getPocaoDeManaForte();

    const std::string &getArma();
    const std::string &getArmadura();

    void setArma(const std::string &arma);
    void setArmadura(const std::string &armadura);

    const std::vector<Item> &getArmas();
    const std::vector<Item> &getArmaduras();

    void setArmas(const Item &arma);
    void setArmaduras(const Item &armadura);
};