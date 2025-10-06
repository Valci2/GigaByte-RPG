#include "Lobby.h"
#include "../Cenarios/INN.h"
#include "../funcoesUteis/funcoesUteis.h"
#include <iostream>

void lobby(Personagem &jogador) {
    while (true) {
        std::cout << "============= Lobby =============" << std::endl;
        std::cout << "[1] Fases" << std::endl;
        std::cout << "[2] Loja" << std::endl;
        std::cout << "[3] INN" << std::endl;
        std::cout << "[4] Status" << std::endl;
        std::cout << "[5] Inventario" << std::endl;

        int escolha = 0;
        std::cout << "O que voce quer fazer: ";
        std::cin >> escolha;
        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "ta tendo me testar ou eh para fritar minha paciencia?" << std::endl;
            std::cout << "tambem vai aguardar 10 segundo agora" << std::endl;
            delay(10);
        } else {
            switch (escolha) {
                case 3:
                    std::cout << "indo ate o local" << std::endl;
                    delay(2);
                    dentroDoINN(jogador); // leva o jogador para dentro do INN
                    break;
                case 4:
                    jogador.status(); // mostra os status do jogador
                    delay(3);
                    break;
                case 5:
                    jogador.inventario(); // mostra o inventario do jogador
                    delay(3);
                    break;
                default: // caso não seja nenhum das opções acima
                    std::cout << "Ta dando uma de chapezinho? respeita os caminhos!" << std::endl;
            }
        }
    }
}