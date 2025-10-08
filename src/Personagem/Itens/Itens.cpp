#include "../../../inc/Personagem/Itens/Itens.h"

// construtor
Itens::Itens() {}

// metodos
void Itens::usarPocaoDeCura() {}
void Itens::usarPocaoDeCuraForte() {}
void Itens::usarPocaoDeMana() {}
void Itens::usarPocaoDeManaForte() {}

// getter
int Itens::getCapiba() {
    return capiba;
}

int Itens::getPocaoDeCura() {
    return pocaoDeCura;
}

int Itens::getPocaoDeCuraForte() {
    return pocaoDeCuraForte;
}

int Itens::getPocaoDeMana() {
    return pocaoDeMana;
}

int Itens::getPocaoDeManaForte() {
    return pocaoDeManaForte;
}

const std::string &Itens::getArma() {
    return arma;
}

const std::string &Itens::getArmadura() {
    return armadura;
}

// setter
void Itens::setCapiba(int Capiba) {
    this->capiba = Capiba;
}

void Itens::setPocaoDeCura(int pocaoDeCura) {
    this->pocaoDeCura = pocaoDeCura;
}

void Itens::setPocaoDeCuraForte(int pocaoDeCuraForte) {
    this->pocaoDeCuraForte = pocaoDeCuraForte;
}

void Itens::setPocaoDeMana(int pocaoDeMana) {
    this->pocaoDeMana = pocaoDeMana;
}

void Itens::setPocaoDeManaForte(int pocaoDeManaForte) {
    this->pocaoDeManaForte = pocaoDeManaForte;
}

void Itens::setArma(const std::string &arma) {
    this->arma = arma;
}

void Itens::serArmadura(const std::string &armadura) {
    this->armadura = armadura;
}