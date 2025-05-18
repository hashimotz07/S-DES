/**
 * @file keygen.hpp
 * @brief Implementação das funções de deslocamento circular e geração de chaves para o algoritmo S-DES.
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */

#include "permutation.hpp"

/**
 * @brief Realiza um deslocamento circular (bit rotation) em um número binário.
 * @details Rotaciona os bits do número para a esquerda, com wraparound.
 * 
 * @param n Número de entrada a ser rotacionado.
 * @param tamanho Número total de bits em 'n'.
 * @param shift Número de posições para rotacionar.
 * @return int Valor rotacionado com 'tamanho' bits.
 * 
 * @pre tamanho > 0 && tamanho <= 32 bits (sizeof(int)*8)
 * @pre shift > 0 && shift < tamanho
 * @post O resultado terá exatamente 'tamanho' bits (bits extras são truncados).
 * 
 * Exemplo de uso:
 * @code
 *   deslocamento_circular(0b10110, 5, 1) // Retorna 0b01101 (rotaciona 1 posição)
 *   deslocamento_circular(0b10110, 5, 2) // Retorna 0b11010 (rotaciona 2 posições)
 * @endcode
 */
int deslocamento_circular(int n, int tamanho, int shift){
    return ((n<<shift) | ((n>>(tamanho - shift)) & ((1 << shift)-1))) & ((1<<tamanho)-1);
}

/**
 * @brief Gera as subchaves K1 e K2 a partir de uma chave inicial de 10 bits.
 * @details Implementa o processo completo do S-DES:
 *          1. Aplica P10 na chave inicial.
 *          2. Divide em 2 blocos de 5 bits.
 *          3. Rotaciona e aplica P8 para gerar K1 e K2.
 * 
 * @param chave Chave inicial de 10 bits.
 * @param[out] k1 Subchave K1 (8 bits).
 * @param[out] k2 Subchave K2 (8 bits).
 * 
 * @pre chave deve ser um valor de 10 bits válido (0 <= chave <= 1023).
 * @post k1 e k2 serão valores de 8 bits (0 <= k1, k2 <= 255).
 * 
 * Exemplo de uso:
 * @code
 *   int k1, k2;
 *   gerarChaves(0b1010000010, k1, k2);
 * @endcode
 */
void gerarChaves(int chave, int &k1, int &k2){
    // permutacao inicial (P10)
    int permutacao = permuta(chave, p10);
    int esquerda = (permutacao>>5); // 5 bits mais significativos
    int direita = (permutacao); // 5 bits menos significativos

    // geracao da k1 (shift de 1 posicao + P8)
    esquerda = deslocamento_circular(esquerda, 5, 1);
    direita = deslocamento_circular(direita, 5 , 1);
    k1 = permuta((esquerda << 5) | direita, p8);

    // geracao da k2 (shift de 2 posicoes + p8)
    esquerda = deslocamento_circular(esquerda, 5, 2);
    direita = deslocamento_circular(direita, 5 , 2);
    k2 = permuta((esquerda << 5) | direita, p8);
}