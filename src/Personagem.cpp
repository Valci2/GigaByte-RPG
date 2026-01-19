#include "Personagem.h"
#include <iostream>
#include "Monstro.h"
#include "Utilitarios.h"

// cosntrutor
Personagem::Personagem(const std::string& nome) : Entidade(nome, 10 , 4, 2, 3, 1, 0) {}

// metodo
void Personagem::status() {
    std::cout << "============= status =============" << std::endl;
    std::cout << "Nome: " << getNome() << std::endl;
    std::cout << "Nivel: " << nivel << std::endl;
    std::cout << "HP: " << getHP() << "/" << getMaxHP() << std::endl;
    std::cout << "Mana: " << getMana() << "/" << getMaxMana() << std::endl;
    std::cout << "Forca: " << getForca() << std::endl;
    std::cout << "Inteligencia: " << getInteligencia() << std::endl;
    std::cout << "Defesa: " << getDefesa() << std::endl;
    std::cout << "XP: " << getXP() << std::endl;
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

void Personagem::trocarItem() {
    std::cout << "Quer trocar a arma ou a armadura" << std::endl;
    std::cout << "[1] - Arma" << std::endl;
    std::cout << "[2] - Armadura" << std::endl;
    std::cout << "[3] - Voltar" << std::endl;
    int escolha = validarEscolha(1, 3);
    
    if (escolha == 1) 
    {
        std::vector<Item> item = inventario.getArmas();
    
        for (size_t i = 0; i < inventario.getArmas().size(); i++){
            std::cout << "[" << i + 1 << "] - " << item[i].nome << " - Dano: " << item[i].poder << std::endl;
        }
    
        std::cout << "[" << item.size() + 1<< "]" << "- voltar" << std::endl;
    
        escolha = validarEscolha(1, item.size() + 1);
        escolha--;
        equiparArma(item[escolha].nome, item[escolha].poder);
    } 
    else if (escolha == 2) 
    {
        std::vector<Item> item = inventario.getArmaduras();
        for (size_t i = 0; i < inventario.getArmaduras().size(); i++){
            std::cout << "[" << i + 1 << "] - " << item[i].nome << " - Dano: " << item[i].poder << std::endl;
        }
        std::cout << "[" << item.size() + 1<< "]" << "- voltar" << std::endl;
        validarEscolha(1, item.size());
        escolha--;
        equiparArma(item[escolha].nome, item[escolha].poder);
    }
}

void Personagem::dormir() {
    setHP(getMaxHP());
    setMana(getMaxMana());
}

bool Personagem::temCapibas(int custo) {
    if (inventario.getCapiba() >= custo){
        return true;
    }
    return false;
}

void Personagem::comprar(int gastar) {
    int total = inventario.getCapiba() - gastar;
    inventario.setCapiba(total);
}

// ==========================================
// nivel do personagem
bool Personagem::ganharXP(int quantidade){
    setXP(getXP() + quantidade);

    // verifica se atingiu o limite para subir de nível
    int limite = nivel * 10;
    this->falta = limite - getXP();

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

// ==========================================
void Personagem::magia() {}

void Personagem::usar_magia() {}


// ==========================================
bool Personagem::fugir() {
    int chance = randint(1, 100);
    if (chance >= 75) return true;
    return false;
}

// escolha para usar o item
bool Personagem::usarItem(TipoPocao tipo) {
    switch (tipo)
    {
    case TipoPocao::PocaoCura: return usarPocao(20, inventario.getPocaoDeCura(), *this, TipoAtributo::HP);
    case TipoPocao::PocaoCuraForte: return usarPocao(50, inventario.getPocaoDeCuraForte(), *this, TipoAtributo::HP);
    case TipoPocao::PocaoMana: return usarPocao(20, inventario.getPocaoDeMana(), *this, TipoAtributo::Mana);
    case TipoPocao::PocaoManaForte: return usarPocao(50, inventario.getPocaoDeManaForte(), *this, TipoAtributo::Mana);
    }
    return false;
}

// usa a poção expecidifica
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

void Personagem::equiparArma(std::string nome, int poder) {
    this->setForca(getForca() - this->forcaDeArma);
    this->forcaDeArma = poder;
    this->inventario.setArma(nome);
    this->setForca(getForca() + poder);
}

void Personagem::equiparArmadura(std::string nome, int poder) {
    this->setDefesaBase(getDefesa() - this->forcaDeArmadura);
    this->forcaDeArmadura = 0;
    this->inventario.setArmadura(nome);
    this->setDefesaBase(getDefesaBase() + poder);
}

// getter
int Personagem::getForcaDeArma() { return forcaDeArma; }
int Personagem::getForcaDeArmadura() { return forcaDeArmadura; }
int Personagem::getNivel() { return nivel; }
int Personagem::getXP() { return XP; }
int Personagem::getFalta() { return falta; }
Itens &Personagem::getInventario() { return inventario; }

// setter
void Personagem::setForcaDeArma(int forca) { this->forcaDeArma = forca; }
void Personagem::setForcaDeArmadura(int forca) { this->forcaDeArmadura = forca;}
void Personagem::setNivel(int nivel) { this->nivel = nivel; }
void Personagem::setXP(int xp) { this->XP = xp; }