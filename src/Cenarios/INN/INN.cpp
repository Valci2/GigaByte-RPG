#include "../../../inc/Cenarios/INN/INN.h"
#include "../../../inc/utilitarios/utilitarios.h"

#include <iostream>

void INN::entrar(Personagem &jogador) {
    int escolha = 0;
    while (true) {
        std::cout << "============== INN ==============" << std::endl;
        std::cout << "[1] Dormir" << std::endl;
        std::cout << "[2] Sair" << std::endl;
        std::cout << "Escolha: " << std::endl;

        std::cin >> escolha;

        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "Nao aceitamos strings, apenas ints" << std::endl;
        }

        switch (escolha) {
            case 1:
                std::cout << "Olha... ele dorme como um anjinho" << std::endl;
                std::cout << "ZZZZZZZZZZZZ" << std::endl;
                dormir(jogador);
                delay(3);
                return;
            case 2:
                std::cout << "Saindo do INN" << std::endl;
                delay(2);
                return;
            default:
                std::cout << "So temos as duas opcões acima" << std::endl;
        }
    }
}


void INN::dormir(Personagem &jogador) {
    jogador.setHP(jogador.getMaxHP());
    jogador.setMana(jogador.getMaxMana());
}
