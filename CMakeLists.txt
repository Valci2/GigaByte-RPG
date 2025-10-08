cmake_minimum_required(VERSION 3.20)
project(RPG)

set(CMAKE_CXX_STANDARD 20)

# Agrupa todos os arquivos automaticamente
file(GLOB_RECURSE SOURCES
        "Projeto-de-orientacao-a-objeto-em-CPP/src/**/*.cpp"
        "Projeto-de-orientacao-a-objeto-em-CPP/main.cpp"
)

add_executable(RPG ${SOURCES})