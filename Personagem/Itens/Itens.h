#pragma once
#include <string>

class Itens {
private:
    int pocaoDeCura = 0;
    int pocaoDeCuraForte = 0;
    int pocaoDeMana = 0;
    int pocaoDeManaForte = 0;
    std::string arma = "sem";
    std::string armadura = "sem";

public:
    // construtor
    Itens();

    // metodos
    void usarPocaoDeCura();
    void usarPocaoDeCuraForte();
    void usarPocaoDeMana();
    void usarPocaoDeManaForte();

    // setter
    void setPocaoDeCura(int pocaoDeCura);
    void setPocaoDeCuraForte(int pocaoDeCuraForte);
    void setPocaoDeMana(int pocaoDeMana);
    void setPocaoDeManaForte(int pocaoDeManaForte);
    void setArma(const std::string &arma);
    void serArmadura(const std::string &armadura);

    // getter
    int getPocaoDeCura();
    int getPocaoDeCuraForte();
    int getPocaoDeMana();
    int getPocaoDeManaForte();
    const std::string getArma();
    const std::string getArmadura();
};
