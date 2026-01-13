#include "Monstros/Monstro.h"
#include <iostream>
#include "Personagem.h"

Monstro::Monstro(const std::string &nome, int maxHP, int maxMana, int forca, int inteligencia, int defesaBase, int XP) : Entidade(nome, maxHP, maxMana, forca, inteligencia, defesaBase, XP) {}