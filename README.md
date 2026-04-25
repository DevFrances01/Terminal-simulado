# 💻 Terminal-simulado

**Terminal-simulado** é um shell interativo desenvolvido em C++, com foco educacional, que simula o comportamento de um terminal de sistema operacional.
> ⚠️ Este projeto é educacional e **não é um sistema operacional real**.
---
## 🧠 Sobre o projeto

O Terminal-simulado funciona como um **shell personalizado**, semelhante a interpretadores como o Bash ou o PowerShell.

Ele permite:

* Entrada de comandos via terminal
* Interpretação dinâmica de comandos
* Execução de funções associadas
* Simulação de um ambiente de sistema

---

## ⚙️ Funcionalidades

* 🔹 Sistema de comandos (`help`, `version`, `clear`, `user`, `exit`)
* 🔹 Interface estilo terminal
* 🔹 Simulação de boot
* 🔹 Gerenciamento simples de usuário
* 🔹 Estrutura modular com `std::map` e `std::function`

---

## 🚀 Como executar

### Pré-requisitos

* Compilador C++ (ex: GCC)
* Windows ou Linux

### Compilação

```bash id="k5h2sv"
g++ main.cpp -o terminal
```

### Execução

```bash id="csn6z1"
./terminal
```
---

## 🔧 Tecnologias utilizadas

* C++
* STL (`map`, `string`, `functional`)
* Console/Terminal

---

## 🧩 Melhorias futuras

* Integração com Python
* Sistema de arquivos simulado (`ls`, `cd`)
* Plugins/scripts
* Interface mais avançada
* Persistência de dados

---
