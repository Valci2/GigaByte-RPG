#include "Combate.h"
#include "Utilitarios.h"
#include <iostream>
#include <vector>

Combate::Combate() {}
Combate::~Combate() {}

// listas de monstros generica da primeira fase
std::vector<Monstro> monstrosFaseUm = {
    Monstro("Disco", 10, 10, 10, 10, 10),
    Monstro("Memoria virtual", 10, 10, 10, 10, 10),
    Monstro("RAM", 10, 10, 10, 10, 10)
};

// listas de monstros generica da segunda fase
std::vector<Monstro> monstrosFaseDois = {
    Monstro("Barramento", 10, 10, 10, 10, 10),
    Monstro("Placa", 10, 10, 10, 10, 10),
    Monstro("UEFI", 10, 10, 10, 10, 10)
};

// listas de monstros generica da terceira fase
std::vector<Monstro> monstrosFaseTres = {
    Monstro("Loop Infinito", 10, 10, 10, 10, 10),
    Monstro("Divisao", 10, 10, 10, 10, 10),
    Monstro("CPU", 10, 10, 10, 10, 10)
};

// menu de escolhas para o combate
void menu() {
    std::cout << "+--------------+" << std::endl;
    std::cout << "| [1] Atacar   |" << std::endl;
    std::cout << "| [2] Defender |" << std::endl;
    std::cout << "| [3] Magia    |" << std::endl;
    std::cout << "| [4] Item     |" << std::endl;
    std::cout << "| [5] Fugir    |" << std::endl;
    std::cout << "+--------------+" << std::endl;
}

void Combate::escolhaDoMonstro(Personagem& jogador, std::vector<Monstro>& monstros, int parte) {
    int indice = randint(0, monstros.size() - 1);
    Monstro atacante = monstros[indice];
}

void Combate::gerenciamentoDeCombate(Personagem &jogador, int fase, int parte) {
    if (fase == 1) {
        escolhaDoMonstro(jogador, monstrosFaseUm, parte);
    }
    else if (fase == 2) {
        escolhaDoMonstro(jogador, monstrosFaseDois, parte);
    }
    else if (fase == 3) {
        escolhaDoMonstro(jogador, monstrosFaseTres, parte);
    }
}
