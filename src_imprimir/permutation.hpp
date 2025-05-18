/**
 * @file permutation.hpp
 * @brief Versão debug das tabelas e funções utilitárias - Documentação completa em src/permutation.hpp
 * @note Contém implementações idênticas às origens com adição de logs condicionais
 * @see src/permutation.hpp para documentação completa das funções
 */

#include "utils.hpp"

// Tabelas de permutação (documentação completa em src/permutation.hpp)
vector<int> p10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};                                  ///< P10 (10→10 bits)
vector<int> p8 = {6, 3, 7, 4, 8, 5, 10, 9};                                         ///< P8 (10→8 bits)
vector<int> p4 = {2, 4, 3, 1};                                                      ///< P4 (4→4 bits)
vector<int> ip = {2, 6, 3, 1, 4, 8, 5, 7};                                          ///< Permutação inicial
vector<int> ipi = {4, 1, 3, 5, 7, 2, 8, 6};                                         ///< Permutação inversa
vector<int> ep = {4, 1, 2, 3, 2, 3, 4, 1};                                          ///< Expansão (4→8 bits)
vector<vector<int>> s0 = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};  ///< S-Box 0 (4→2 bits)
vector<vector<int>> s1 = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};  ///< S-Box 1 (4→2 bits)

/**
 * @brief Aplica permutação com logs (documentação completa em src/permutation.hpp)
 * @param n Valor a permutar
 * @param v Tabela de permutação
 * @param total_bits Tamanho da entrada (padrão: 10)
 * @return Valor permutado
 * @debug Logs mostram entrada/saída e tabela usada
 */

int permuta(int n, vector<int> &v, int total_bits = 10){
    int resultado = 0;
    for(int i = 0; i < (int)v.size(); i++){
        resultado = resultado << 1;
        resultado |= (n >> (total_bits - v[i])) & 1;
    }
    return resultado;
}