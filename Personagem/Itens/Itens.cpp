#include "Itens.h"
#include "../Personagem.h"

Itens::Itens() {}

void Itens::usarPocaoDeCura(Personagem jogador) {}

void Itens::usarPocaoDeCuraForte() {}

void Itens::usarPocaoDeMana() {}

void Itens::usarPocaoDeManaForte() {}

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

