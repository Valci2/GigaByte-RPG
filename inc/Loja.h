#pragma once
#include "Personagem.h"
#include "Tipos.h"

#include <vector>

struct itensDeCompra;

class Loja {
public:
    Loja() = default;

    // entrada da loja
    void entrar(Personagem &jogador);

    // menu da loja
    void menuDeCompras();

    // menu das armas/armaduras e a logica de troca das armas/armaduras
    void menuDeItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, const std::string &tituloMenu, TipoItem tipo);

    bool trocarItens(const std::vector<itensDeCompra> &itens, Personagem &jogador, int escolha, TipoItem tipo);
    void comprarPocao(const std::vector<itensDeCompra> &pocoes, int escolha, Personagem &jogador, int quantidade);
};
