# S-DES – Simplified DES

Este projeto implementa o algoritmo **S-DES (Simplified DES)**, uma versão didática do algoritmo de cifra de blocos DES, com suporte aos modos de operação ECB e CBC. Desenvolvido como parte do Trabalho de Implementação 1 da disciplina **Segurança Computacional – CIC0201 (UnB)**, ministrada pela professora Lorena Borges.

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
S-DES/
├── docs/ # Documentação e relatório
│ ├── relatorio.pdf # Relatório final do projeto
│ ├── html/ # Criada automaticamente pelo Doxygen (documentação em HTML)
│ ├── latex/ # Criada automaticamente pelo Doxygen (documentação em LaTeX)
│ ├── mainpage.dox # Conteúdo da página inicial da documentação do Doxygen
│
├── src/ # Código-fonte principal (limpo, modular e comentado)
│ ├── encrypt.hpp # Implementação dos modos ECB e CBC
│ ├── ffunction.hpp # Implementação da função F com S-Boxes e operações XOR
│ ├── input.hpp # Funções de entrada e menus interativos
│ ├── keygen.hpp # Geração das subchaves K1 e K2
│ ├── modes.hpp # Interface para modos de operação
│ ├── permutation.hpp # Permutações P10, P8, IP, IP⁻¹, P4
│ ├── sdes.cpp # Arquivo principal com o ponto de entrada do programa
│ └── utils.hpp # Funções auxiliares e validações (binário, inteiro, etc.)
│
├── src_imprimir/ # Versões com saídas detalhadas (verbose) para apresentação
│ ├── main.cpp # Menu interativo com impressão detalhada dos passos
│ └── ... # Módulos correspondentes aos de src/, mas com couts adicionais
│
├── .gitignore # Arquivos e pastas ignorados pelo Git
├── Doxyfile # Arquivo de configuração do Doxygen
├── Makefile # Define comandos para compilar, limpar, documentar e executar
├── README.md # Arquivo com instruções de uso e informações do projeto
```

> A separação entre `src/` e `src_imprimir/` foi feita para manter a clareza e facilitar a leitura do código.
> ℹ️ **Nota:** A documentação das funções está incorporada diretamente nos arquivos da pasta `src/`, usando comentários no padrão do **Doxygen**.  
> Para entender o funcionamento detalhado de cada parte do algoritmo, consulte os cabeçalhos e descrições nos próprios arquivos `.hpp` e `.cpp` dentro da pasta `src/`.


---

## ⚙️ Funcionalidades

- ✅ Geração de subchaves com impressão das etapas
- ✅ Encriptação e decriptação de blocos
- ✅ Modos ECB e CBC
- ✅ Impressão passo a passo (opcional)
- ✅ Menu interativo no terminal

---

## 🧪 Como compilar

Para compilar e executar o projeto, certifique-se de ter o g++ instalado e digite:

### Usando Makefile:
```bash
make run
```

### Ou manualmente:
g++ -std=c++17 -o sdes src_imprimir/main.cpp
./sdes

### 📦 Dependências

Para compilar o projeto e gerar a documentação com o Doxygen, é necessário ter os seguintes pacotes instalados no sistema:

- `g++` (compilador C++)
- `make` (utilitário de automação de build)
- `doxygen` (geração automática de documentação)

---

### 🧰 Como instalar as dependências

<details><summary><strong>Ubuntu/Debian</strong></summary>

```bash
sudo apt update
sudo apt install build-essential doxygen
```
> O pacote `build-essential` inclui o `g++` e o `make`.
</details> 

<details> <summary><strong>Fedora</strong></summary>
```bash
sudo dnf install gcc-c++ make doxygen
```
</details>

 <details> <summary><strong>Arch Linux</strong></summary>
```bash
sudo pacman -S base-devel doxygen
```
> O grupo `base-devel` inclui o `make` e o `g++`.
</details> 

<details> <summary><strong>macOS (com Homebrew)</strong></summary>
```bash
brew install make doxygen
```
> O `g++` já vem com o Xcode Command Line Tools. Para garantir:
```bash
xcode-select --install
```
</details> 
<details> <summary><strong>Windows</strong></summary>

1. Instale o [MinGW](http://www.mingw.org/) ou [MSYS2](https://www.msys2.org/), que oferecem `g++` e `make`.

2. Instale o Doxygen por meio do instalador:  
   👉 [https://www.doxygen.nl/download.html](https://www.doxygen.nl/download.html)

</details>

### ✅ Verificação

Execute os comandos abaixo para verificar se os pacotes foram instalados corretamente:

```bash
g++ --version
make --version
doxygen --version
```

Se os três exibirem a versão instalada, está tudo pronto.


### 🛠️ Comandos úteis (`make`)

- `make run` — Compila o projeto e executa o binário.
- `make clean` — Remove o executável e os arquivos `.o`.
- `make doxygen` — Gera a documentação com o Doxygen.
- `make html` — Gera a documentação e abre automaticamente `html/index.html` no navegador.
- `make doc-clean` — Remove a pasta `html` criada.

> ⚠️ A pasta `html/` será criada automaticamente ao rodar `make doxygen`.

---

👨‍💻 Autores

   - Iasmim de Queiroz Freitas
   - Lucas Issamu Hashimoto

Segurança Computacional – 2025/1 (CIC0201)