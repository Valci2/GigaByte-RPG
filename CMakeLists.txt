# Diz qual é a versão mínima do CMake necessária para processar esse arquivo
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto
project(RPG)

# Define a versão do C++ que o compilador deve usar, neste caso, o C++20
set(CMAKE_CXX_STANDARD 20)

# Adiciona o diretório include/ como caminho para os arquivos de cabeçalho (.hpp)
include_directories(inc)

# Agrupa todos os arquivos automaticamente
file(GLOB_RECURSE SOURCES
        src/Cenarios/fases/fases.cpp
        src/Cenarios/INN/INN.cpp
        src/Cenarios/Loja/Loja.cpp
        src/utilitarios/utilitarios.cpp
        src/Historia/Historia.cpp
        src/Lobby/Lobby.cpp
        src/Personagem/Personagem.cpp
        src/Personagem/Itens/Itens.cpp
        src/Monstros/monstros.cpp
        src/main.cpp
)

# Cria o executável do seu programa, chamado RPG
add_executable(RPG ${SOURCES})