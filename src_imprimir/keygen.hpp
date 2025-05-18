/**
 * @file keygen.hpp
 * @brief Versão debug da geração de chaves - Documentação completa em src/keygen.hpp
 * @note Contém logs detalhados de cada etapa do processo
 * @see src/keygen.hpp para documentação completa das funções
 */

#include "permutation.hpp"

/**
 * @brief Deslocamento circular
 */
int deslocamento_circular(int n, int tamanho, int shift){
    return ((n<<shift) | ((n>>(tamanho - shift)) & ((1 << shift)-1))) & ((1<<tamanho)-1);
}

/**
 * @brief Geração de subchaves com logs detalhados
 * @debug Mostra todas as etapas do processo quando imprimir=true:
 * - Permutação P10
 * - Deslocamentos circulares
 * - Permutações P8
 * - Resultados intermediários
 */
void gerarChaves(int chave, int &k1, int &k2){
    
    if(imprimir){
        cout << "\n====================== Geração de Subchaves =====================\n\n";
        cout << "Chave inicial (10 bits):          " << toBin(chave, 10) << endl;

    }

    //definindo valores para geracao das chaves
    int permutacao = permuta(chave, p10);
    int esquerda = (permutacao>>5);
    int direita = (permutacao);

    //criacao de k1
    esquerda = deslocamento_circular(esquerda, 5, 1);
    direita = deslocamento_circular(direita, 5 , 1);
    k1 = permuta((esquerda << 5) | direita, p8);
    if(imprimir){
        cout << "\n--- Etapas para gerar K1 ---\n";
        cout << "Permutação P10:                   " << toBin(permutacao, 10) << endl;
        cout << "Deslocamento circular (1x):       " << toBin((esquerda << 5) | direita, 10) << endl;
        cout << "Permutação P8 → K1:               " << toBin(k1, 8) << endl;
    }
    

    //criacao de k2
    esquerda = deslocamento_circular(esquerda, 5, 2);
    direita = deslocamento_circular(direita, 5 , 2);
    k2 = permuta((esquerda << 5) | direita, p8);
    if(imprimir){
        cout << "\n\n--- Etapas para gerar K2 ---\n";
        cout << "Deslocamento circular (2x):       " << toBin((esquerda << 5) | direita, 10) << endl;
        cout << "Permutação P8 → K2:               " <<  toBin(k2, 8) << endl;
        cout << "\n\n----------------- Resultado Final das Subchaves -----------------\n\n";
        cout << "K1:                              " << toBin(k1, 8) << endl;
        cout << "K2:                              " << toBin(k2, 8) << endl;
        cout << "\n================================================================\n";
    }
}