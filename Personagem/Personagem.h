#pragma once
#include <string>

#include "Itens/Itens.h"

class Personagem {
    private:
        std::string nome;
        int HP = 5;
        int maxHP = 5;
        int mana = 2;
        int maxMana = 2;
        int nivel = 1;
        int forca = 1;
        int inteligencia = 1;
        int defesa = 0;
        int ouro = 0;
        Itens itens;

    public:
        // construtor
        Personagem(const std::string &nome);

        // metodos
        void status();
        void inventario();

        // Getter e Setter
        std::string getNome();
        void setNome(const std::string &nome);
        int getHP();
        void setHP(int hp);
        int getMaxHP();
        void setMaxHP(int maxHP);
        int getMaxMana();
        void setMaxMana(int mana);
        int getMana();
        void setMana(int mana);
        int getNivel();
        void setNivel(int nivel);
        int getForca();
        void setForca(int forca);
        int getInteligencia();
        void setInteligencia(int inteligencia);
        int getDefesa();
        void setDefesa(int defesa);
        int getOuro();
        void setOuro(int ouro);
};
