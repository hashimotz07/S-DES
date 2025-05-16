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
    if(imprimir)
        cout << "    S" << s[0][0] << "(" << toBin(linha, 2) << toBin(coluna, 2) << ") -> " << toBin(s[linha][coluna], 2) << endl;

    return s[linha][coluna];
}

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

int feistel(int l, int r, int k1, int k2){
    if(imprimir) cout << "\n=> Primeira Rodada (com K" << (encriptar^3) << ")\n\n";
    l = f(l, r, k1);
    if(imprimir){
        cout << "\n  Resultado da rodada:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
    }
    swap(l, r);
    encriptar ^= 3;
    if(imprimir){
        cout << "\n-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -\n";
        cout << "  Após troca:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
        cout << "\n-  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -\n";
    if(imprimir) cout << "\n=> Segunda Rodada (com K" << (encriptar^3) << ")\n\n";
    }
    l = f(l, r, k2);
    if(imprimir){
        cout << "\n  Resultado final da rodada:\n";
        cout << "    L =                " << toBin(l, 4) << endl;
        cout << "    R =                " << toBin(r, 4) << endl;
    }
    return ((l << 4) | r);
}