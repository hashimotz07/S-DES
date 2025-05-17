# S-DES – Simplified DES

Este projeto implementa o algoritmo **S-DES (Simplified DES)**, uma versão didática do algoritmo de cifra de blocos DES, como parte do Trabalho de Implementação 1 da disciplina **Segurança Computacional – CIC0201 (UnB)**.

---

## 🎯 Objetivo

A implementação tem como foco:

- Realizar **cifragem e decifragem** de blocos de 8 bits com uma chave de 10 bits.
- Utilizar o algoritmo S-DES completo, incluindo:
  - Geração das subchaves K1 e K2
  - Permutações e trocas (P10, P8, IP, IP⁻¹, etc.)
  - Rodadas de Feistel com S-Boxes
- Suportar os **modos de operação ECB e CBC**, com vetores de inicialização.

---

## 🗂️ Estrutura do Projeto

S-DES-organizado/
├── README.md
├── Makefile
├── src/ # Código limpo, comentado e modular
│ ├── sdes.cpp
│ ├── keygen.hpp
│ ├── permutation.hpp
│ ├── ffunction.hpp
│ ├── encrypt.hpp
│ └── utils.hpp
├── src_imprimir/ # Código com cout para visualização passo a passo
│ ├── main.cpp
│ ├── keygen.hpp
│ ├── permutation.hpp
│ ├── ffunction.hpp
│ ├── encrypt.hpp
│ └── utils.hpp


> A separação entre `src/` e `src_imprimir/` foi feita para manter a clareza e facilitar a leitura do código.

---

## ⚙️ Funcionalidades

- ✅ Geração de subchaves com impressão das etapas
- ✅ Encriptação e decriptação de blocos
- ✅ Modos ECB e CBC
- ✅ Impressão passo a passo (opcional)
- ✅ Menu interativo no terminal

---

## 🧪 Como compilar

### Usando Makefile:
```bash
make

### Ou manualmente:
g++ -std=c++17 -o sdes src_imprimir/main.cpp

👨‍💻 Autores

   - Iasmim de Queiroz Freitas
   - Lucas Issamu Hashimoto

Segurança Computacional – 2025/1 (CIC0201)