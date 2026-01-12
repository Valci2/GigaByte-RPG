#include "Personagem.h"
#include <iostream>
#include "Monstros/Monstro.h"
#include "Utilitarios.h"

// cosntrutor
Personagem::Personagem(const std::string &nome) : nome(nome) {}

// metodo
void Personagem::status() {
    std::cout << "============= status =============" << std::endl;
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "HP: " << HP << "/" << maxHP << std::endl;
    std::cout << "Mana: " << mana << "/" << maxMana << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Forca: " << forca << std::endl;
    std::cout << "Inteligencia: " << inteligencia << std::endl;
    std::cout << "Defesa: " << defesaBase << std::endl;
}

void Personagem::mostrarinventario() {
    std::cout << "============= inventario =============" << std::endl;
    std::cout << "Capibas: " << inventario.getCapiba() << std::endl;
    std::cout << "Pocao de Cura: " << inventario.getPocaoDeCura() << "/10" << std::endl;
    std::cout << "Pocao de Cura Forte: " << inventario.getPocaoDeCuraForte() << "/10" << std::endl;
    std::cout << "Pocao de Mana: " << inventario.getPocaoDeMana() << "/10" << std::endl;
    std::cout << "Pocao de Mana Forte: " << inventario.getPocaoDeManaForte() << "/10" << std::endl;
    std::cout << "Arma: " << inventario.getArma() << std::endl;
    std::cout << "Armadura: " << inventario.getArmadura() << std::endl;
}

void Personagem::dormir() {
    this->HP = maxHP;
    this->mana = maxMana;
}

void Personagem::subirDeNivel() {

}

// combate
void Personagem::atacar(Monstro& monstro) {
    int dano = static_cast<int> (this->forca * 1.4 + this->inteligencia * 0.5);
    std::cout << nome << " deu " << dano << " de dano" << std::endl;
    monstro.tomarDano(dano);
}

void Personagem::defender() {
    if (defendendo) return;

    std::cout << nome << " se defende" << std::endl;
    this->defendendo = true;
    this->defesaBonus = static_cast<int>(nivel * 0.5);
}

void Personagem::finalizarTurno() {
    defendendo = false;
    defesaBonus = 0;
}

void Personagem::tomarDano(int dano) {
    int danoTotal = dano - getDefesa();
    if (danoTotal <= 0) danoTotal = 1;
    HP -= danoTotal;
    if (HP <= 0) { HP = 0; }
}

void Personagem::magia() {}

void Personagem::usar_magia() {

}

bool Personagem::fugir() {
    int chance = randint(1, 100);
    if (chance >= 75) return true;
    return false;
}

void Personagem::statusDeCombate() {
    std::cout << "========= " << nome << " =========" << std::endl;
    std::cout << "HP: " << this->HP << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
}

bool Personagem::usarItem(TipoItem tipo) {
    switch (tipo) {
    case TipoItem::PocaoCura: return usarPocao(20, inventario.getPocaoDeCura(), &Itens::setPocaoDeCura, HP, maxHP, "Pocao de Cura");
    case TipoItem::PocaoCuraForte: return usarPocao(50, inventario.getPocaoDeCuraForte(), &Itens::setPocaoDeCuraForte, HP, maxHP, "Pocao de cura forte");
    case TipoItem::PocaoMana: return usarPocao(20, inventario.getPocaoDeMana(), &Itens::setPocaoDeMana, mana, maxMana, "Pocao de Mana");
    case TipoItem::PocaoManaForte: return usarPocao(50, inventario.getPocaoDeManaForte(), &Itens::setPocaoDeManaForte, mana, maxMana, "pocao de mana forte");
    }
    return false;
}

bool Personagem::usarPocao(int quantidade, int atual, void (Itens::*setter)(int), int& atributo, int maxAtributo, const std::string& nome) {
    if (atual <= 0) return false;
    if (atributo >= maxAtributo) return false;

    atributo += quantidade;
    if (atributo >= maxAtributo) atributo = maxAtributo;

    (inventario.*setter)(atual - 1);
    return true;
}

// getter
const std::string &Personagem::getNome() { return nome; }
int Personagem::getHP() { return HP; }
int Personagem::getMaxHP() { return maxHP; }
int Personagem::getMana() { return mana; }
int Personagem::getMaxMana() { return maxMana; }
int Personagem::getNivel() { return nivel; }
int Personagem::getForca() { return forca; }
int Personagem::getInteligencia() { return inteligencia; }
int Personagem::getDefesa() { return defesaBase + defesaBonus; }
int Personagem::getXP() { return XP; }
bool Personagem::getDefendendo(){ return defendendo; }
Itens &Personagem::getInventario() { return inventario; }

// setter
void Personagem::setNome(const std::string &nome) { this->nome = nome; }
void Personagem::setHP(int HP) { this->HP = HP; }
void Personagem::setMaxHP(int maxHP) { this->maxHP = maxHP; }
void Personagem::setMana(int mana) { this->mana = mana; }
void Personagem::setMaxMana(int maxMana) { this->maxMana = maxMana; }
void Personagem::setNivel(int nivel) { this->nivel = nivel; }
void Personagem::setForca(int forca) { this->forca = forca; }
void Personagem::setInteligencia(int inteligencia) { this->inteligencia = inteligencia; }
void Personagem::setDefesa(int defesa) { this->defesaBase = defesa; }
void Personagem::setXP(int xp) { this->XP = xp; }
void Personagem::setDefendendo(bool defendendo) { this->defendendo = defendendo; }