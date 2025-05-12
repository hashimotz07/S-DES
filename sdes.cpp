#include <bits/stdc++.h>
#define inacio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/*permuta*/
int permuta(int n, vector<int> v, int total_bits){
    int resultado = 0;
    for(int i = 0; i < v.size(); i++){
        resultado = resultado << 1;
        resultado |= (n >> (total_bits - v[i])) & 1;
    }
    return resultado;
}

/*deslocamento circular*/
int deslocamento_circular(int n, int tamanho, int shift){
    return ((n>>shift) | (n>>(tamanho - shift))) & ((1<<tamanho)-1);
}

int main(){
    inacio;
    int chave = 1010000010; //chave de 10 bits
    int dado = 11010111; //bloco de dados de 8 bits

    /*geração de chaves subjacentes*/



    return 0;
}