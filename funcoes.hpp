#include "geradorChave.hpp"

int permutacaoInicial(int n){
    return permuta(n, ip, 8);
}

int permutacaoFinal(int n){
    return permuta(n, ipi, 8);
}

pair<int, int> dividi(int n){
    int l = n >> 4;
    int r = n & ((1 << 4) - 1);
    return make_pair(l, r);
}

int s_box(int n, vector<vector<int>>& s){
    int linha = ((n&1) << 1) | ((n >> 3) & 1);
    int coluna = (n & 2) | ((n >> 2) & 1);
    return s[linha][coluna];
}

int F(int n, int k){
    n = permuta(n, ep, 4) ^ k;
    int l = s_box(n >> 4, s0);
    int r = s_box(n, s1);
    return permuta(((l << 4) | r), p4);
}

int f(int l, int r, int k){
    return l ^ F(r, k);
}

int feistel(int l, int r, int k1, int k2){
    l = f(l, r, k1);
    swap(l, r);
    l = f(l, r, k2);
    return ((l << 4) | r);
}