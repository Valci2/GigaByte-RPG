#include <iostream>
#include <thread> // Fornece acesso à biblioteca de multithreading da C++ Standard Library, usada para criar e gerenciar threads.
#include <chrono> // Traz ferramentas de tempo, como duração, relógios, contagem de tempo etc.
#include <limits> // Fornece limites numéricos para os tipos primitivos (como int, float, etc.).
#include <random> // Para randomizar de forma moderna
#include "../../inc/utilitarios/utilitarios.h"

// limpa a entrada de uma resposta errada
void limparEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// faz o programa pelo momento que você decidir
void delay(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

// printa o titulo formatado
void titulo(const std::string &titulo) {
    std::cout << "========= " << titulo << " =========" << std::endl;
}

// printa uma linha
void linha() {
    std::cout << "===============================" << std::endl;
}

// gera um numero aleatorio
int randint(int min, int max) {
    static std::mt19937 gerador(std::random_device{}()); // Criado só na 1ª chamada
    std::uniform_int_distribution<int> distribuicao(min, max);
    return distribuicao(gerador);
}

int validarEscolha(int min, int max) {
    int escolha;
    while (true) {
        std::cout << "Escolha: ";
        std::cin >> escolha;
        if (!std::cin.fail() && escolha >= min && escolha <= max)
            return escolha;
        limparEntrada();
        std::cout << "Entrada inválida! Digite um número entre " << min << " e " << max << ".\n";
    }
}