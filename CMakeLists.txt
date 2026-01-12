# Diz qual é a versão mínima do CMake necessária para processar esse arquivo
cmake_minimum_required(VERSION 3.20)

# Define o nome do projeto
project(RPG)

# Define a versão do C++ que o compilador deve usar, neste caso, o C++20
set(CMAKE_CXX_STANDARD 20)

# Adiciona o diretório include/ como caminho para os arquivos de cabeçalho (.hpp)
include_directories(inc
    inc/Monstros
)

# Agrupa todos os arquivos automaticamente
file(GLOB_RECURSE SOURCES
        src/Fases.cpp
        src/INN.cpp
        src/Loja.cpp
        src/Utilitarios.cpp
        src/Historia.cpp
        src/Lobby.cpp
        src/Personagem.cpp
        src/Itens.cpp
        src/Monstros/Monstro.cpp
        src/Combate.cpp
        src/main.cpp
)

# Cria o executável do seu programa, chamado RPG
add_executable(RPG ${SOURCES}
        inc/Tipos.h
        src/Monstros/Boss.cpp
        inc/Monstros/Boss.h
        src/Entidade.cpp
        inc/Entidade.h)