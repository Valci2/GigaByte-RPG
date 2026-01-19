#include "Lobby.h"
#include "Utilitarios.h"
#include <iostream>

Lobby::Lobby(Personagem &jogador) : jogador(jogador) {}

enum acoes
{
    Fases = 1,
    Loja,
    Inn,
    Status,
    Inventario,
    Trocar,
    Sair = 9
};

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

void Lobby::mostrarMenu() const {
    titulo("Lobby");
    std::cout << "[1] - Fases" << std::endl;
    std::cout << "[2] - Loja" << std::endl;
    std::cout << "[3] - INN" << std::endl;
    std::cout << "[4] - Status" << std::endl;
    std::cout << "[5] - Inventario" << std::endl;
    std::cout << "[6] - Trocar item" << std::endl;
    std::cout << "[9] - Sair do jogo" << std::endl;
}

void Lobby::processarEscolha(int escolha) {
    switch (escolha) {
        case Fases:
            fases.entrar(jogador);
            break;
        case Loja:
            std::cout << "Caminhando até a Loja" << std::endl;
            delay(1);
            loja.entrar(jogador);
            break;
        case Inn:
            std::cout << "Caminhando até o INN" << std::endl;
            delay(1);
            inn.entrar(jogador);
            break;
        case Status:
            jogador.status();
            delay(2);
            break;
        case Inventario:
            jogador.mostrarinventario();
            delay(2);
            break;
        case Trocar:
            jogador.trocarItem();
            break;
        case Sair:
            std::exit(1);
        default:
            std::cout << "Entrada inesperada, não coloquei ainda esse caminho!" << std::endl;
            delay(2);
    }
}