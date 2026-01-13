#include "Combate.h"
#include "Utilitarios.h"
#include "Tipos.h"
#include <iostream>
#include <vector>

Combate::Combate() {}
Combate::~Combate() {}

// listas de monstros generica da primeira fase
std::vector<Monstro> monstrosFaseUm = {
    Monstro("Cache Fantasma", 5, 3, 1, 2, 1, randint(1, 3), randint(1, 3)),
    Monstro("Bit Perdido", 6, 9, 2, 3, 1, randint(1, 4), randint(1, 4)),
    Monstro("Pixel Morto", 10, 10, 4, 7,  3, randint(2, 5), randint(2, 5)),
    Monstro("Pacote Malicioso", 14, 8, 6, 7, 4, randint(2, 6), randint(2, 6)),
    Monstro("Memória Corrompida", 25, 20, 11, 4, 8, randint(10,20), randint(10, 20))
};

// listas de monstros generica da segunda fase
std::vector<Monstro> monstrosFaseDois = {
    Monstro("Chipset Sombrio", 20, 15, 10, 9, 10, randint(20, 30), randint(20, 30)),
    Monstro("Barramento Caótico", 23, 16, 10, 10, 9, randint(30, 50), randint(30, 50)),
    Monstro("Slot Vazio", 25, 20, 10, 10, 14, randint(40, 50), randint(40, 50)),
    Monstro("BIOS Antiga", 25, 23, 12, 12, 11, randint(40, 70), randint(40, 70)),
    Monstro("Conector Enferrujado", 35, 30, 14, 15, 16, randint(100, 150), randint(100, 150))
};

// listas de monstros generica da terceira fase
std::vector<Monstro> monstrosFaseTres = {
    Monstro("Thread Caótica", 30, 12, 13, 18, 15, randint(80, 160), randint(80, 160)),
    Monstro("Segmentation Fault", 32, 12, 14, 18, 16, randint(100, 160), randint(100, 160)),
    Monstro("Overclock Insano", 36, 13, 15, 20, 17, randint(150, 250), randint(150, 250)),
    Monstro("Pipeline Quebrado", 40, 11, 16, 25, 16, randint(200, 350), randint(200, 350)),
    Monstro("Deadlock", 60, 50, 20, 40, 20, randint(400, 600), randint(400, 600))
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

std::vector<std::string> magias = {
    "Tela-preta",
    "Golpe de agua",
};

void menuDeMagias()
{

}

enum Acao {
    Atacar = 1,
    Defender,
    Magia,
    Item,
    Fugir
};

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

void Combate::iniciarCombate(Personagem& jogador, Monstro monstro) {

    // Variaveis do combate
    int escolha = 0;
    int escolhaDoMonstro = 0;
    int turnos = 1;
    int dano = 0;
    bool fugiu = false;

    // Combate
    while (jogador.getHP() > 0 && monstro.getHP() > 0 && !fugiu) {

        std::cout << "========= " << turnos << "⁰ turno" << " ========="<< std::endl;
        jogador.statusDeCombate();
        monstro.statusDeCombate();

        bool turnoValido = false;
        while (!turnoValido) {
            menu();
            escolha = validarEscolha(1, 5);

            switch (escolha) {
                case Atacar:
                    {
                        dano = jogador.atacar(monstro);
                        std::cout << jogador.getNome() << " deu " << dano << " de dano ao " << monstro.getNome() << std::endl;
                        turnoValido = true;
                        break;
                    }
                case Defender:
                    {
                        jogador.defender();
                        std::cout << jogador.getNome() << " se defende" << std::endl;
                        turnoValido = true;
                        break;
                    }
                case Magia:
                    {
                        jogador.magia();
                        turnoValido = true;
                        break;
                    }
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
            if (escolhaDoMonstro <= 80) {
                dano = monstro.atacar(jogador);
                std::cout << monstro.getNome() << " deu " << dano << " de dano ao " << jogador.getNome() << std::endl;

            }
            else {
                monstro.defender();
                std::cout << monstro.getNome() << " se defende" << std::endl;
            }

            jogador.finalizarTurno();
            turnos++;
        }
    }

    bool upou = false;
    // Fim do combate
    if (jogador.getHP() > 0 && !fugiu)
    {
        linha();
        std::cout << "Parabens voce ganhou a batalha" << std::endl;

        std::cout << jogador.getNome() << " ganhou: " << monstro.getXP() << " XP" << std::endl;
        std::cout << jogador.getNome() << " ganhou: " << monstro.getCapibas() << " Capibas" << std::endl;
        jogador.getInventario().setCapiba(monstro.getCapibas());
        upou = jogador.ganharXP(monstro.getXP());

        if (upou) {
            std::cout << "voce subiu de nivel" << std::endl;
            jogador.status();
        }
    }
    else { std::cout << jogador.getNome() << " tankou mais dano do que podia e acabou morrendo" << std::endl; }
}