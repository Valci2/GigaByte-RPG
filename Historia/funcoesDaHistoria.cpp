#include "funcoesDaHistoria.h"
#include "../funcoesUteis/funcoesUteis.h"
#include <iostream>

void respostaInvalida(int tentativas) {
    if (tentativas < 3) {
        std::cout << "Essa resposta nem existe dentro das condicionais." << std::endl;
    } else if (tentativas == 30) {
        std::cout << "EH serio que voce ainda ta fazendo isso?" << std::endl;
    } else if (tentativas == 60) {
        std::cout << "Voce esta perdendo a sua vida pra acumular tentativas?" << std::endl;
    } else if (tentativas == 100) {
        std::cout << "SERIO, ESSE EH MEU ULTIMO AVISO SE VOCE NAO PARAR EU PARO." << std::endl;
    } else if (tentativas >= 101) {
        std::cout << "ENTAO TA BOM ;-;" << std::endl;
        exit(0);
    } else {
        std::cout << "ja falei que nao faz parte, tentativa numero: " << tentativas << std::endl;
    }
}

void responderOpcao(int resposta) {
    switch (resposta) {
        case 1:
            std::cout << "Entao... e uma pena. Aqui nao tem dragoes." << std::endl;
            break;
        case 2:
            std::cout << "Poxa... voce sabe que o nome do jogo eh *Albion Online* e mesmo assim clicou em Gigabyte." << std::endl;
            break;
        case 3:
            std::cout << "BLZ, agora sim! Vamos entrar no mundo de cabeca." << std::endl;
            break;
    }
}

int escolherOpcaoInicial() {
    int resposta = 0;
    int tentativas = 0;

    do {
        std::cout << "O que voce faz aqui?" << std::endl;
        std::cout << "[1] Estou aqui para Derrotar Dragons." << std::endl;
        std::cout << "[2] Sei la cara, isso aqui nao eh albion? acho que baixei errado." << std::endl;
        std::cout << "[3] Quero jogar o Gigabyte." << std::endl;
        linha();

        std::cin >> resposta;

        if (std::cin.fail()) {
            limparEntrada();
            std::cout << "Digitou um caractere? Que ousado voce hein..." << std::endl;
            tentativas++;
            continue;
        }

        if (resposta < 1 || resposta > 3) {
            respostaInvalida(tentativas);
            tentativas++;
        }

    } while (resposta < 1 || resposta > 3);

    return resposta;
}