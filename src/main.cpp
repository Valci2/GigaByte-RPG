#include "Personagem.h"
#include "Historia.h"
#include "Lobby.h"

// personagem recebe o dano e a defesa lá na loja ou personagem recebe em invantario
// colocar defesa das armaduras e ataque das armas
// colocar um sistema pra trocar a armadura e a arma se o jogador quiser
// talvez ajustar melhor os atributos

// fazer as historias
// talvez fazer o lobby gerenciar as historias

// fazer as magias e o sistema de magias 


// adicinar comentarios?

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