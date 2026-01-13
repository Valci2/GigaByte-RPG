#include "Personagem.h"
#include "Historia.h"
#include "Lobby.h"

// colocar defesa das armaduras e ataque das armas

// fazer as historias
// talvez fazer o lobby gerenciar as historias

// talvez colocar um gerenciador de combate que sera uma classe que vai ficar nas fases, ele que vai decidir o combate do jogo, deixando mais facil gerenciar o combate do jogo

// adicinar comentarios?

// personagem recebe o dano e a defesa lá na loja ou personagem recebe em invantario

// colocar a magia
// talvez refatorar a classe do combate

/*
 *
 *
 *
 */

// remover:

/* remover o personagem criado para teste da main
 *
 *
 *
 *
 *
 *
 */

int main() {

    // Personagem jogador = apresentacao(); // apresenta o jogador ao mundo, e jogador é criado lá dentro
    // historia01(); // função que conta a primeira parte da historia do jogo

    Personagem jogador("pablito"); // remover depois
    Lobby lobby(jogador);
    lobby.iniciar();

    return 0;
}