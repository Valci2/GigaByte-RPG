#include "INN.h"
#include "Utilitarios.h"
#include <iostream>

void INN::entrar(Personagem &jogador) {
    int escolha = 0;
    while (true) {
        titulo("INN");
        std::cout << "[1] Dormir" << std::endl;
        std::cout << "[2] Voltar" << std::endl;

        escolha = validarEscolha(1, 2);

        switch (escolha) {
            case 1:
                std::cout << "Olha... ele dorme como um anjinho." << std::endl;
                std::cout << "ZZZZZZZZZZZZ" << std::endl;
                jogador.dormir();
                delay(2);
                return;
            case 2:
                std::cout << "Saindo do INN" << std::endl;
                delay(1);
                return;
        }
    }
}