#include "geradorChave.hpp"
#include "funcoes.hpp"

int encriptacao(int n, int k){
    int k1, k2;
    gerarChaves(k, k1, k2);

    n = permutacaoInicial(n);
    cout << "Permutação inicial: " << n << endl;
    auto [l, r] = dividi(n);
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