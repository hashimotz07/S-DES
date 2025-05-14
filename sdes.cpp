#include <bits/stdc++.h>

using namespace std;

/*permuta*/
int permuta(int n, vector<int> &v){
    int resultado = 0, total_bits = 10;
    for(int i = 0; i < v.size(); i++){
        resultado = resultado << 1;
        resultado |= (n >> (total_bits - v[i])) & 1;
    }
    return resultado;
}

/*deslocamento circular*/
int deslocamento_circular(int n, int tamanho, int shift){
    return ((n<<shift) | (n>>(tamanho - shift))) & ((1<<tamanho)-1);
}

/*geração de chaves subjacentes*/
void gerarChaves(int chave, int &k1, int &k2){
    vector<int> p10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    vector<int> p8  = {6, 3, 7, 4, 8, 5, 10, 9};

    //definindo valores para geracao das chaves
    int permutacao = permuta(chave, p10);
    int esquerda = (permutacao>>5);
    int direita = (permutacao);

    //criacao de k1
    esquerda = deslocamento_circular(esquerda, 5, 1);
    direita = deslocamento_circular(direita, 5 , 1);
    k1 = permuta((esquerda << 5) | direita, p8);


    //criacao de k2
    esquerda = deslocamento_circular(esquerda, 5, 2);
    direita = deslocamento_circular(direita, 5 , 2);
    k2 = permuta((esquerda << 5) | direita, p8);
}

int main(){
    int chave = 1010000010; //chave de 10 bits
    int dado = 11010111; //bloco de dados de 8 bits




    return 0;
}