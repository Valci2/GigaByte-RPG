#pragma once
#include <string>

#include "Itens.h"
class Monstro;

class Personagem {
private:
    std::string nome;
    int HP = 10;
    int maxHP = 10;
    int mana = 2;
    int maxMana = 2;
    int nivel = 1;
    int forca = 1;
    int inteligencia = 1;
    int defesa = 0;
    Itens inventario; // classe de atributo publico

public:
    // construtor
    Personagem(const std::string &nome);

    // metodos
    void status();
    void mostrarinventario();
    void subirDeNivel();
    void dormir();

    // combate
    void atacar(Monstro& monstro);
    void defender();
    void usar_magia();
    void fugir();
    void tomarDano(int dano);

    // metodos para usar itens
    void usarPocaoDeCura();
    void usarPocaoDeCuraForte();
    void usarPocaoDeMana();
    void usarPocaoDeManaForte();

    // Getter
    const std::string &getNome();
    int getHP();
    int getMaxHP();
    int getMaxMana();
    int getMana();
    int getNivel();
    int getForca();
    int getInteligencia();
    int getDefesa();
    Itens &getInventario();

    // Setter
    void setNome(const std::string &nome);
    void setHP(int hp);
    void setMaxHP(int maxHP);
    void setMana(int mana);
    void setMaxMana(int mana);
    void setNivel(int nivel);
    void setForca(int forca);
    void setInteligencia(int inteligencia);
    void setDefesa(int defesa);
};