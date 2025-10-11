#include "../../inc/Lobby/Lobby.h"
#include "../../inc/utilitarios/utilitarios.h"
#include <iostream>

Lobby::Lobby(Personagem &jogador) : jogador(jogador) {}

void Lobby::mostrarMenu() const {
    std::cout << "============== Lobby ==============" << std::endl;
    std::cout << "[1] - Fases" << std::endl;
    std::cout << "[2] - Loja" << std::endl;
    std::cout << "[3] - INN" << std::endl;
    std::cout << "[4] - Status" << std::endl;
    std::cout << "[5] - Inventario" << std::endl;
    std::cout << "[0] - Sair" << std::endl;
}

void Lobby::processarEscolha(int escolha) {
    switch (escolha) {
        case 3:

            inn.entrar(jogador);
            break;
        case 4:
            jogador.status();
            delay(2);
            break;
        case 5:
            jogador.mostrarinventario();
            delay(2);
            break;
        case 0:
            exit(0);
        default:
            std::cout << "Fora do tamanho da array" << std::endl;
            delay(3);
    }
}

void Lobby::iniciar() {
    int escolha = 0;
    do {
        mostrarMenu();
        std::cout << "Escolha: ";
        std::cin >> escolha;

        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "Entrada inválida!" << std::endl;
            delay(2);
            continue;
        }

        processarEscolha(escolha);

    } while (escolha != 0);
}