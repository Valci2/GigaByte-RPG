#include "Fases.h"
#include "Utilitarios.h"
#include <iostream>

struct FaseInfo {
    std::string nome;
    std::vector<std::string> partes;
};

// ====== Nome Das partes de cada fase ======
const std::vector<FaseInfo> fases = {
    {
        "Memória",
        {  // Partes da primeira fase
            "Cripta da Memória",
            "Labirinto dos Dados Perdidos",
            "Santuário da RAM"
        }
    },
    {
        "Placa-mãe",
        { // Partes da segunda fase
            "Caminho dos Barramentos",
            "Circuito Sombrio",
            "Caverna da BIOS"
        }
    },
    {
        "CPU",
        { // Partes da terceira fase
            "Trono da Lógica Binária",
            "Torre da ULA",
            "Domínio dos Registradores"
        }
    }
};

// ========== Principal ==========
void Fases::entrar(Personagem& jogador) {
    while (true) {

        if (jogador.getHP() <= 0) {
            std::cout << "Voce nao tem vida para encarar as fases. Va se curar no inn.\n";
            return;
        }

        titulo("Fases");
        menuDasFases();

        int escolhaFase = validarEscolha(1, fases.size() + 1);

        if (escolhaFase == fases.size() + 1)
            return;

        int faseIndex = escolhaFase - 1;
        const FaseInfo& fase = fases[faseIndex];

        titulo("Fase: " + fase.nome);
        menuDasPartes(fase.partes);

        int escolhaParte = validarEscolha(1, fase.partes.size() + 1);

        if (escolhaParte == fase.partes.size() + 1)
            continue;

        linha();
        combate->comecar(jogador, faseIndex + 1, escolhaParte);
    }
}

// ========= menu das fases =========
void Fases::menuDasFases() {
    for (int i = 0; i < fases.size(); i++) { std::cout << "[" << i + 1 << "] - " << fases[i].nome << std::endl; }
    std::cout << "[" << fases.size() + 1 << "] - Voltar" << std::endl;
}

// ========= menu das partes =========
void Fases::menuDasPartes(const std::vector<std::string>& partes) {
    for (int i = 0; i < partes.size(); i++) { std::cout << "[" << i + 1 << "] - " << partes[i] << std::endl; }
    std::cout << "[" << partes.size() + 1 << "] - Voltar" << std::endl;
}