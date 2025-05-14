#include "encriptDecript.hpp"

int main(){
    int chave = toInt("1010000010", 10);
    int bloco = toInt("11010111", 8);

    string bitt=  toBin(encriptacao(bloco, chave), 8);
    cout << "cypherText : " << bitt << endl;
    // cout << decriptacao(encriptacao(bloco, chave), chave) << endl;
}