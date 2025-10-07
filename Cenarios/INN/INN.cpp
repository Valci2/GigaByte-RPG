#include "../INN/INN.h"
#include "../../Personagem/Personagem.h"
#include "../../funcoesUteis/funcoesUteis.h"
#include <iostream>

void dentroDoINN(Personagem &jogador) {
    std::cout << "============= INN =============" << std::endl;
    std::cout << "Ola meu chapa " << jogador.getNome() << " acho que voce merece um descanco." << std::endl;
    std::cout << "HP: " << jogador.getHP() << "/" << jogador.getMaxHP() << std::endl;
    std::cout << "Mana: " << jogador.getMana() << "/" << jogador.getMaxMana() << std::endl;

    int capibasDoJogador = jogador.getInventario().getCapiba();
    int precoDeDormir = static_cast<int>(capibasDoJogador * 0.1);

    if (capibasDoJogador <= 9) {
        std::cout << "tu ta tao pobre que eu deixo voce dormir aqui de graca." << std::endl;
    } else {
        std::cout << "Voce precisa de pelo menos " << precoDeDormir << " capibas para dormir." << std::endl;
        std::cout << "Voce tem " << capibasDoJogador << " capibas." << std::endl;
    }
    linha();
    std::cout << "[1] dormir" << std::endl;
    std::cout << "[2] sair " << std::endl;

    int escolha = 0;

    while (true) {
        std::cin >> escolha;

        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "Nao aceitamos strings, apenas ints." << std::endl;
            continue;
        }

        switch (escolha) {
            case 1:
                if (capibasDoJogador >= precoDeDormir) {
                    jogador.getInventario().setCapiba(capibasDoJogador - precoDeDormir);
                    jogador.setHP(jogador.getMaxHP());
                    jogador.setMana(jogador.getMaxMana());
                    std::cout << jogador.getNome() << " esta dormindo como um como se tivessem desligador da tomada." <<
                            std::endl;
                    std::cout << "ZZZZZZZZZZZZ" << std::endl;
                    delay(2);
                    return; // volta para o lobby depois de dormir
                }
                std::cout << "Voce nao tem capibas suficientes para dormir." << std::endl;
                break;

            case 2:
                std::cout << "Saindo do INN..." << std::endl;
                delay(2);
                return; // volta para o lobby

            default:
                std::cout << "O INN so suporta os digitos 1 e 2" << std::endl;
                break;
        }
    }
}