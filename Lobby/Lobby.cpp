#include "Lobby.h"
#include <iostream>
#include "../Cenarios/INN.h"
#include "../funcoesUteis/funcoesUteis.h"

void lobby(Personagem &jogador) {
    while (true) {
        std::cout << "============= Lobby =============" << std::endl;
        std::cout << "[1] Fases" << std::endl;
        std::cout << "[2] Loja" << std::endl;
        std::cout << "[3] INN" << std::endl;
        std::cout << "[4] Status" << std::endl;
        std::cout << "[5] Inventario" << std::endl;

        int escolha = 0;
        int a = 0;
        std::cout << "O que voce quer fazer: ";
        std::cin >> escolha;
        linha();
        switch (escolha) {
            case 3:
                a = dentroDoINN(jogador); // tem que resumir isso
                break;
            case 4:
                jogador.status();
                break;
            case 5:
                jogador.inventario();
                break;
            default:
                std::cout << "Ta dando uma de chapezinho? respeita os caminhos!" << std::endl;
        }
        if (std::cin.fail()) {
            std::cout << "Nao tenho esse caminho na memoria. Como eu vou ir?" << std::endl;
            limparEntrada();
        }
    }
}
