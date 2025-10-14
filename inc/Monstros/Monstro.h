#pragma once
#include <string>
#include "Personagem/Itens/Itens.h"

class monstro {
private:
    std::string nome;
    int HP;
    int maxHP = 5;
    int mana;
    int maxMana = 2;
    int forca;
    int inteligencia;
    int defesa;
    Itens inventario; // classe de atributo publico

public:
    monstro(const std::string &nome, int vida, int forca, int inteligencia, int defesa);
    virtual void atacar() = 0; // metodo virtual que todo monstro tera que possuir
    virtual void defender() = 0; //
    virtual void usarPocoes() = 0;
};