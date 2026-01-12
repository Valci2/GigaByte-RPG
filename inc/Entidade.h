#pragma once

#include <string>

class Entidade {
private:
    std::string nome;
    int HP;
    int maxHP;
    int mana;
    int maxMana;
    int forca;
    int inteligencia;
    int defesaBase;
    int defesaBonus;
    bool defendendo = false;

public:
    Entidade(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase);
    virtual ~Entidade() = default;

    // combate
    virtual void atacar(Entidade& alvo);
    virtual void defender();
    virtual void magia(Entidade& alvo);
    virtual void tomarDano(int dano);
    virtual void statusDeCombate();
    virtual void finalizarTurno();

    // getters
    std::string getNome();
    int getHP();
    int getMaxHP();
    int getMana();
    int getMaxMana();
    int getForce();
    int getInteligencia();
    int getDefesa();
    bool getDefendendo();

    // setters
    void setNome(const std::string &nome);
    void setMaxHP(int maxHP);
    void setHP(int HP);
    void setMaxMana(int maxMana);
    void setMana(int mana);
    void setForce(int force);
    void setInteligencia(int inteligencia);
    void setDefesaBase(int defesaBase);
    void setDefendendo(bool defendendo);
};