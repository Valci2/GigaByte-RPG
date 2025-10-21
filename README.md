# 🧠 GigaByte RPG — Um mini RPG de terminal em C++

## 🧩 Sobre o Projeto

**GigaByte RPG** é um projeto desenvolvido em **C++**, utilizando **Programação Orientada a Objetos (POO)** e **Estruturas de Dados (EDOO)**.
O jogo é um **RPG de terminal** ambientado dentro de um **computador**, onde o jogador desperta em um mundo digital caótico e precisa enfrentar ameaças tecnológicas para sobreviver.

O projeto é modular, dividido em múltiplos arquivos e diretórios, simulando um jogo completo com:

* Loja 🏪
* Fases ⚔️
* Pousada (INN) 🛏️
* Lobby 🎮
* Sistema de personagem e inventário 💾

---

## 🧙‍♂️ História

Você acorda no misterioso **mundo de GigaByte**, um lugar onde **componentes eletrônicos ganharam vida**.
De relés revoltados a CPUs com mania de grandeza, todo tipo de bug e travamento te aguarda.

Seu objetivo?
**Derrotar a corrupção digital**, evoluir, comprar upgrades e — se a sorte permitir — enfrentar o **Boss Supremo: o próprio PC.**

> “O PC. Aquele que liga quando quer, reinicia no meio da luta e ainda joga a culpa no driver da placa de vídeo.”

---

## ⚔️ Funcionalidades Principais

* 🧱 **Estrutura modular**: cada área do jogo (Loja, INN, Fases etc.) possui seus próprios headers e fontes.
* 💰 **Sistema de loja**: compre armas, poções e equipamentos.
* 🏕️ **Pousada (INN)**: descanse e recupere HP e MP.
* 🗺️ **Fases**: enfrente desafios e inimigos em batalhas por turnos.
* 🧠 **História interativa**: introdução com diálogos e escolhas.
* 🎭 **Personagem com status**: HP, mana, força, defesa e inventário.
* 🧰 **POO aplicada**: herança, encapsulamento, construtores, métodos e classes modulares.

---

## 🧠 Estrutura do Código

```
GigaByte-RPG/
├── inc/                    # Cabeçalhos (.h)
│   ├── Monstros
│   ├── Fases.h
│   ├── Historia.h
│   ├── INN.h
│   ├── Itens.h
│   ├── Lobby.h
│   ├── Loja.h
│   ├── Personagem.h
│   └── Utilitarios.h
│
├── src/                    # Implementações (.cpp)
│   ├── Monstros
│   ├── Fases.cpp
│   ├── Historia.cpp
│   ├── INN.cpp
│   ├── Itens.cpp
│   ├── Lobby.cpp
│   ├── Loja.cpp
│   ├── Personagem.cpp
│   ├── Utilitarios.cpp
│   └── main.cpp
│
├── CMakeLists.txt          # Configuração do build
└── README.md               # Documento atual
```

Essa divisão segue boas práticas de arquitetura em C++, permitindo **expansão fácil** e **manutenção organizada**.

---

## 🧱 Conceitos de POO Utilizados

* **Classes e Objetos**: `Personagem`, `Loja`, `INN`, `Lobby`, etc.
* **Encapsulamento**: uso de atributos privados e métodos públicos.
* **Herança e Polimorfismo** (em desenvolvimento): para definir monstros e fases derivadas.
* **Modularização**: separação clara entre `.h` e `.cpp`.
* **Controle de entrada e fluxo**: funções para validar respostas e interações do jogador.

---

## 🕹️ Como Rodar o Jogo

### 🔹 Passo 1 — Clonar o repositório

```bash
git clone https://github.com/Valci2/GigaByte-RPG.git
cd GigaByte-RPG
```

### 🔹 Passo 2 — Compilar com CMake

#### No terminal (Linux / VS Code)

```bash
cmake -B build
cmake --build build
./build/main
```

#### No CLion

1. Abra o projeto.
2. Aguarde o CMake configurar automaticamente.
3. Clique em **Run ▶️**.

---

## 🧩 Exemplo de Gameplay (Introdução)

```cpp
std::cout << "============= GigaByte =============" << std::endl;
std::cout << "Ola jogador, voce esta no mundo de Gigabyte, um mundo dentro do seu PC." << std::endl;
delay(3);
```

O jogador é então levado à escolha inicial:

```
O que voce faz aqui?
[1] Estou aqui para Derrotar Dragons.
[2] Sei la cara, isso aqui nao eh albion? acho que baixei errado.
[3] Quero jogar o Gigabyte.
```

Dependendo da escolha, a história segue um rumo diferente — com muito humor e auto-referência ao próprio código.

---

## 💾 Próximas Expansões

* 🧟 Sistema de inimigos e batalhas (Monstros)
* 💬 Diálogos com NPCs
* 🧰 Sistema de inventário completo
* 🎯 Sistema de habilidades (magias e golpes especiais)

---

## 🎓 Objetivo Educacional

Este projeto foi desenvolvido para **aprender C++ na prática**, aplicando:

* Estrutura de código limpa e modular
* Organização em múltiplos arquivos
* Padrões de projeto simples
* Controle de fluxo e entrada no terminal
* Uso real de classes e objetos

---

## ✍️ Autor

**Valci Marques de Melo**
Projeto desenvolvido para estudos de **POO / EDOO**, com C++ e CMake.

> “Um jogo dentro do PC, feito dentro do PC, que roda dentro do PC.” — *o dev, provavelmente.*

---

Quer que eu adicione uma seção final com **prints (simulados)** do terminal, mostrando o início do jogo com cores e layout estilo RPG de texto (exemplo visual dentro do README)? Isso deixa o repositório muito mais atrativo visualmente.
