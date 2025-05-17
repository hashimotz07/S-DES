#include "ffunction.hpp"

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

int decriptacao(int n, int k){
    encriptar = 1;
    n = encriptacao(n, k);
    encriptar = 2;
    return n;
}