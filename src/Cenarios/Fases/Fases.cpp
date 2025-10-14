#include "Cenarios/Fases/Fases.h"
#include <iostream>

// partes da primeira fase
std::vector<std::string> faseUm = {
    {"Cache"},
    {"RAM"},
    {"ROM"}
};

// partes da segunda fase
std::vector<std::string> faseDois = {
    {"Chipset"},
    {"GPU"},
    {"Bios"}
};

// partes da terceira fase
std::vector<std::string> fasetres = {
    {"Unidade de Controle (UC)"},
    {"Unidade Lógica e Aritmética (ULA)"},
    {"Registradores"}
};

// principal
void Fases::entrar(Personagem &jogador) {

}

// menu das fases
void Fases::menuDeFases() {
    std::cout << "[1] - Memoria" << std::endl;
    std::cout << "[2] - Placa mae" << std::endl;
    std::cout << "[3] - CPU" << std::endl;
}

// menu das partes
void Fases::menuDasPartes(const std::vector<std::string> &fases) {
    for (int i = 0; i < fases.size(); i++) {
        std::cout << "[" << i << "] - " << fases[i] << std::endl;
    }
}
