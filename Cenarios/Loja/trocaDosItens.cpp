#include "trocaDosItens.h"
#include "../../funcoesUteis/funcoesUteis.h"
#include "../../Personagem/Personagem.h"
#include <iostream>

void trocaDaArma(Personagem &jogador) {
    while (true) {
        std::cout << "============= Arma =============" << std::endl;
        std::cout << "[1] Espada De Circuito (5 capibas)" << std::endl;
        std::cout << "[2] Espada ALU (30 capibas)" << std::endl;
        std::cout << "[3] Espada integrada (80 capibas)" << std::endl;
        std::cout << "[4] Espada Analogica (150 capibas)" << std::endl;
        std::cout << "[5] Espada De Agua (250 capibas)" << std::endl;
        std::cout << "[6] mudei de ideia, nao quero mais comprar armas" << std::endl;
        int capibasDoJogador = jogador.getInventario().getCapiba();
        std::cout << "saldo: " << capibasDoJogador << std::endl;

        int escolha;
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cout << "string e fogo" << std::endl;
            limparEntrada();
        }

        switch (escolha) {
            case 1:
                if (capibasDoJogador >= 5) {
                    jogador.getInventario().setCapiba(capibasDoJogador - 5);
                    jogador.getInventario().setArma("Espada De Circuito");
                } else {
                    std::cout << "nao tem capibas o suficiente" << std::endl;
                }
                break;
            case 2:
                if (capibasDoJogador >= 30) {
                    jogador.getInventario().setCapiba(capibasDoJogador - 30);
                    jogador.getInventario().setArma("Espada ALU");
                } else {
                    std::cout << "nao tem capibas o suficiente" << std::endl;
                }
                break;
            case 3:
                if (capibasDoJogador >= 80) {
                    jogador.getInventario().setCapiba(capibasDoJogador - 80);
                    jogador.getInventario().setArma("Espada integrada");
                } else {
                    std::cout << "nao tem capibas o suficiente" << std::endl;
                }
                break;
            case 4:
                if (capibasDoJogador >= 150) {
                    jogador.getInventario().setCapiba(capibasDoJogador - 150);
                    jogador.getInventario().setArma("Espada Analogica");
                } else {
                    std::cout << "nao tem capibas o suficiente" << std::endl;
                }
                break;
            case 5:
                if (capibasDoJogador >= 250) {
                    jogador.getInventario().setCapiba(capibasDoJogador - 250);
                    jogador.getInventario().setArma("Espada De Agua");
                } else {
                    std::cout << "nao tem capibas o suficiente" << std::endl;
                }
                break;
            case 6:
                return; // volta ao menu da loja
            default:
                std::cout << "nao possuimos essa arma" << std::endl;
                break;
        }
    }
}
