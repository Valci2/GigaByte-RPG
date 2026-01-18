#pragma once
#include <string>

#include "Entidade.h"
#include "Itens.h"
#include "Tipos.h"

enum class TipoAtributo {
    HP,
    Mana
};

class Personagem : public Entidade {
private:
    int nivel = 1;
    int XP = 0;
    int falta = 0;
    Itens inventario; // classe de atributo publico

public:
    // construtor
    Personagem(const std::string &nome);

    // metodos
    void status();
    void mostrarinventario();
    void subirDeNivel(int limite);
    bool ganharXP(int quantidade);
    void dormir();

    // combate
    void magia();
    void usar_magia();
    bool usarItem(TipoItem item);
    bool usarPocao(int quantidade, int atual,Entidade& alvo, TipoAtributo tipo);
    bool fugir();

    // Getter
    int getNivel();
    int getXP();
    int getFalta();
    Itens &getInventario();

    // Setter
    void setNivel(int nivel);
    void setXP(int xp);
};