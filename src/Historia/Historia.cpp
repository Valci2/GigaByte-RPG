#include "../../inc/Historia/Historia.h"
#include "../../inc/utilitarios/utilitarios.h"
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

Personagem apresentacao() {
    std::cout << "============= GigaByte =============" << std::endl;
    std::cout << "Ola jogador, voce esta no mundo de Gigabyte, um mundo dentro do seu PC." << std::endl;
    delay(3);

    linha();
    std::cout << "Bem como eu estou sendo desenvolvido para um projeto que precisa usar POO, entao" << std::endl;
    std::cout << "preciso criar um objeto da classe Personagem. Para isso, preciso que voce forneca seu nome." << std::endl;
    std::cout << "(sim, forneca. infelizmente fui programado em c++ e nao consigo computar acentos)." << std::endl;

    delay(5);
    std::cout << "entao coloca ai, se nao o programa nao roda. ;-;" << std::endl;

    linha();
    std::cout << "Digite seu nome: ";
    std::string nome = "";
    std::cin >> nome;
    Personagem jogador(nome);

    std::cout << "Valeu. Seu nome esta sendo alocado pra memoria RAM (ou cache, sei la).." << std::endl;
    delay(2);
    std::cout << "Agora sim, voce esta oficialmente 'instanciado'." << std::endl;
    delay(3);
    linha();

    int resposta = escolherOpcaoInicial();
    responderOpcao(resposta);

    delay(3);
    linha();
    return jogador;
}

void historia01() {
    std::cout << "No glorioso, caotico e totalmente instavel mundo de GigaByte — um mundo onde componentes eletronicos" << std::endl;
    std::cout << "ganham vida, personalidades duvidosas e vontade propria de te ver sofrer. De relays revoltados ate" << std::endl;
    std::cout << "CPUs com delirio de grandeza, cada um mais insuportavel que o outro." << std::endl;
    delay(5);

    linha();
    std::cout << "Seu objetivo? Enfrentar essa trupe de sucata viva, subir de nivel e, com sorte (e um milagre)," << std::endl;
    std::cout << "encarar o Boss Supremo: o lendario PC. Isso mesmo, o PC. Aquele que liga quando quer, reinicia no" << std::endl;
    std::cout << "meio da luta e ainda joga a culpa no driver da placa de video." << std::endl;
    delay(5);

    linha();
    std::cout << "Domine. Capture. Aprenda. (Quer dizer, 'capturar' e modo de dizer mesmo... o dev ate pensou em" << std::endl;
    std::cout << "colocar mecanica de captura, mas ai lembrou que tinha vida para viver, abriu o iFood e nunca mais voltou nessa" << std::endl;
    std::cout << "parte do codigo.)" << std::endl;
    std::cout << "Enfim, e so sair dando porrada nos chips e fingir que ta tudo funcionando." << std::endl;
    delay(5);

    linha();
    std::cout << "Vou te apresentar o Lobby eh nele que voce pode fazer upgrades, descansar, escolher as fases, ver os status, Etc." << std::endl;
    std::cout << "[1] Fases: voce pode acessar as 3 fases principais do jogo aqui dentro." << std::endl;
    std::cout << "[2] Loja: voce pode comprar suas armas, pocoes, aqui." << std::endl;
    std::cout << "[3] INN: voce pode descansar nesse pousada, assim voce recupera HP (vida) e MP (mana)." << std::endl;
    std::cout << "[4] Status: voce ve os status do personagem, HP, mana, forca, defesa, etc." << std::endl;
    std::cout << "[5] Inventario: voce ve os itens que você possui e os seus equipamentos." << std::endl;
    delay(10);
}