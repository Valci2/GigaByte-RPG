#include "Personagem.h"
#include <iostream>
#include "Monstros/Monstro.h"
#include "Utilitarios.h"

// cosntrutor
Personagem::Personagem(const std::string& nome) : Entidade(nome, 10 , 4, 2, 3, 1, 0) {}

// metodo
void Personagem::status() {
    std::cout << "============= status =============" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "HP: " << getHP() << "/" << getMaxHP() << std::endl;
    std::cout << "Mana: " << getMana() << "/" << getMaxMana() << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "Forca: " << getForca() << std::endl;
    std::cout << "Inteligencia: " << getInteligencia() << std::endl;
    std::cout << "Defesa: " << getDefesa() << std::endl;
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
    setHP(getMaxHP());
    setMana(getMaxMana());
}

// nivel do personagem
bool Personagem::ganharXP(int quantidade){
    setXP(getXP() + quantidade);

    // verifica se atingiu o limite para subir de nível
    int limite = nivel * 10; // exemplo: cada nível precisa de 100 * nivel XP
    if (XP >= limite) { subirDeNivel(limite); return true; }
    return false;
}

void Personagem::subirDeNivel(int limite) {

    int excedente = getXP() - limite;
    setXP(excedente);
    nivel++;

    // aumento de atributos
    setMaxHP(getMaxHP() + 3);
    setMaxMana(getMaxMana() + 2);
    setForca(getForca() + 1);
    setInteligencia(getInteligencia() + 1);
    setDefesaBase(getDefesa() + 1);

    // recupera vida e mana
    setHP(getMaxHP());
    setMana(getMaxMana());
}

void Personagem::magia() {}

void Personagem::usar_magia() {}

bool Personagem::fugir() {
    int chance = randint(1, 100);
    if (chance >= 75) return true;
    return false;
}

bool Personagem::usarItem(TipoItem tipo) {
    switch (tipo) {
    case TipoItem::PocaoCura:
        return usarPocao(20, inventario.getPocaoDeCura(), *this, TipoAtributo::HP);

    case TipoItem::PocaoCuraForte:
        return usarPocao(50, inventario.getPocaoDeCuraForte(), *this, TipoAtributo::HP);

    case TipoItem::PocaoMana:
        return usarPocao(20, inventario.getPocaoDeMana(), *this, TipoAtributo::Mana);

    case TipoItem::PocaoManaForte:
        return usarPocao(50, inventario.getPocaoDeManaForte(), *this, TipoAtributo::Mana);
    }
    return false;
}


bool Personagem::usarPocao(int quantidade, int atual, Entidade& alvo, TipoAtributo tipo) {

    if (atual <= 0) return false;

    if (tipo == TipoAtributo::HP)
    {
        if (alvo.getHP() >= alvo.getMaxHP())
            return false;

        int novoHP = alvo.getHP() + quantidade;
        if (novoHP > alvo.getMaxHP())
            novoHP = alvo.getMaxHP();

        alvo.setHP(novoHP);

    }
    else 
    { // Mana
        if (alvo.getMana() >= alvo.getMaxMana())
            return false;

        int novaMana = alvo.getMana() + quantidade;
        if (novaMana > alvo.getMaxMana())
            novaMana = alvo.getMaxMana();

        alvo.setMana(novaMana);
    }

    // consome a poção
    if (tipo == TipoAtributo::HP) {
        inventario.setPocaoDeCura(atual - 1);
    } else {
        inventario.setPocaoDeMana(atual - 1);
    }

    return true;
}

// getter
int Personagem::getNivel() { return nivel; }
int Personagem::getXP() { return XP; }
Itens &Personagem::getInventario() { return inventario; }

// setter
void Personagem::setNivel(int nivel) { this->nivel = nivel; }
void Personagem::setXP(int xp) { this->XP = xp; }