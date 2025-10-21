#pragma once
#include <string>

class Monstro {
private:
    std::string nome;
    int HP;
    int maxHP;
    int mana;
    int maxMana;
    int forca;
    int inteligencia;
    int defesa;

public:
    Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesa);
    virtual void atacar();
    virtual void defender();
    virtual ~Monstro() = default;
};