/**
 * @file permutation.hpp
 * @brief Implementação das tabelas de permutação e função de permutação para o algoritmo S-DES.
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */

#include "utils.hpp"

// Tabelas de permutação (documentação em linha)
vector<int> p10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};  ///< Tabela P10 (10 bits de entrada).
vector<int> p8 = {6, 3, 7, 4, 8, 5, 10, 9};         ///< Tabela P8 (10 bits -> 8 bits).
vector<int> p4 = {2, 4, 3, 1};                      ///< Tabela P4 (4 bits de saída).
vector<int> ip = {2, 6, 3, 1, 4, 8, 5, 7};          ///< Tabela de Permutação Inicial (IP).
vector<int> ipi = {4, 1, 3, 5, 7, 2, 8, 6};         ///< Tabela de Permutação Inversa (IP⁻¹).
vector<int> ep = {4, 1, 2, 3, 2, 3, 4, 1};          ///< Tabela de Expansão (4 bits -> 8 bits).
vector<vector<int>> s0 = {                           
    {1, 0, 3, 2},
    {3, 2, 1, 0},
    {0, 2, 1, 3},
    {3, 1, 3, 2}
};                                                  ///< Matriz S-Box 0 (4 bits -> 2 bits).
vector<vector<int>> s1 = {                           
    {0, 1, 2, 3},
    {2, 0, 1, 3},
    {3, 0, 1, 0},
    {2, 1, 0, 3}
};                                                  ///< Matriz S-Box 1 (4 bits -> 2 bits).{}


/**
 * @brief Aplica uma permutação em um número inteiro usando uma tabela específica.
 * @details Cada bit do resultado é mapeado a partir da tabela de permutação.
 * 
 * @param n Número de entrada (bits a serem permutados).
 * @param v Tabela de permutação (ex.: p10, p8, ip, etc.).
 * @param total_bits Número total de bits em 'n' (padrão: 10).
 * @return int Valor permutado com tamanho igual ao tamanho da tabela 'v'.
 * 
 * @pre v não deve estar vazia.
 * @pre total_bits deve ser >= ao maior valor em 'v'.
 * @pre n deve ser um valor válido dentro do número de bits especificado.
 * @post O resultado terá exatamente v.size() bits.
 */
int permuta(int n, vector<int> &v, int total_bits = 10){
    int resultado = 0;
    for(int i = 0; i < (int)v.size(); i++){
        resultado = resultado << 1;
        resultado |= (n >> (total_bits - v[i])) & 1;
    }
    return resultado;
}