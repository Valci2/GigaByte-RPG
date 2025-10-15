#pragma once
#include "../../Personagem/Personagem.h"
#include <vector>

struct itensDeCompra;

class Loja {
public:
    Loja() = default;

    // entrada da loja
    void entrar(Personagem &jogador);

    // menu da loja
    void menuDeCompras();

    // menu das armas e a logica de troca das armas e armaduras
    void menuDeItens(const std::vector<itensDeCompra> &itens, Personagem &jogador,
                     const std::string &tituloMenu, const std::string &tipo);
    bool trocarItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, int escolha,
                     const std::string &tipo);

    void comprarPocao(const std::vector<itensDeCompra> &pocoes, int escolha, Personagem &jogador, int quantidade);
};
