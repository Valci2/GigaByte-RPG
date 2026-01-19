#include "Itens.h"

#include <iostream>

// construtor
Itens::Itens() {}

void Itens::adicionarPocao(const std::string &nome, int quantidade) {
    if (nome == "Pocao de Cura") pocaoDeCura += quantidade;
    else if (nome == "Pocao de Cura Forte") pocaoDeCuraForte += quantidade;
    else if (nome == "Pocao de Mana") pocaoDeMana += quantidade;
    else if (nome == "Pocao de Mana Forte") pocaoDeManaForte += quantidade;
}

// getter
int Itens::getCapiba() { return capiba; }
int Itens::getPocaoDeCura() { return pocaoDeCura; }
int Itens::getPocaoDeCuraForte() { return pocaoDeCuraForte; }
int Itens::getPocaoDeMana() { return pocaoDeMana; }
int Itens::getPocaoDeManaForte() { return pocaoDeManaForte; }

// setter
void Itens::setCapiba(int Capiba) { this->capiba = Capiba; }
void Itens::setPocaoDeCura(int pocaoDeCura) { this->pocaoDeCura = pocaoDeCura; }
void Itens::setPocaoDeCuraForte(int pocaoDeCuraForte) { this->pocaoDeCuraForte = pocaoDeCuraForte; }
void Itens::setPocaoDeMana(int pocaoDeMana) { this->pocaoDeMana = pocaoDeMana; }
void Itens::setPocaoDeManaForte(int pocaoDeManaForte) { this->pocaoDeManaForte = pocaoDeManaForte; }

const std::string &Itens::getArma() { return this->armaEquipada; }
const std::string &Itens::getArmadura() { return this->armaduraEquipada; }

void Itens::setArma(const std::string &arma) { this->armaEquipada = arma; }
void Itens::setArmadura(const std::string &armadura) { this->armaduraEquipada = armadura; }

const std::vector<Item> &Itens::getArmas() { return this->armas; }
const std::vector<Item> &Itens::getArmaduras() { return this->armaduras; }

void Itens::setArmas(const Item &arma) { this->armas.push_back(arma); }
void Itens::setArmaduras(const Item &armadura) { this->armaduras.push_back(armadura); }