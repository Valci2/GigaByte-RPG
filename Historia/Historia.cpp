#include "Historia.h"
#include "../funcoesUteis/funcoesUteis.h"
#include <iostream>

Personagem apresentacao() {
    std::cout << "============= GigaByte =============" << std::endl;
    std::cout << "Ola jogador, voce esta no mundo de Gigabyte, um mundo dentro do seu PC." << std::endl;
    delay(3);

    linha();
    std::cout << "Bem como eu estou sendo desenvolvido para um projeto que precisa usar POO, entao" << std::endl;
    std::cout << "preciso criar um objeto da classe Personagem. Para isso, preciso que voce forneca seu nome." << std::endl;
    std::cout << "(sim, forneca. infelizmente fui programado em c++ e não consigo computar acentos)." << std::endl;

    delay(5);
    std::cout << "entao coloca ai, se nao o programa não roda. ;-;" << std::endl;

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
    std::cout << "[1] Fases: voce pode acessar as 3 fases principais do jogo aqui dentro" << std::endl;
    std::cout << "[2] Loja: voce pode comprar suas armas, pocoes, aqui." << std::endl;
    std::cout << "[3] INN: voce pode descansar nesse pousada, assim voce recupera HP (vida) e MP (mana)" << std::endl;
    std::cout << "[4] Status: voce ve os status do personagem, HP, mana, forca, defesa, etc." << std::endl;
    std::cout << "[5] Inventario: voce ve os itens que você possui e os seus equipamentos." << std::endl;
    delay(10);
}