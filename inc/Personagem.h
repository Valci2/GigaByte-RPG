#pragma once
#include <string>

#include "Itens.h"
#include "Tipos.h"

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
    int defesaBase = 0;
    int defesaBonus = 0;
    int XP = 0;
    bool defendendo = false;
    Itens inventario; // classe de atributo publico

public:
    // construtor
    Personagem(const std::string &nome);

    // metodos
    void status();
    void mostrarinventario();
    void subirDeNivel();
    void dormir();
    void statusDeCombate();
    void finalizarTurno();

    // combate
    void atacar(Monstro& monstro);
    void defender();
    void magia();
    void usar_magia();
    bool usarItem(TipoItem item);
    bool usarPocao(int quantidade, int atual, void (Itens::*setter)(int), int& atributo, int maxAtributo, const std::string& nome);
    bool fugir();
    void tomarDano(int dano);
    bool usarPocaoDeCura(int quantidade, int quantidadeDePoca, void (Itens::*setter)(int));
    bool usarPocaoDeMana(int quantidade, int quantidadeDePocao, void (Itens::*setter)(int));

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
    int getXP();
    bool getDefendendo();
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
    void setXP(int xp);
    void setDefendendo(bool defendendo);
};