#include "keygen.hpp"

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
    int linha = ((n & 8) >> 2) | (n & 1);
    int coluna = ((n & 4) >> 1) | ((n & 2) >> 1);

    return s[linha][coluna];
}

int F(int n, int k){
    n = permuta(n, ep, 4);
    n ^= k;
    int l = s_box(n >> 4, s0);
    int r = s_box(n, s1);
    n = permuta(((l << 2) | r), p4, 4);
    return n;
}

int f(int l, int r, int k){
    int ans = F(r, k) ^ l;
    return ans;
}

int feistel(int l, int r, int k1, int k2){
    l = f(l, r, k1);
    swap(l, r);
    encriptar ^= 3;
    l = f(l, r, k2);
    return ((l << 4) | r);
}