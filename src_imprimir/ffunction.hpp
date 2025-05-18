/**
 * @file ffunction.hpp
 * @brief Versão debug da função Feistel - Documentação completa em src/ffunction.hpp
 * @note Contém logs detalhados de cada etapa do processo
 * @see src/ffunction.hpp para documentação completa das funções
 */

#include "keygen.hpp"

/**
 * @brief Aplica permutação inicial (IP)
 */
int permutacaoInicial(int n){
    return permuta(n, ip, 8);
}

/**
 * @brief Aplica permutação final (IP⁻¹)
 */
int permutacaoFinal(int n){
    return permuta(n, ipi, 8);
}


/**
 * @brief Divide bloco de 8 bits em dois de 4 bits
 */
pair<int, int> dividi(int n){
    int l = n >> 4;
    int r = n & ((1 << 4) - 1);
    return make_pair(l, r);
}


/**
 * @brief Aplica S-Box com log detalhado
 * @debug Mostra seleção de linha/coluna e resultado
 */
int s_box(int n, vector<vector<int>>& s){
    int linha = ((n & 8) >> 2) | (n & 1);
    int coluna = ((n & 4) >> 1) | ((n & 2) >> 1);
    if(imprimir)
        cout << "    S" << !(s[0][0]) << "(" << toBin(linha, 2) << toBin(coluna, 2) << ") -> " << toBin(s[linha][coluna], 2) << endl;

    return s[linha][coluna];
}

/**
 * @brief Função F da rede Feistel com logs
 * @debug Mostra todas as etapas:
 * - Expansão/Permutação
 * - XOR com subchave
 * - Processamento nas S-Boxes
 * - Permutação P4
 */
int F(int n, int k){
    n = permuta(n, ep, 4);
    if(imprimir){
        cout << "    E/P(R):            " << toBin(n, 8) << "\n\n";
        cout << "  XOR com K" << (encriptar^3) << ":\n";
        cout << "    K" << (encriptar^3) << ":                " << toBin(k, 8) << endl;
    }
    n ^= k;

    if(imprimir){
        cout << "    Resultado:         " << toBin((n^k), 8) << endl;
        cout << "\n  S-Boxes:\n";
    }

    int l = s_box(n >> 4, s0);
    int r = s_box(n, s1);

    n = permuta(((l << 2) | r), p4, 4);

    if(imprimir){
        cout << "    Saída:             " << toBin(l, 2) << toBin(r, 2) << endl;
        cout << "    P4:                " << toBin(n, 4) << endl;
    }
    return n;
}

/**
 * @brief Rodada Feistel com logs
 * @debug Mostra:
 * - Expansão de R
 * - Resultado da função F
 * - XOR com L
 */
int f(int l, int r, int k){
    if(imprimir){
        cout << "  Expansão/Permutação de R:\n";
        cout << "    R =                " << toBin(r, 4) << endl;
    }

    int ans = F(r, k) ^ l;

    if(imprimir){
        cout << "\n  XOR com L:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    L ⊕ F =            " << toBin(ans, 4) << endl;
    }
    return ans;
}

/**
 * @brief Rede Feistel completa (2 rodadas) com logs detalhados
 * @debug Mostra:
 * - Processamento de cada rodada
 * - Troca de blocos
 * - Resultados intermediários
 */
int feistel(int l, int r, int k1, int k2){
    if(imprimir) cout << "\n=> Primeira Rodada (com K" << (encriptar^3) << ")\n\n";
    l = f(l, r, k1);
    if(imprimir){
        cout << "\n  Resultado da rodada:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
    }
    swap(l, r);
    encriptar ^= 3;   // alterna entre encriptar/decriptar (1 XOR 3 = 2, 2 XOR 3 = 1)
    if(imprimir){
        cout << "\n-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -\n";
        cout << "  Após troca:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
        cout << "\n-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -\n";
        cout << "\n=> Segunda Rodada (com K" << (encriptar^3) << ")\n\n";
    }
    l = f(l, r, k2);
    if(imprimir){
        cout << "\n  Resultado final da rodada:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
    }
    return ((l << 4) | r);
}