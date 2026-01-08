#include "Fases.h"
#include "Utilitarios.h"
#include <iostream>

// ====== Nome Das partes de cada fase ======
// Partes da primeira fase
std::vector<std::string> faseUm = {
    {"Cripta da Memória"},
    {"Labirinto dos Dados Perdidos"},
    {"Santuário da RAM"}
};

// Partes da segunda fase
std::vector<std::string> faseDois = {
    {"Caminho dos Barramentos"},
    {"Circuito Sombrio"},
    {"Caverna da BIOS"}
};

// Partes da terceira fase
std::vector<std::string> faseTres = {
    {"Trono da Lógica Binária"},
    {"Torre da ULA"},
    {"Domínio dos Registradores"}
};

// ========== Principal ==========
void Fases::entrar(Personagem &jogador) {
    int escolha = 0;

    do {
        titulo("Fases");
        menuDeFases();

        escolha = validarEscolha(1, 4);
        int parte = 0;
        switch (escolha) {
            case 1:
                titulo("Fase 1");
                menuDasPartes(faseUm);
                parte = validarEscolha(1, faseUm.size() + 1);
                combate->gerenciamentoDeCombate(jogador, escolha, parte);
                break;
            case 2:
                titulo("Fase 2");
                menuDasPartes(faseDois);
                parte = validarEscolha(1, faseDois.size() + 1);
                break;
            case 3:
                titulo("Fase 3");
                menuDasPartes(faseTres);
                parte = validarEscolha(1, faseTres.size() + 1);
                break;
        }
    } while (escolha != 4);
}

// ========= menu das fases =========
void Fases::menuDeFases() {
    std::cout << "[1] - Memoria" << std::endl;
    std::cout << "[2] - Placa mae" << std::endl;
    std::cout << "[3] - CPU" << std::endl;
    std::cout << "[4] - Voltar" << std::endl;
}

// ========= menu das partes =========
void Fases::menuDasPartes(const std::vector<std::string> &fases) {
    for (int i = 0; i < fases.size(); i++) {
        std::cout << "[" << i + 1 << "] - " << fases[i] << std::endl;
    }
    std::cout << "[" << fases.size() + 1 << "]" << " - voltar" << std::endl;
}