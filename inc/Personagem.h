#pragma once
#include <string>

#include "Entidade.h"
#include "Itens.h"
#include "Tipos.h"

class Personagem : public Entidade {
private:
    int nivel = 1;
    int XP = 0;
    Itens inventario; // classe de atributo publico

public:
    // construtor
    Personagem(const std::string &nome);

    // metodos
    void status();
    void mostrarinventario();
    void subirDeNivel(int limite);
    void ganharXP(int quantidade);
    void dormir();

    // combate
    void magia();
    void usar_magia();
    bool usarItem(TipoItem item);
    bool usarPocao(int quantidade, int atual, void (Itens::*setter)(int), int& atributo, int maxAtributo, const std::string& nome);
    bool fugir();

    // Getter
    int getNivel();
    int getXP();
    Itens &getInventario();

    // Setter
    void setNivel(int nivel);
    void setXP(int xp);
};