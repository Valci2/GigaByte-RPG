#pragma once
#include <string>
class Personagem;

class Monstro {
private:
    std::string nome;
    int HP;
    int maxHP;
    int mana;
    int maxMana;
    int forca;
    int inteligencia;
    int defesa;

public:
    Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesa);
    virtual ~Monstro() = default;

    virtual void atacar(Personagem& jogador);
    virtual void defender();
    virtual void magia(Personagem& jogador);
    virtual void tomarDano(int dano);

    std::string getNome();
    int getHP();
    int getMaxHP();
    int getMana();
    int getMaxMana();
    int getForce();
    int getInteligencia();
    int getDefesa();

    void setNome(const std::string &nome);
    void setMaxHP(int maxHP);
    void setHP(int HP);
    void setMaxMana(int maxMana);
    void setMana(int mana);
    void setForce(int force);
    void setInteligencia(int inteligencia);
    void setDefesa(int defesa);
};