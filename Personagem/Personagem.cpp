#include "Personagem.h"
#include <iostream>

// cosntrutor
Personagem::Personagem(const std::string &nome) : nome(nome) {
}

// metodo
void Personagem::status() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "HP: " << HP << std::endl;
    std::cout << "Mana: " << mana << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Forca: " << forca << std::endl;
    std::cout << "Inteligencia: " << inteligencia << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
}

void Personagem::inventario() {
    std::cout << "Pocao de Cura: " << itens.getPocaoDeCura() << std::endl;
    std::cout << "Pocao de Cura Forte: " << itens.getPocaoDeCuraForte() << std::endl;
    std::cout << "Pocao de Mana: " << itens.getPocaoDeMana() << std::endl;
    std::cout << "Pocao de Mana Forte: " << itens.getPocaoDeManaForte() << std::endl;
    std::cout << "Arma: " << itens.getArma() << std::endl;
    std::cout << "Armadura: " << itens.getArmadura() << std::endl;
}

std::string Personagem::getNome() {
    return nome;
}

int Personagem::getHP() {
    return HP;
}

int Personagem::getMaxHP() {
    return maxHP;
}


int Personagem::getMana() {
    return mana;
}

int Personagem::getMaxMana() {
    return maxMana;
}


int Personagem::getNivel() {
    return nivel;
}

int Personagem::getForca() {
    return forca;
}

int Personagem::getInteligencia() {
    return inteligencia;
}

int Personagem::getDefesa() {
    return defesa;
}

int Personagem::getOuro() {
    return ouro;
}

void Personagem::setNome(const std::string &nome) {
    this->nome = nome;
}

void Personagem::setHP(int HP) {
    this->HP = HP;
}

void Personagem::setMaxHP(int maxHP) {
    this->maxHP = maxHP;
}

void Personagem::setMana(int mana) {
    this->mana = mana;
}

void Personagem::setMaxMana(int maxMana) {
    this->maxMana = maxMana;
}

void Personagem::setNivel(int nivel) {
    this->nivel = nivel;
}

void Personagem::setForca(int forca) {
    this->forca = forca;
}

void Personagem::setInteligencia(int inteligencia) {
    this->inteligencia = inteligencia;
}

void Personagem::setDefesa(int defesa) {
    this->defesa = defesa;
}

void Personagem::setOuro(int ouro) {
    this->ouro = ouro;
}