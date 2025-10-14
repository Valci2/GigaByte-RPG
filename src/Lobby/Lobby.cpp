#include "Lobby/Lobby.h"
#include "utilitarios/utilitarios.h"
#include <iostream>

Lobby::Lobby(Personagem &jogador) : jogador(jogador) {}

void Lobby::mostrarMenu() const {
    titulo("Lobby");
    std::cout << "[1] - Fases" << std::endl;
    std::cout << "[2] - Loja" << std::endl;
    std::cout << "[3] - INN" << std::endl;
    std::cout << "[4] - Status" << std::endl;
    std::cout << "[5] - Inventario" << std::endl;
    std::cout << "[9] - Sair do jogo" << std::endl;
}

void Lobby::processarEscolha(int escolha) {
    switch (escolha) {
        case 1:
            fases.entrar(jogador);
            break;
        case 2:
            std::cout << "Caminhando até a Loja" << std::endl;
            delay(1);
            loja.entrar(jogador);
            break;
        case 3:
            std::cout << "Caminhando até o INN" << std::endl;
            delay(1);
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
        case 9:
            break;
        default:
            std::cout << "Entrada inesperada, não coloquei ainda esse caminho!" << std::endl;
            delay(2);
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
            std::cout << "nao tem um caminho em string" << std::endl;
            delay(2);
            continue;
        }

        processarEscolha(escolha);
    } while (escolha != 9);
}