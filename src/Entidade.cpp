#include "../inc/Entidade.h"
#include <iostream>

Entidade::Entidade(const std::string& nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase) {
    this->nome = nome;
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->maxMana = maxMana;
    this->mana = maxMana;
    this->forca = forca;
    this->inteligencia = inteligencia;
    this->defesaBase = defesaBase;
}

// combate
void Entidade::atacar(Entidade& alvo) {
    int dano = static_cast<int> (this->forca * 1.2 + this->inteligencia * 0.1);
    std::cout << nome << " deu " << dano << " de dano" << std::endl;
    alvo.tomarDano(dano);
}

void Entidade::magia(Entidade& alvo) {

}

void Entidade::defender() {
    if (defendendo) return;

    std::cout << nome << " se defende" << std::endl;
    this->defendendo = true;
    this->defesaBonus +=  2;
}

void Entidade::finalizarTurno() {
    defendendo = false;
    defesaBonus = 0;
}

void Entidade::tomarDano(int dano) {
    int danoTotal = dano - getDefesa();
    if (danoTotal <= 0) danoTotal = 1;
    HP -= danoTotal;
    if (HP <= 0) { HP = 0; }
}

void Entidade::statusDeCombate() {
    std::cout << "========= " << nome << " =========" << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
}

// getters
std::string Entidade::getNome() { return this->nome; }
int Entidade::getHP() { return this->HP; }
int Entidade::getMaxHP() { return this->maxHP; }
int Entidade::getMana() { return this->mana; }
int Entidade::getMaxMana() { return this->maxMana; }
int Entidade::getForce() { return this->forca; }
int Entidade::getInteligencia() { return this->inteligencia; }
int Entidade::getDefesa() { return this->defesaBase + defesaBonus; }
bool Entidade::getDefendendo() { return this->defendendo; }

// setters
void Entidade::setNome(const std::string &nome) { this->nome = nome; }
void Entidade::setHP(int HP) { this->HP = HP; }
void Entidade::setMaxHP(int maxHP) { this->maxHP = maxHP; }
void Entidade::setMana(int mana) { this->mana = mana; }
void Entidade::setMaxMana(int maxMana) { this->maxMana = maxMana; }
void Entidade::setForce(int force) { this->forca = force; }
void Entidade::setInteligencia(int inteligencia) { this->inteligencia = inteligencia; }
void Entidade::setDefesaBase(int defesa) { this->defesaBase = defesa; }
void Entidade::setDefendendo(bool defendendo){ this->defendendo = defendendo; }