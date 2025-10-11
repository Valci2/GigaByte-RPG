cmake_minimum_required(VERSION 3.20)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

# Agrupa todos os arquivos automaticamente
file(GLOB_RECURSE SOURCES
        "src/Cenarios/fases/fases.cpp"
        "src/Cenarios/INN/INN.cpp"
        "src/Cenarios/Loja/Loja.cpp"
        "src/utilitarios/utilitarios.cpp"
        "src/Historia/Historia.cpp"
        "src/Lobby/Lobby.cpp"
        "src/Personagem/Personagem.cpp"
        "src/Personagem/Itens/Itens.cpp"
        "src/Monstros/monstros.cpp"
        "src/main.cpp"
)

add_executable(RPG ${SOURCES})