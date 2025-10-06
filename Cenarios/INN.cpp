#include "INN.h"
#include "../Personagem/Personagem.h"
#include "../funcoesUteis/funcoesUteis.h"
#include <iostream>

void dentroDoINN(Personagem &jogador) {
    std::cout << "============= INN =============" << std::endl;
    std::cout << "Ola meu chapa " << jogador.getNome() << " acho que voce merece um descanco" << std::endl;
    std::cout << "HP: " << jogador.getMaxHP() << "/" << jogador.getHP() << std::endl;
    std::cout << "Mana: " << jogador.getMaxMana() << "/" << jogador.getMana() << std::endl;
    std::cout << "[1] dormir" << std::endl;
    std::cout << "[2] sair " << std::endl;

    int escolha = 0;

    while (true) {
        std::cin >> escolha;
        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "Nao aceitamos strings, apenas ints" << std::endl;
            continue;
        }
        if (escolha == 1) {
            jogador.setHP(jogador.getMaxHP());
            jogador.setMana(jogador.getMaxMana());
            std::cout << jogador.getNome() << " esta dormindo como um como se tivessem desligador da tomada" <<
                    std::endl;
            std::cout << "ZZZZZZZZZZZZ" << std::endl;
            delay(3);
            return; // volta para o lobby depois de dormir
        }
        if (escolha == 2) {
            std::cout << "Saindo do INN..." << std::endl;
            delay(1);
            return; // volta para o lobby
        }
        std::cout << "O INN so suporta os digitos 1 e 2" << std::endl;
    }
}