/**
 * @file encrypt.hpp
 * @brief Versão com logs de debug - Para documentação completa, consulte src/encrypt.hpp
 * @note Esta versão contém implementações idênticas às origens, mas com:
 * - Flags de controle de impressão (imprimir, encriptar)
 * - Logs detalhados do processo interno
 * 
 * @see src/encrypt.hpp para documentação completa das funções
 */

#include "ffunction.hpp"

/**
 * @brief Realiza encriptação ou decriptação com base na flag `encriptar`
 * @debug Mostra:
 * - Permutações iniciais/finais
 * - Subchaves geradas
 * - Resultado das rodadas Feistel
 */
int encriptacao(int n, int k){
    int k1, k2;
    bool imprimiPausa = imprimir;
    imprimir = false;
    gerarChaves(k, k1, k2);
    imprimir = imprimiPausa;
    if(encriptar&1) swap(k1, k2);
    
    if(imprimir){
        cout << "\n====================== S-DES - " << (encriptar&1 ? "Decriptação" : "Encriptação")  << " ======================\n\n";
        cout << "Bloco de entrada:      " << toBin(n, 8) << endl;
        cout << "Chave de 10 bits:      " << toBin(k, 10) << endl;
        cout << "\nSubchaves geradas:\n";
        cout << "  K1 = " << toBin(k1, 8) << endl;
        cout << "  K2 = " << toBin(k2, 8) << endl;
        cout << "\n---------------------------------------------------------------\n";
        cout << "[1] Permutação Inicial (IP)\n\n";
        cout << "  Entrada:             " << toBin(n, 8) << endl;
    }

    n = permutacaoInicial(n);
    auto [l, r] = dividi(n);
    if(imprimir){
        cout << "  Após IP:             " << toBin(n, 8) << endl;
        cout << "\n---------------------------------------------------------------\n";
        cout << "[2] Divisão em metades\n\n";
        cout << "  L (4 bits):          " << toBin(l, 4) << endl;
        cout << "  R (4 bits):          " << toBin(r, 4) << endl;
        cout << "\n---------------------------------------------------------------\n";
        cout << "[3] Rodadas de Feistel\n\n";
    }
    n = feistel(l, r, k1, k2);
    if(imprimir){
        cout << "\n---------------------------------------------------------------\n";
        cout << "[4]  Permutação Final (IP⁻¹)\n\n";
        cout << "  Entrada:             " << toBin(n, 8) << endl;
    }
    n = permutacaoFinal(n);
    
    if(imprimir)
        cout << "  Saída cifrada:       " << toBin(n, 8) << endl;
    
    return n;
}

/**
 * @brief Wrapper para decriptação usando `encriptacao` com flag apropriada
 */
int decriptacao(int n, int k){
    encriptar = 1;
    n = encriptacao(n, k);
    encriptar = 2;
    return n;
}