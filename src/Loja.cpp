#include "Loja.h"
#include "Utilitarios.h"
#include <iostream>
#include <vector>

// ========= Estrutura para os itens da loja ============== 
struct itensDeCompra {
    std::string nome;
    int preco;
    int poder;
};

// ============== itens disponiveis para comprar ==============
// Armas
const std::vector<itensDeCompra> armasDisponiveis = {
    {"Espada de cobre", 10, 1},
    {"Espada de circuito", 30, 2},
    {"Espada eletrica", 60, 3},
    {"Espada bug", 150, 4},
    {"Espada de agua", 300, 5}
};

// Armaduras
const std::vector<itensDeCompra> armadurasDisponiveis = {
    {"Armadura de bronze", 15, 1},
    {"Armadura de circuito integrado", 40, 2},
    {"Armadura de placa de video", 70, 3},
    {"Armadura de de placa mae", 160, 4},
    {"Armadura com IA", 310, 5}
};

// Pocoes
const std::vector<itensDeCompra> pocoesDisponiveis = {
    {"Pocao de Cura", 10},
    {"Pocao de Cura Forte", 40},
    {"Pocao de Mana", 30},
    {"Pocao de Mana Forte", 80}
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

bool querEquipar(){
    std::cout << "Voce quer equipar esse equipamento? [S/N]" << std::endl;
    std::cout << "[1] Sim" << std::endl;
    std::cout << "[2] Nao" << std::endl;
    validarEscolha(1, 2);
    if (1) {
        return true;
    }
    return false;
}

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
                menuDeItens(armasDisponiveis, jogador, "Armas Disponiveis", TipoItem::Arma);
                break;
            case COMPRA_ARMADURA:
                menuDeItens(armadurasDisponiveis, jogador, "Armaduras Disponiveis", TipoItem::Armadura);
                break;
            case COMPRA_POCOES:
                menuDeItens(pocoesDisponiveis, jogador, "Pocoes Disponiveis", TipoItem::Pocao);
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

void Loja::menuDeItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, const std::string &tituloMenu, TipoItem tipo) {
    int escolha = 0;
    
    do {
        // menu dos itens
        titulo(tituloMenu);
        
        for (size_t i = 0; i < itens.size(); i++) {
            const auto &item = itens[i];
            std::cout << "[" << i + 1 << "] " << item.nome << " - Preco " << item.preco << " Capibas" << std::endl;
        }
        
        // menu de volta
        std::cout << "[" << itens.size() + 1 << "] Voltar" << std::endl;
        std::cout << "Você possui " << jogador.getInventario().getCapiba() << " Capibas" << std::endl;

        // escolha do jogador para poções
        escolha = validarEscolha(1, itens.size() + 1);

        if (escolha > 0 && escolha <= itens.size()) {
            
            if (tipo == TipoItem::Pocao) 
            {
                std::cout << "Escolha a quantidade entre (1 a 10)." << std::endl;
                int quantidadeDePocoes = validarEscolha(1, 10);
                comprarPocao(itens, escolha - 1, jogador, quantidadeDePocoes);
            } 
            else 
            {
                bool conseguiu = trocarItens(itens, jogador, escolha - 1, tipo);

                if (conseguiu) {
                    std::cout << "Voce comprou " << itens[escolha - 1].nome << "!" << std::endl;
                } else {
                    std::cout << "voce não possui cabibas suficientes. O preco e " << itens[escolha - 1].preco << " e voce possui " << jogador.getInventario().getCapiba() << std::endl;
                }
                delay(1);
            }
        }
    } while (escolha != itens.size() + 1);
}

// ================== Troca a armadura e a Arma ==================
bool Loja::trocarItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, int escolha, TipoItem tipo) {
    
    // variaveis locais
    const itensDeCompra &item = itens[escolha];

    bool conseguiu = jogador.temCapibas(item.preco);

    const Item &itemComprado = {itens[escolha].nome, itens[escolha].poder};
    bool quer = false;

    // verifica se o jogador tem dinheiro suficiente para trocar pelo item desejado
    if (conseguiu) {
        if (tipo == TipoItem::Arma) {
            std::vector<Item> armas = jogador.getInventario().getArmas();
            bool tem = false;
            for (size_t i = 0; i < armas.size(); i++) {
                if (itemComprado.nome == armas[i].nome) tem = true;
            }
            if (!tem)
            {
            jogador.comprar(item.preco);
            jogador.getInventario().setArmas(itemComprado);
            if (querEquipar()) jogador.equiparArma(itemComprado.nome, itemComprado.poder);
            }
            else { 
                return false; 
            }
        } else if (tipo == TipoItem::Armadura) {    
            std::vector<Item> armas = jogador.getInventario().getArmas();
            bool tem = false;
            for (size_t i = 0; i < armas.size(); i++) {
                if (itemComprado.nome == armas[i].nome) tem = true;
            }
            if (!tem)
            {        
            jogador.comprar(item.preco);
            jogador.getInventario().setArmaduras(itemComprado);
            if (querEquipar()) jogador.equiparArmadura(itemComprado.nome, itemComprado.poder);
            }
            else { 
                return false; 
            }
            return false;
        }
        return true;
    }

    return false;
}

// ====================== Compra de Poções ======================
void Loja::comprarPocao(const std::vector<itensDeCompra> &pocoes, int escolha, Personagem &jogador, int quantidade) {

    // variaveis locais
    const int LIMITE_DE_POCOES = 10;
    const auto &item = pocoes[escolha];
    std::string nomePocao = item.nome;
    int precoUnitario = item.preco;
    int quantidadePocao = 0;

    // pega a quantidade de poções que o jogador tem
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

    // verifica se o jogador não ultrapassou o limite de poções
    int espacoDisponivel = LIMITE_DE_POCOES - quantidadePocao;
    if (espacoDisponivel <= 0) {
        std::cout << "Você já atingiu o limite de poções!" << std::endl;
        return;
    }

    // verifica se o jogador tem espaço disponivel para adicionar mais poções
    if (quantidade > espacoDisponivel) {
        std::cout << "Limite atingido! Só pode comprar " << espacoDisponivel << "." << std::endl;
        quantidade = espacoDisponivel;
    }

    // verifica se o jogador tem capibas suficientes para a compra
    int capibasDoJogador = jogador.getInventario().getCapiba();
    int custoTotal = precoUnitario * quantidade;

    if (capibasDoJogador < custoTotal) {
        std::cout << "Capibas insuficientes!" << " Faltam " << custoTotal - capibasDoJogador << " Capibas." << std::endl;
        return;
    }

    // faz a compra e retira o dinheiro do jogador
    jogador.getInventario().setCapiba(capibasDoJogador - custoTotal);
    jogador.getInventario().adicionarPocao(nomePocao, quantidade);

    // print para imformar o jogador
    std::cout << "Você comprou " << quantidade << "x " << nomePocao << " por " << custoTotal << " Capibas!";
    std::cout << "Saldo atual: " << jogador.getInventario().getCapiba() << " Capibas." << std::endl;
    delay(1);
}
