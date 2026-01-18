#include "Monstros/FabricaDeMonstros.h"
#include "Utilitarios.h"

FabricaDeMonstros::FabricaDeMonstros() {}
FabricaDeMonstros::~FabricaDeMonstros() {}

// ======================== lista de monstros ========================
// listas de monstros da primeira fase
std::vector<TemplateMonstro> FabricaDeMonstros::monstrosFaseUm = {
    { "Cache Fantasma", 5, 3, 1, 2, 2, 1, 3, 1, 3 },
    { "Bit Perdido", 6, 4, 2, 3, 1, 1, 4, 1, 3 },
    { "Pixel Morto", 10, 10, 4, 7,  3, 2, 5, 2, 5 },
    { "Pacote Malicioso", 14, 8, 6, 7, 4, 2, 6, 2, 5 },
    { "Memória Corrompida", 25, 20, 11, 4, 8, 10, 20, 10, 20 }
};

// listas de monstros da segunda fase
std::vector<TemplateMonstro> FabricaDeMonstros::monstrosFaseDois = {
    { "Chipset Sombrio", 20, 15, 10, 9, 10, 20, 30, 20, 30 },
    { "Barramento Caótico", 23, 16, 10, 10, 9, 20, 35, 20, 35 },
    { "Slot Vazio", 25, 20, 10, 10, 14, 35, 50, 35, 50 },
    { "BIOS Antiga", 25, 23, 12, 12, 11, 45, 70, 40, 50 },
    { "Conector Enferrujado", 35, 30, 14, 15, 16, 100, 150, 50, 100 }
};

// listas de monstros da terceira fase
std::vector<TemplateMonstro> FabricaDeMonstros::monstrosFaseTres = {
    { "Thread Caótica", 30, 12, 13, 18, 15, 100, 150, 0, 0 },
    { "Segmentation Fault", 32, 12, 14, 18, 16, 100, 160, 0, 0 },
    { "Overclock Insano", 36, 13, 15, 20, 17, 120, 180, 0, 0 },
    { "Pipeline Quebrado", 40, 11, 17, 25, 16, 160, 200, 0, 0 },
    { "Deadlock", 60, 50, 20, 40, 20, 400, 600, 400, 600 }
};

// ========================================================================
Monstro FabricaDeMonstros::fabricar(int fase, int parte)
{
    std::vector<TemplateMonstro>* pool = &monstrosFaseUm;

    if (fase == 2) pool = &monstrosFaseDois;
    else if (fase == 3) pool = &monstrosFaseTres;

    int indice = 0;

    if (parte == 1)
        indice = randint(0, pool->size() - 4);
    else if (parte == 2)
        indice = randint(2, pool->size() - 2);
    else
        indice = pool->size() - 1;

    const TemplateMonstro& t = (*pool)[indice];

    Monstro m(
        t.nome,
        t.hpBase + randint(-2, 2),
        t.manaBase + randint(-2, 2),
        t.forcaBase + randint(-1, 1),
        t.inteligenciaBase + randint(-1, 1),
        t.defesaBase + randint(-1, 1),
        randint(t.xpMin, t.xpMax),
        randint(t.capibasMin, t.capibasMax)
    );

    return m;
}