#include "Personagem/Personagem.h"
#include "Historia/Historia.h"
#include "Lobby/Lobby.h"

// colocar a mecanica do uso de pocoes, dava pra colocar atraves de uma função que identifica o tipo de poção que ele quer usar e usar aquele pocao, com uma mecanica de validação facil
// fazer os monstros, fazer uma classe monstro que vai ter ser a classe pai
// fazer a mecanica de combate
// fazer a mecanica das fases
// fazer as historias


int main() {

    // Personagem jogador = apresentacao(); // apresenta o jogador ao mundo, e jogador é criado lá dentro
    // historia01(); // função que conta a primeira parte da historia do jogo
    Personagem jogador("pablito");
    Lobby lobby(jogador);
    lobby.iniciar();

    return 0;
}