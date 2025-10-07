#pragma once
#include <string>


class monstros {
private:
    std::string Monstro;
    int vida;
    int forca;
    int inteligencia;
    int defesa;

public:
    monstros(const std::string &nome, int vida, int forca, int inteligencia, int defesa);
    virtual void atacar() = 0;
    virtual void defender() = 0;
};