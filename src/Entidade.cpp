#include "../inc/Entidade.h"
#include <iostream>

Entidade::Entidade(const std::string& nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP) {
    this->nome = nome;
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->maxMana = maxMana;
    this->mana = maxMana;
    this->forca = forca;
    this->inteligencia = inteligencia;
    this->defesaBase = defesaBase;
    this->defesaBonus = 0;
    this->XP = XP;
}

// combate
int Entidade::atacar(Entidade& alvo) {
    int dano = static_cast<int> (this->forca * 1.2 + this->inteligencia * 0.1 - alvo.getDefesa());
    dano = alvo.tomarDano(dano);
    return dano;
}

void Entidade::magia(Entidade& alvo) {

}

void Entidade::defender() {
    if (defendendo) return;

    this->defendendo = true;
    this->defesaBonus +=  2;
}

void Entidade::finalizarTurno() {
    defendendo = false;
    defesaBonus = 0;
}

int Entidade::tomarDano(int dano) {
    if (dano <= 0) dano = 1;
    HP -= dano;
    if (HP <= 0) { HP = 0; }
    return dano;
}



bool Entidade::estaVivo()
{
    return HP > 0;
}

// getters
const std::string& Entidade::getNome() const { return this->nome; }
int Entidade::getHP() const { return this->HP; }
int Entidade::getMaxHP() const { return this->maxHP; }
int Entidade::getMana() const { return this->mana; }
int Entidade::getMaxMana() const { return this->maxMana; }
int Entidade::getForca() const { return this->forca; }
int Entidade::getInteligencia() const { return this->inteligencia; }
int Entidade::getDefesaBase() const { return this->defesaBase; }
int Entidade::getDefesa() const { return this->defesaBase + defesaBonus; }
int Entidade::getXP() const { return this->XP; }
bool Entidade::getDefendendo() const { return this->defendendo; }

// setters
void Entidade::setNome(const std::string &nome) { this->nome = nome; }
void Entidade::setHP(int HP) { this->HP = HP; }
void Entidade::setMaxHP(int maxHP) { this->maxHP = maxHP; }
void Entidade::setMana(int mana) { this->mana = mana; }
void Entidade::setMaxMana(int maxMana) { this->maxMana = maxMana; }
void Entidade::setForca(int forca) { this->forca = forca; }
void Entidade::setInteligencia(int inteligencia) { this->inteligencia = inteligencia; }
void Entidade::setDefesaBase(int defesa) { this->defesaBase = defesa; }
void Entidade::setDefesaBonus(int defesa) { this->defesaBonus = defesa; }
void Entidade::setXP(int XP) { this->XP = XP; }
void Entidade::setDefendendo(bool defendendo){ this->defendendo = defendendo; }