#include "Cenarios/Loja/Loja.h"
#include "utilitarios/utilitarios.h"
#include <iostream>
#include <vector>

// ============== struct para juntar os itens de compra ==============
struct itensDeCompra {
    std::string nome;
    int preco;
};

// ============== itens disponiveis para comprar ==============
// armas
const std::vector<itensDeCompra> armasDisponiveis = {
    {"Espada de cobre", 10},
    {"Espada de circuito", 30},
    {"Espada eletrica", 60},
    {"Espada bug", 150},
    {"Espada de agua", 300}
};

// armaduras
const std::vector<itensDeCompra> armadurasDisponiveis = {
    {"Armadura de bronze", 15},
    {"Armadura de circuito integrado", 40},
    {"Armadura de placa de video", 70},
    {"Armadura de de placa mae", 160},
    {"Armadura com IA", 310}
};

// ====================== Enum para menu ======================
enum TipoCompra {
    COMPRA_ARMA = 1,
    COMPRA_ARMADURA,
    POCAO_CURA,
    POCAO_CURA_FORTE,
    POCAO_MANA,
    POCAO_MANA_FORTE,
    SAIR = 7
};

// ================= Principal ===================
void Loja::entrar(Personagem &jogador) {
    titulo("Loja");
    std::cout << "Ola, meu fonte, quer comprar algo? sinta-se a vontade." << std::endl;
    int escolha = 0;
    do {
        linha();
        menuDeCompras();
        linha();
        escolha = validarEscolha(1, 7);
        switch (escolha) {
            case COMPRA_ARMA:
                menuDeItens(armasDisponiveis, jogador, "Armas Disponiveis", "arma");
                break;
            case COMPRA_ARMADURA:
                menuDeItens(armadurasDisponiveis, jogador, "Armaduras Disponiveis", "armadura");
                break;
            case POCAO_CURA:
            case POCAO_CURA_FORTE:
            case POCAO_MANA:
            case POCAO_MANA_FORTE: {
                std::cout << "Quantas poções deseja comprar (1 a 10)?\n";
                int quantidade = validarEscolha(1, 10);
                comprarPocao(escolha, jogador, quantidade);
                break;
            }

            case SAIR:
                std::cout << "Saindo da loja" << std::endl;
                delay(1);
                return;
        }
    } while (escolha != SAIR);
}

// ================= Menus ===================
void Loja::menuDeCompras() {
    std::cout << "[1] Comprar uma Nova Arma" << std::endl;
    std::cout << "[2] Comprar uma Nova Armadura" << std::endl;
    std::cout << "[3] Comprar Pocao de Cura (10)" << std::endl;
    std::cout << "[4] Comprar Pocao de Cura Forte (40)" << std::endl;
    std::cout << "[5] Comprar Pocao de Mana (50)" << std::endl;
    std::cout << "[6] Comprar Pocao de Mana Forte (100)" << std::endl;
    std::cout << "[7] Sair da Loja" << std::endl;
}

void Loja::menuDeItens(const std::vector<itensDeCompra> &itens, Personagem &jogador,
                       const std::string &tituloMenu, const std::string &tipo) {
    int escolha = 0;
    do {
        titulo(tituloMenu);
        for (int i = 0; i < itens.size(); i++) {
            std::cout << "[" << i + 1 << "] " << itens[i].nome << " (" << itens[i].preco << ")\n";
        }

        std::cout << "[" << itens.size() + 1 << "] Voltar\n";
        std::cout << "Você possui " << jogador.getInventario().getCapiba() << " Capibas\n";
        escolha = validarEscolha(1, itens.size() + 1);

        if (escolha > 0 && escolha <= itens.size()) {
            bool conseguiu = trocarItens(itens, jogador, escolha - 1, tipo);
            if (conseguiu) {
                std::cout << "Voce comprou " << itens[escolha - 1].nome << "!" << std::endl;
            } else {
                std::cout << "voce não possui cabibas suficientes. O preco e " << itens[escolha - 1].preco <<
                        " e voce possui " << jogador.getInventario().getCapiba() << std::endl;
            }
            delay(1);
        }
    } while (escolha != itens.size() + 1);
}

// ================== Troca a armadura e a Arma ==================
bool Loja::trocarItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, int escolha, const std::string& tipo) {
    const itensDeCompra &item = itens[escolha];
    int capibasDoJogador = jogador.getInventario().getCapiba();

    if (capibasDoJogador >= item.preco) {
        jogador.getInventario().setCapiba(capibasDoJogador - item.preco);
        if (tipo == "arma") {
            jogador.getInventario().setArma(item.nome);
        }
        else if (tipo == "armadura") {
            jogador.getInventario().setArmadura(item.nome);
        }
        return true;
    }

    return false;
}

// ====================== Compra de Poções ======================
void Loja::comprarPocao(int tipoPocao, Personagem &jogador, int quantidade) {
    int precoUnitario = 0;
    std::string nomePocao;

    switch (tipoPocao) {
        case POCAO_CURA: precoUnitario = 10; nomePocao = "Poção de Cura"; break;
        case POCAO_CURA_FORTE: precoUnitario = 40; nomePocao = "Poção de Cura Forte"; break;
        case POCAO_MANA: precoUnitario = 50; nomePocao = "Poção de Mana"; break;
        case POCAO_MANA_FORTE: precoUnitario = 100; nomePocao = "Poção de Mana Forte"; break;
    }

    int custoTotal = precoUnitario * quantidade;
    int capibasDoJogador = jogador.getInventario().getCapiba();

    if (capibasDoJogador < custoTotal) {
        std::cout << "Capibas insuficientes! Você possui " << capibasDoJogador
                  << " e precisa de " << custoTotal << ".\n";
        return;
    }

    jogador.getInventario().setCapiba(capibasDoJogador - custoTotal);

    switch (tipoPocao) {
        case POCAO_CURA: jogador.getInventario().setPocaoDeCura(quantidade); break;
        case POCAO_CURA_FORTE: jogador.getInventario().setPocaoDeCuraForte(quantidade); break;
        case POCAO_MANA: jogador.getInventario().setPocaoDeMana(quantidade); break;
        case POCAO_MANA_FORTE: jogador.getInventario().setPocaoDeManaForte(quantidade); break;
    }

    std::cout << "Você comprou " << quantidade << "x " << nomePocao << "!\n";
    delay(1);
}