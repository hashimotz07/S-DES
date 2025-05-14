#include "funcoes.hpp"

int encriptacao(int n, int k){
    int k1, k2;
    cout << "Geração de chave:\n\nChave inicial: " << toBin(k, 10) << endl;
    gerarChaves(k, k1, k2);
    
    cout << "\n\nEncriptação:\n\nBloco inicial: " << toBin(n, 8) << endl;

    n = permutacaoInicial(n);
    cout << "Permutação inicial: " << toBin(n, 8) << endl;
    auto [l, r] = dividi(n);
    cout << "l : " << toBin(l, 4) << " , r : " << toBin(r, 4) << endl;
    n = feistel(l, r, k1, k2);
    cout << n << endl;
    return  permutacaoFinal(n);
}

int decriptacao(int n, int k){
    int k1, k2;
    gerarChaves(k, k1, k2);

    n = permutacaoInicial(n);
    auto [l, r] = dividi(n);
    n = feistel(l, r, k2, k1);
    return permutacaoFinal(n);
}