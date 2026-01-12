#pragma once
#include <string>

class Itens {
private:
    int capiba = 0;
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
    void adicionarPocao(const std::string &nome, int quantidade);

    // setter
    void setCapiba(int capiba);
    void setPocaoDeCura(int pocaoDeCura);
    void setPocaoDeCuraForte(int pocaoDeCuraForte);
    void setPocaoDeMana(int pocaoDeMana);
    void setPocaoDeManaForte(int pocaoDeManaForte);
    void setArma(const std::string &arma);
    void setArmadura(const std::string &armadura);

    // getter
    int getCapiba();
    int getPocaoDeCura();
    int getPocaoDeCuraForte();
    int getPocaoDeMana();
    int getPocaoDeManaForte();
    const std::string &getArma();
    const std::string &getArmadura();
};
