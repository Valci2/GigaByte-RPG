#include "Monstros/Monstro.h"
#include <iostream>
#include "Personagem.h"

Monstro::Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP, int capibas) : Entidade(nome, maxHP, maxMana, forca, inteligencia, defesaBase, XP), capibas(capibas) {}

int Monstro::getCapibas() { return capibas; }

void Monstro::setCapibas(int capibas) { this->capibas = capibas; }