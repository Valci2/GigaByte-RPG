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
    int XP;
    bool defendendo = false;

public:
    Entidade(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP);
    virtual ~Entidade() = default;

    // combate
    virtual int atacar(Entidade& alvo);
    virtual void defender();
    virtual void magia(Entidade& alvo);
    virtual int tomarDano(int dano);
    virtual void statusDeCombate();
    virtual void finalizarTurno();

    // getters
    std::string& getNome();
    int& getHP();
    int& getMaxHP();
    int& getMana();
    int& getMaxMana();
    int& getForca();
    int& getInteligencia();
    int& getDefesaBase();
    int getDefesa();
    int& getXP();
    bool& getDefendendo();

    // setters
    void setNome(const std::string &nome);
    void setMaxHP(int maxHP);
    void setHP(int HP);
    void setMaxMana(int maxMana);
    void setMana(int mana);
    void setForca(int forca);
    void setInteligencia(int inteligencia);
    void setDefesaBase(int defesaBase);
    void setDefesaBonus(int defesaBonus);
    void setXP(int XP);
    void setDefendendo(bool defendendo);
};