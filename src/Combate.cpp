#include "Combate.h"
#include "Utilitarios.h"
#include "Tipos.h"
#include <iostream>
#include <vector>


Combate::Combate() {}
Combate::~Combate() {}

// listas de monstros generica da primeira fase
std::vector<Monstro> monstrosFaseUm = {
    Monstro("Cache Fantasma", 5, 3, 1, 2, 0 ),
    Monstro("Bit Perdido", 6, 9, 2, 3, 1),
    Monstro("Pixel Morto", 10, 10, 4, 7,  3),
    Monstro("Pacote Malicioso", 14, 8, 6, 7, 4),
    Monstro("Memória Corrompida", 25, 20, 11, 4, 8)
};


// listas de monstros generica da segunda fase
std::vector<Monstro> monstrosFaseDois = {
    Monstro("Chipset Sombrio", 15, 10, 9, 9, 13),
    Monstro("Barramento Caótico", 14, 11, 10, 10, 12),
    Monstro("Slot Vazio", 12, 9, 11, 8, 11),
    Monstro("BIOS Antiga", 16, 8, 12, 9, 14),
    Monstro("Conector Enferrujado", 35, 10, 15, 10, 12)
};


// listas de monstros generica da terceira fase
std::vector<Monstro> monstrosFaseTres = {
    Monstro("Thread Caótica", 18, 12, 14, 11, 15),
    Monstro("Segmentation Fault", 19, 12, 15, 10, 17),
    Monstro("Overclock Insano", 21, 13, 14, 12, 18),
    Monstro("Pipeline Quebrado", 18, 11, 13, 11, 16),
    Monstro("Deadlock", 20, 11, 13, 12, 16)
};


// menu de escolhas para o combate
void menu() {
    std::cout << "+--------------+" << std::endl;
    std::cout << "| [1] Atacar   |" << std::endl;
    std::cout << "| [2] Defender |" << std::endl;
    std::cout << "| [3] Magia    |" << std::endl;
    std::cout << "| [4] Item     |" << std::endl;
    std::cout << "| [5] Fugir    |" << std::endl;
    std::cout << "+--------------+" << std::endl;
}

void menuItens(Personagem &jogador) {
    std::cout << "=== Qual item você quer usar? ===" << std::endl;
    std::cout << "[1] Pocao de Cura (" << jogador.getInventario().getPocaoDeCura() << "/10)" << "\n";
    std::cout << "[2] Pocao de Cura Forte (" << jogador.getInventario().getPocaoDeCuraForte() << "/10)" << "\n";
    std::cout << "[3] Pocao de Mana (" << jogador.getInventario().getPocaoDeMana() << "/10)" << "\n";
    std::cout << "[4] Pocao de Mana Forte (" << jogador.getInventario().getPocaoDeManaForte() << "/10)" << "\n";
    std::cout << "[5] Voltar""\n";
}

enum Acao {
    Atacar = 1,
    Defender,
    Magia,
    Item,
    Fugir
};

void Combate::gerenciamentoDeMonstro(Personagem& jogador, std::vector<Monstro>& monstros, int parte) {

    int indice;

    if (parte == 1) {
        indice = randint(0, monstros.size() - 4);
    }
    else if (parte == 2) {
        indice = randint(0, monstros.size() - 2);
    }
    else {
        indice = monstros.size() - 1;
    }

    Monstro& atacante = monstros[indice];

    std::cout << "parece que você foi avistado pelo " << atacante.getNome() << std::endl;
    iniciarCombate(jogador, atacante);
}

void Combate::comecar(Personagem &jogador, int fase, int parte) {
    if (fase == 1) {
        gerenciamentoDeMonstro(jogador, monstrosFaseUm, parte);
    }
    else if (fase == 2) {
        gerenciamentoDeMonstro(jogador, monstrosFaseDois, parte);
    }
    else if (fase == 3) {
        gerenciamentoDeMonstro(jogador, monstrosFaseTres, parte);
    }
}

void Combate::iniciarCombate(Personagem& jogador, Monstro& monstro) {

    int escolha = 0;
    int escolhaDoMonstro = 0;
    int turnos = 1;
    bool fugiu = false;

    while (jogador.getHP() > 0 && monstro.getHP() > 0 && !fugiu) {
        std::cout << turnos << "⁰ turno" << std::endl;
        jogador.statusDeCombate();
        monstro.statusDeCombate();

        bool turnoValido = false;
        while (!turnoValido) {
            menu();
            escolha = validarEscolha(1, 5);

            switch (escolha) {
                case Atacar: jogador.atacar(monstro); turnoValido = true; break;
                case Defender: jogador.defender(); turnoValido = true; break;
                case Magia: jogador.magia(); turnoValido = true; break;
                case Item: {
                    menuItens(jogador);

                    int escolhaItem = validarEscolha(1, 5);

                    if (escolhaItem == 5) break;
                    bool sucesso = jogador.usarItem(static_cast<TipoItem>(escolhaItem - 1));

                    if (!sucesso) {
                        std::cout << "voce nao conseguiu usar a pocao" << std::endl;
                    } else {
                        turnoValido = true;
                    }
                    break;
                }
                case Fugir: fugiu = jogador.fugir(); turnoValido = true; break;
            }
        }

        if (jogador.getHP() > 0 && monstro.getHP() > 0 && !fugiu) {

            monstro.finalizarTurno();

            escolhaDoMonstro = randint(1, 100);
            if (escolhaDoMonstro <= 75) {
                monstro.atacar(jogador);
            }
            else {
                monstro.defender();
            }

            jogador.finalizarTurno();
            turnos++;
        }
    }
}