/**
 * @file ffunction.hpp
 * @brief Implementação das funções de encriptação e decriptação do algoritmo S-DES
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 * 
 * @note Utiliza a variável global 'encriptar' de utils.hpp
 * @note Controle global de operação:
 * - encriptar = 2: Modo encriptação (usa K1 depois K2)
 * - encriptar = 1: Modo decriptação (inverte para K2 depois K1)
 * 
 * @warning A variável 'encriptar' deve ser modificada apenas pelas funções deste módulo
 */

#include "ffunction.hpp"

/**
 * @brief Realiza a encriptação de um bloco de 8 bits usando S-DES
 * @details O comportamento depende do valor global 'encriptar':
 * - Se encriptar == 2: Encripta com K1 → K2 (padrão)
 * - Se encriptar == 1: Decripta com K2 → K1
 * 
 * @param n Bloco de 8 bits a ser encriptado (0-255)
 * @param k Chave mestra de 10 bits (0-1023)
 * @return int Bloco encriptado de 8 bits
 * 
 * @pre n deve ser um valor de 8 bits (0 <= n <= 255)
 * @pre k deve ser um valor de 10 bits (0 <= k <= 1023)
 * @post O resultado será um bloco de 8 bits encriptado
 * 
 * @note O processo segue estas etapas:
 * 1. Geração das subchaves K1 e K2
 *      -> Inverte a ordem se encriptar == 1
 * 2. Permutação inicial (IP)
 * 3. Aplicação da rede de Feistel (2 rodadas)
 * 4. Permutação final (IP⁻¹)
 */
int encriptacao(int n, int k){
    int k1, k2;
    gerarChaves(k, k1, k2);
    if(encriptar&1) swap(k1, k2);

    n = permutacaoInicial(n);
    auto [l, r] = dividi(n);
    n = feistel(l, r, k1, k2);
    n = permutacaoFinal(n);
    
    return n;
}

/**
 * @brief Função conveniente para decriptação
 * @details Configura automaticamente encriptar = 1 para decriptação,
 * executa a operação e restaura o valor original (2)
 * 
 * @param n Bloco de 8 bits a ser decriptado (0-255)
 * @param k Chave mestra de 10 bits (0-1023)
 * @return int Bloco decriptado de 8 bits
 * 
 * @note A decriptação é implementada como uma encriptação com:
 * 1. Ordem inversa das subchaves (K2, K1)
 * 2. Mesma rede de Feistel
 */
int decriptacao(int n, int k){
    encriptar = 1;
    n = encriptacao(n, k);
    encriptar = 2;
    return n;
}