#include "Lobby.h"
#include <iostream>
#include <thread> // Fornece acesso à biblioteca de multithreading da C++ Standard Library, usada para criar e gerenciar threads.
#include <chrono> // Traz ferramentas de tempo, como duração, relógios, contagem de tempo etc.
#include <limits> // Fornece limites numéricos para os tipos primitivos (como int, float, etc.).

void lobby(Personagem jogador) {
    while (true) {
        std::cout << "============= Lobby =============" << std::endl;
        std::cout << "[1] Fases" << std::endl;
        std::cout << "[2] Loja" << std::endl;
        std::cout << "[3] INN" << std::endl;
        std::cout << "[4] Status" << std::endl;
        std::cout << "[5] Inventario" << std::endl;

        int escolha = 0;
        std::cout << "O que você quer fazer: ";
        std::cin >> escolha;
        switch (escolha) {
            case 4:
                jogador.status();
                break;
            default:
                std::cout << "Ta dando uma de chapezinho? respeita os caminhos!" << std::endl;
        }
        if (std::cin.fail()) {
            std::cout << "Não tenho esse caminho na memoria. Como eu vou ir?" << std::endl;
            std::cin.clear(); // limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // descarta a entrada inválida
        }
    }
}
