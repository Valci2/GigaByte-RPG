#include "Loja.h"
#include "../../funcoesUteis/funcoesUteis.h"
#include "../Loja/trocaDosItens.h"
#include <iostream>

void dentroDaLoja(Personagem &jogador) {
    while (true) {
        std::cout << "============= Loja =============" << std::endl;
        std::cout << "[1] Comprar nova arma" << std::endl;
        std::cout << "[2] Comprar nova armadura" << std::endl;
        std::cout << "[3] Comprar Pocoes de Cura" << std::endl;
        std::cout << "[4] Comprar Pocoes de Cura Forte" << std::endl;
        std::cout << "[5] Comprar Pocoes de Mana" << std::endl;
        std::cout << "[6] Comprar Pocoes de Mana Forte" << std::endl;
        std::cout << "[7] Sair" << std::endl;
        int escolha;
        std::cin >> escolha;
        if (std::cin.fail()) {
            std::cout << "Nao conheco esse itens que voce digitou ve se outro jogo tem" << std::endl;
            limparEntrada();
        }
        switch (escolha) {
            case 1:
                trocaDaArma(jogador);
            case 7:
                return;
        }
    }
}