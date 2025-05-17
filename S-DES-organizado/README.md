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
```
S-DES-organizado/
├── Makefile # Compila e executa o projeto
├── README.md # Instruções e informações do projeto
│
├── src/ # Código limpo, modular e comentado
│ ├── sdes.cpp # Execução principal do algoritmo S-DES
│ ├── keygen.hpp # Geração de subchaves (K1 e K2)
│ ├── permutation.hpp # Permutações: P10, P8, IP, IP⁻¹, P4
│ ├── ffunction.hpp # Função F com S-Boxes e XOR
│ ├── encrypt.hpp # Modos de operação: ECB e CBC
│ └── utils.hpp # Utilidades e validações de entrada
│
├── src_imprimir/ # Versões com cout para apresentação
│ ├── main.cpp # Menu interativo e passo a passo no terminal
│ ├── encrypt.hpp # Impressão detalhada de ECB e CBC
│ └── ... # Versões verbosas dos demais módulos
```

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
```

### Ou manualmente:
g++ -std=c++17 -o sdes src_imprimir/main.cpp

---

👨‍💻 Autores

   - Iasmim de Queiroz Freitas
   - Lucas Issamu Hashimoto

Segurança Computacional – 2025/1 (CIC0201)