/**
 * @file ffunction.hpp
 * @brief Implementação das funções de permutação, S-Box e rede de Feistel para o S-DES.
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */

#include "keygen.hpp"

/**
 * @brief Aplica a permutação inicial (IP) em um bloco de 8 bits.
 * @param n Bloco de 8 bits a ser permutado.
 * @return int Bloco permutado (8 bits).
 * @pre n deve ser um valor de 8 bits (0 <= n <= 255).
 * @post O resultado será uma permutação dos bits de entrada conforme a tabela IP.
 */
int permutacaoInicial(int n){
    return permuta(n, ip, 8);
}

/**
 * @brief Aplica a permutação inversa (IP⁻¹) em um bloco de 8 bits.
 * @param n Bloco de 8 bits a ser permutado.
 * @return int Bloco permutado (8 bits).
 * @pre n deve ser um valor de 8 bits (0 <= n <= 255).
 * @post O resultado será a permutação inversa de IP.
 */
int permutacaoFinal(int n){
    return permuta(n, ipi, 8);
}

/**
 * @brief Divide um bloco de 8 bits em dois blocos de 4 bits (esquerda/direita).
 * @param n Bloco de 8 bits.
 * @return pair<int, int> Par (L, R), onde L = 4 bits MSB, R = 4 bits LSB.
 * @pre n deve ser um valor de 8 bits.
 * @post L e R serão valores de 4 bits cada (0 <= L, R <= 15).
 * 
 * Exemplo de uso:
 * @code
 *   dividi(0b11001010) // Retorna (0b1100, 0b1010)
 * @endcode
 */
pair<int, int> dividi(int n){
    int l = n >> 4;
    int r = n & ((1 << 4) - 1);
    return make_pair(l, r);
}

/**
 * @brief Aplica uma S-Box (Substitution Box) a um bloco de 4 bits.
 * @param n Bloco de 4 bits (0-15).
 * @param s Matriz S-Box (4x4).
 * @return int Bloco de 2 bits resultante.
 * @pre n deve ser um valor de 4 bits (0 <= n <= 15).
 * @pre s deve ser uma matriz 4x4 válida.
 * @post O resultado será um valor de 2 bits (0-3).
 * 
 * Exemplo de uso:
 * @code
 *   s_box(0b1010, s0) // Retorna 0b10 (linha 2, coluna 1)
 * @endcode
 */
int s_box(int n, vector<vector<int>>& s){
    int linha = ((n & 8) >> 2) | (n & 1);
    int coluna = ((n & 4) >> 1) | ((n & 2) >> 1);

    return s[linha][coluna];
}

/**
 * @brief Função F (Expansão + S-Box + Permutação) do S-DES.
 * @param n Bloco de 4 bits.
 * @param k Subchave de 8 bits.
 * @return int Bloco de 4 bits processado.
 * @pre n deve ser um valor de 4 bits.
 * @pre k deve ser um valor de 8 bits.
 * @post O resultado será um valor de 4 bits.
 */
int F(int n, int k){
    n = permuta(n, ep, 4);
    n ^= k;
    int l = s_box(n >> 4, s0);
    int r = s_box(n, s1);
    n = permuta(((l << 2) | r), p4, 4);
    return n;
}

/**
 * @brief Rede de Feistel completa (2 rodadas) para encriptação/decriptação.
 * @param l Bloco esquerdo de 4 bits.
 * @param r Bloco direito de 4 bits.
 * @param k1 Subchave K1 (8 bits).
 * @param k2 Subchave K2 (8 bits).
 * @return int Bloco de 8 bits processado.
 */
int feistel(int l, int r, int k1, int k2){
    l = F(r, k1) ^ l;
    swap(l, r);
    l = F(r, k2) ^ l;
    return ((l << 4) | r);
}