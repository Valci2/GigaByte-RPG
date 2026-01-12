#include "Monstros/Monstro.h"
#include <iostream>
#include "Personagem.h"

Monstro::Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase) {
    this->nome = nome;
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->maxMana = maxMana;
    this->mana = maxMana;
    this->forca = forca;
    this->inteligencia = inteligencia;
    this->defesaBonus = 0;
    this->defesaBase = defesaBase;
}

// combate
void Monstro::atacar(Personagem& jogador) {
    int dano = static_cast<int> (this->forca * 1.2 + this->inteligencia * 0.1);
    std::cout << nome << " deu " << dano << " de dano" << std::endl;
    jogador.tomarDano(dano);
}

void Monstro::magia(Personagem &jogador) {

}

void Monstro::defender() {
    if (defendendo) return;

    std::cout << nome << " se defende" << std::endl;
    this->defendendo = true;
    this->defesaBonus +=  2;
}

void Monstro::finalizarTurno() {
    defendendo = false;
    defesaBonus = 0;
}

void Monstro::tomarDano(int dano) {
    int danoTotal = dano - getDefesa();
    if (danoTotal <= 0) danoTotal = 1;
    HP -= danoTotal;
    if (HP <= 0) { HP = 0; }
}

void Monstro::statusDeCombate() {
    std::cout << "========= " << nome << " =========" << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
}

// getters
std::string Monstro::getNome() { return this->nome; }
int Monstro::getHP() { return this->HP; }
int Monstro::getMaxHP() { return this->maxHP; }
int Monstro::getMana() { return this->mana; }
int Monstro::getMaxMana() { return this->maxMana; }
int Monstro::getForce() { return this->forca; }
int Monstro::getInteligencia() { return this->inteligencia; }
int Monstro::getDefesa() { return this->defesaBase + defesaBonus; }
bool Monstro::getDefendendo() { return this->defendendo; }

// setters
void Monstro::setNome(const std::string &nome) { this->nome = nome; }
void Monstro::setHP(int HP) { this->HP = HP; }
void Monstro::setMaxHP(int maxHP) { this->maxHP = maxHP; }
void Monstro::setMana(int mana) { this->mana = mana; }
void Monstro::setMaxMana(int maxMana) { this->maxMana = maxMana; }
void Monstro::setForce(int force) { this->forca = force; }
void Monstro::setInteligencia(int inteligencia) { this->inteligencia = inteligencia; }
void Monstro::setDefesaBase(int defesa) { this->defesaBase = defesa; }
void Monstro::setDefendendo(bool defendendo){ this->defendendo = defendendo; }