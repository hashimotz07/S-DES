#include "permutacao.hpp"

/*deslocamento circular*/
int deslocamento_circular(int n, int tamanho, int shift){
    return ((n<<shift) | (n>>(tamanho - shift))) & ((1<<tamanho)-1);
}

/*geração de chaves subjacentes*/
void gerarChaves(int chave, int &k1, int &k2){

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