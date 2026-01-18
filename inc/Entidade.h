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
    virtual void finalizarTurno();
    virtual bool estaVivo();

    // getters
    const std::string& getNome() const;
    int getHP() const;
    int getMaxHP() const;
    int getMana() const;
    int getMaxMana() const;
    int getForca() const;
    int getInteligencia() const;
    int getDefesaBase() const;
    int getDefesa() const;
    int getXP() const;
    bool getDefendendo() const;

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