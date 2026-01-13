#include "Loja.h"
#include "Utilitarios.h"
#include <iostream>
#include <vector>

// ============== struct para juntar os itens de compra ==============
struct itensDeCompra {
    std::string nome;
    int preco;
};

// ============== itens disponiveis para comprar ==============
// Armas
const std::vector<itensDeCompra> armasDisponiveis = {
    {"Espada de cobre", 10},
    {"Espada de circuito", 30},
    {"Espada eletrica", 60},
    {"Espada bug", 150},
    {"Espada de agua", 300}
};

// Armaduras
const std::vector<itensDeCompra> armadurasDisponiveis = {
    {"Armadura de bronze", 15},
    {"Armadura de circuito integrado", 40},
    {"Armadura de placa de video", 70},
    {"Armadura de de placa mae", 160},
    {"Armadura com IA", 310}
};

// Pocoes
const std::vector<itensDeCompra> pocoesDisponiveis = {
    {"Pocao de Cura", 10},
    {"Pocao de Cura Forte", 40},
    {"Pocao de Mana", 50},
    {"Pocao de Mana Forte", 100}
};


// ====================== Enum para menu ======================
enum TipoCompra {
    COMPRA_ARMA = 1,
    COMPRA_ARMADURA,
    COMPRA_POCOES,
    SAIR
};

enum pocao {
    POCAO_CURA = 0,
    POCAO_CURA_FORTE,
    POCAO_MANA,
    POCAO_MANA_FORTE,
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
        escolha = validarEscolha(1, 4);
        switch (escolha) {
            case COMPRA_ARMA:
                menuDeItens(armasDisponiveis, jogador, "Armas Disponiveis", "arma");
                break;
            case COMPRA_ARMADURA:
                menuDeItens(armadurasDisponiveis, jogador, "Armaduras Disponiveis", "armadura");
                break;
            case COMPRA_POCOES:
                menuDeItens(pocoesDisponiveis, jogador, "Pocoes Disponiveis", "pocao");
                break;
        }
    } while (escolha != SAIR);

    std::cout << "Saindo da loja" << std::endl;
    delay(1);
}

// ================= Menus ===================
void Loja::menuDeCompras() {
    std::cout << "[1] - Comprar uma Nova Arma" << std::endl;
    std::cout << "[2] - Comprar uma Nova Armadura" << std::endl;
    std::cout << "[3] - Comprar Pocoes" << std::endl;
    std::cout << "[4] - Voltar" << std::endl;
}

void Loja::menuDeItens(const std::vector<itensDeCompra> &itens, Personagem &jogador,
                       const std::string &tituloMenu, const std::string &tipo) {
    int escolha = 0;
    do {
        // menu dos itens
        titulo(tituloMenu);
        for (size_t i = 0; i < itens.size(); i++) {
            const auto &item = itens[i];
            std::cout << "[" << i + 1 << "] " << item.nome << " - Preco " << item.preco << " Capibas" << std::endl;
        }
        std::cout << "[" << itens.size() + 1 << "] Voltar" << std::endl;
        std::cout << "Você possui " << jogador.getInventario().getCapiba() << " Capibas" << std::endl;

        // escolha do jogador para poções
        escolha = validarEscolha(1, itens.size() + 1);

        if (escolha > 0 && escolha <= itens.size()) {
            if (tipo == "pocao") {
                std::cout << "Escolha a quantidade entre (1 a 10)." << std::endl;
                int quantidadeDePocoes = validarEscolha(1, 10);
                comprarPocao(itens, escolha - 1, jogador, quantidadeDePocoes);
            } else {
                bool conseguiu = trocarItens(itens, jogador, escolha - 1, tipo);

                if (conseguiu) {
                    std::cout << "Voce comprou " << itens[escolha - 1].nome << "!" << std::endl;
                } else {
                    std::cout << "voce não possui cabibas suficientes. O preco e " << itens[escolha - 1].preco <<
                            " e voce possui " << jogador.getInventario().getCapiba() << std::endl;
                }
                delay(1);
            }
        }
    } while (escolha != itens.size() + 1);
}

// ================== Troca a armadura e a Arma ==================
bool Loja::trocarItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, int escolha,
                       const std::string &tipo) {
    const itensDeCompra &item = itens[escolha];
    int capibasDoJogador = jogador.getInventario().getCapiba();

    if (capibasDoJogador >= item.preco) {
        jogador.getInventario().setCapiba(capibasDoJogador - item.preco);
        if (tipo == "arma") {
            jogador.getInventario().setArma(item.nome);
        } else if (tipo == "armadura") {
            jogador.getInventario().setArmadura(item.nome);
        }
        return true;
    }
    return false;
}

// ====================== Compra de Poções ======================
void Loja::comprarPocao(const std::vector<itensDeCompra> &pocoes, int escolha, Personagem &jogador, int quantidade) {

    const int LIMITE_DE_POCOES = 10;
    const auto &item = pocoes[escolha];
    std::string nomePocao = item.nome;
    int precoUnitario = item.preco;
    int quantidadePocao = 0;

    switch (escolha) {
        case POCAO_CURA:
            quantidadePocao = jogador.getInventario().getPocaoDeCura();
            break;
        case POCAO_CURA_FORTE:
            quantidadePocao = jogador.getInventario().getPocaoDeCuraForte();
            break;
        case POCAO_MANA:
            quantidadePocao = jogador.getInventario().getPocaoDeMana();
            break;
        case POCAO_MANA_FORTE:
            quantidadePocao = jogador.getInventario().getPocaoDeManaForte();
            break;
    }

    int espacoDisponivel = LIMITE_DE_POCOES - quantidadePocao;
    if (espacoDisponivel <= 0) {
        std::cout << "Você já atingiu o limite de poções!" << std::endl;
        return;
    }

    if (quantidade > espacoDisponivel) {
        std::cout << "Limite atingido! Só pode comprar " << espacoDisponivel << "." << std::endl;
        quantidade = espacoDisponivel;
    }

    int capibasDoJogador = jogador.getInventario().getCapiba();
    int custoTotal = precoUnitario * quantidade;
    if (capibasDoJogador < custoTotal) {
        std::cout << "Capibas insuficientes!" << " Faltam " << custoTotal - capibasDoJogador << " Capibas." <<
                std::endl;
        return;
    }

    jogador.getInventario().setCapiba(capibasDoJogador - custoTotal);
    jogador.getInventario().adicionarPocao(nomePocao, quantidade);

    std::cout << "Você comprou " << quantidade << "x " << nomePocao << " por " << custoTotal << " Capibas!";
    std::cout << "Saldo atual: " << jogador.getInventario().getCapiba() << " Capibas." << std::endl;
    delay(1);
}
