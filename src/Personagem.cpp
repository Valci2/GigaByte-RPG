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
void Personagem::ganharXP(int quantidade){
    setXP(getXP() + quantidade);

    // verifica se atingiu o limite para subir de nível
    int limite = nivel * 10; // exemplo: cada nível precisa de 100 * nivel XP
    if (XP >= limite) subirDeNivel(limite);
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
    case TipoItem::PocaoCura: return usarPocao(20, inventario.getPocaoDeCura(), &Itens::setPocaoDeCura, getHP(), getMaxHP(), "Pocao de Cura");
    case TipoItem::PocaoCuraForte: return usarPocao(50, inventario.getPocaoDeCuraForte(), &Itens::setPocaoDeCuraForte, getHP(), getMaxHP(), "Pocao de cura forte");
    case TipoItem::PocaoMana: return usarPocao(20, inventario.getPocaoDeMana(), &Itens::setPocaoDeMana, getMana(), getMaxMana(), "Pocao de Mana");
    case TipoItem::PocaoManaForte: return usarPocao(50, inventario.getPocaoDeManaForte(), &Itens::setPocaoDeManaForte, getMana(), getMaxMana(), "pocao de mana forte");
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
int Personagem::getNivel() { return nivel; }
int Personagem::getXP() { return XP; }
Itens &Personagem::getInventario() { return inventario; }

// setter
void Personagem::setNivel(int nivel) { this->nivel = nivel; }
void Personagem::setXP(int xp) { this->XP = xp; }