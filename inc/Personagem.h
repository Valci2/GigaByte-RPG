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
    int forcaDeArma = 0;
    int forcaDeArmadura = 0;
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
    void comprar(int quantidade);
    bool temCapibas(int custo);
    void equiparArma(std::string nome, int poder);
    void equiparArmadura(std::string nome, int poder);
    void trocarItem();

    // combate
    void magia();
    void usar_magia();
    bool usarItem(TipoPocao item);
    bool usarPocao(int quantidade, int atual,Entidade& alvo, TipoAtributo tipo);
    bool fugir();

    // Getter
    int getForcaDeArma();
    int getForcaDeArmadura();
    int getNivel();
    int getXP();
    int getFalta();
    Itens &getInventario();

    // Setter
    void setForcaDeArma(int forca);
    void setForcaDeArmadura(int forca);
    void setNivel(int nivel);
    void setXP(int xp);
};