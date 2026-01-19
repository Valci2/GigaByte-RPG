#include "Combate.h"
#include "Utilitarios.h"
#include "Tipos.h"
#include "FabricaDeMonstros.h"

#include <iostream>
#include <iomanip> // para setw

Combate::Combate() {}
Combate::~Combate() {}

// ====================== menus ======================
// menu de escolhas para o combate
void menu() {
    std::cout << "+-- Seu Turno --+" << std::endl;
    std::cout << "| [1] Atacar    |" << std::endl;
    std::cout << "| [2] Defender  |" << std::endl;
    std::cout << "| [3] Magia     |" << std::endl;
    std::cout << "| [4] Item      |" << std::endl;
    std::cout << "| [5] Fugir     |" << std::endl;
    std::cout << "+---------------+" << std::endl;
}

void menuItens(Personagem &jogador) {
    std::cout << "=== Qual item você quer usar? ===" << std::endl;
    std::cout << "[1] Pocao de Cura (" << jogador.getInventario().getPocaoDeCura() << "/10)" << "\n";
    std::cout << "[2] Pocao de Cura Forte (" << jogador.getInventario().getPocaoDeCuraForte() << "/10)" << "\n";
    std::cout << "[3] Pocao de Mana (" << jogador.getInventario().getPocaoDeMana() << "/10)" << "\n";
    std::cout << "[4] Pocao de Mana Forte (" << jogador.getInventario().getPocaoDeManaForte() << "/10)" << "\n";
    std::cout << "[5] Voltar""\n";
}


void statusDeCombate(Personagem &jogador, Monstro &monstro)
{
    const int col = 26;

    std::cout << "+--------------------------+--------------------------+\n";

    std::cout << "| " << std::left << std::setw(col - 1) << jogador.getNome()
              << "| " << std::left << std::setw(col - 1) << monstro.getNome() << "|\n";

    std::cout << "+--------------------------+--------------------------+\n";

    std::cout << "| HP   "
              << std::right << std::setw(3) << jogador.getHP()
              << "/" << std::setw(3) << jogador.getMaxHP()
              << std::left << std::setw(col - 13) << " "
              << "| HP   "
              << std::right << std::setw(3) << monstro.getHP()
              << "/" << std::setw(3) << monstro.getMaxHP()
              << std::left << std::setw(col - 13) << " "
              << "|\n";

    std::cout << "| Mana "
              << std::right << std::setw(3) << jogador.getMana()
              << "/" << std::setw(3) << jogador.getMaxMana()
              << std::left << std::setw(col - 13) << " "
              << "| Mana "
              << std::right << std::setw(3) << monstro.getMana()
              << "/" << std::setw(3) << monstro.getMaxMana()
              << std::left << std::setw(col - 13) << " "
              << "|\n";

    std::cout << "+--------------------------+--------------------------+\n";
}

// ===================== começa o combate =====================
// faz a escolha do monstro dependendo da fase e da parte
void Combate::comecar(Personagem &jogador, int fase, int parte) {
    Monstro atacante = fabricaDeMonstros.fabricar(fase, parte);
    std::cout << "parece que você foi avistado pelo " << atacante.getNome() << std::endl;
    iniciarCombate(jogador, atacante);
}

// ===================== turnos =====================
bool Combate::turnoDoJogador(Personagem &jogador, Monstro &monstro)
{
    int dano = 0;
    int escolha = 0;
    bool fugiu = false;

    while (true) {
        menu();
        escolha = validarEscolha(1, 5);

        switch (escolha) {
            case Atacar:
                {
                    dano = jogador.atacar(monstro);
                    std::cout << jogador.getNome() << " atacou e causou " << dano << " de dano ao " << monstro.getNome() << std::endl;
                    return false;
                }
            case Defender:
                {
                    jogador.defender();
                    std::cout << jogador.getNome() << " se defende" << std::endl;
                    return false;
                }
            case Magia:
                {
                    jogador.magia();
                    bool sucesso = false;
                    if (!sucesso)
                    {
                        std::cout << "Voce nao conseguiu usar a magia" << std::endl;
                    }
                    else
                    {
                        return false;
                    }
                    break;
                }
            case Item: {
                    menuItens(jogador);

                    int escolhaItem = validarEscolha(1, 5);

                    if (escolhaItem == 5) break;
                    bool sucesso = jogador.usarItem(static_cast<TipoPocao>(escolhaItem - 1));

                    if (!sucesso) {
                        std::cout << "voce nao conseguiu usar a pocao" << std::endl;
                    } else {
                        return false;
                    }
                    break;
            }
            case Fugir:
                fugiu = jogador.fugir();
                return fugiu;
        }
    }
}

void Combate::turnoDoMonstro(Personagem &jogador, Monstro &monstro)
{
    if (randint(1, 100) <= 80) {
        std::cout << monstro.getNome() << " atacou e causou " << monstro.atacar(jogador) << " de dano\n";
    } else {
        monstro.defender();
        std::cout << monstro.getNome() << " se defende\n";
    }
}
// ============================================================

// ==================== Logica do Combate =====================
void Combate::iniciarCombate(Personagem &jogador, Monstro monstro)
{
    // Variaveis do combate
    int turnos = 1;
    bool fugiu = false;

    // Combate
    do  {
        std::cout << "============= " << turnos << "⁰ turno" << " ============="<< std::endl;

        statusDeCombate(jogador, monstro);

        fugiu = turnoDoJogador(jogador, monstro);
        monstro.finalizarTurno();

        if (jogador.getHP() > 0 && monstro.getHP() > 0 && !fugiu) {
            turnoDoMonstro(jogador, monstro);
            jogador.finalizarTurno();
        }

        turnos++;
    } while (jogador.estaVivo() && monstro.estaVivo() && !fugiu);

    // Fim do combate
    if (jogador.estaVivo() && !fugiu)
    {
        fimDeCombate(jogador, monstro);
    }
    else
    {
        std::cout << jogador.getNome() << " tankou mais dano do que podia e acabou morrendo" << std::endl;
    }
}

// =================== Final do combate ===================
void Combate::fimDeCombate(Personagem& jogador, Monstro& monstro)
{
    bool upou = false;
    std::cout << "========= " << "Parabens voce derrotou o " << monstro.getNome() << " =========" << std::endl;

    jogador.getInventario().setCapiba(jogador.getInventario().getCapiba() + monstro.getCapibas());
    upou = jogador.ganharXP(monstro.getXP());

    if (!upou){
        std::cout << jogador.getNome() << " Ganhou: " << monstro.getXP() << " XP, para evoluir falta " << jogador.getFalta() << " XP" << std::endl;
        std::cout << jogador.getNome() << " ganhou: " << monstro.getCapibas() << " Capibas" << std::endl;
    }
    else {
        std::cout << jogador.getNome() << " Ganhou: " << monstro.getXP() << " XP" << std::endl;
        std::cout << jogador.getNome() << " ganhou: " << monstro.getCapibas() << " Capibas" << std::endl;
        std::cout << "Voce subiu de nivel" << std::endl;
        jogador.status();
    }

}