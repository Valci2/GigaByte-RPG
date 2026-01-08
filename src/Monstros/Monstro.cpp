#include "Monstros/Monstro.h"
#include "Personagem.h"

Monstro::Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesa) {
    this->nome = nome;
    this->maxHP = maxHP;
    this->HP = maxHP;
    this->maxMana = maxMana;
    this->mana = maxMana;
    this->forca = forca;
    this->inteligencia = inteligencia;
    this->defesa = defesa;
}

void Monstro::atacar(Personagem& jogador) {
    int dano = static_cast<int> (this->forca * 1.4 + this->inteligencia * 0.5 - jogador.getDefesa());
    if (dano <= 0) { dano = 1; }
    jogador.tomarDano(dano);
}

void Monstro::magia(Personagem &jogador) {

}

void Monstro::defender() {
    this->defesa += defesa + 2;
}

void Monstro::tomarDano(int dano) {
    HP -= dano;
    if (HP <= 0) { HP = 0; }
}


std::string Monstro::getNome() { return this->nome; }
int Monstro::getHP() { return this->HP; }
int Monstro::getMaxHP() { return this->maxHP; }
int Monstro::getMana() { return this->mana; }
int Monstro::getMaxMana() { return this->maxMana; }
int Monstro::getForce() { return this->forca; }
int Monstro::getInteligencia() { return this->inteligencia; }
int Monstro::getDefesa() { return this->defesa; }

void Monstro::setNome(const std::string &nome) { this->nome = nome; }
void Monstro::setHP(int HP) { this->HP = HP; }
void Monstro::setMaxHP(int maxHP) { this->maxHP = maxHP; }
void Monstro::setMana(int mana) { this->mana = mana; }
void Monstro::setMaxMana(int maxMana) { this->maxMana = maxMana; }
void Monstro::setForce(int force) { this->forca = force; }
void Monstro::setInteligencia(int inteligencia) { this->inteligencia = inteligencia; }
void Monstro::setDefesa(int defesa) { this->defesa = defesa; }