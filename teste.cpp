#include "encriptDecript.hpp"

int main(){
    int chave = toInt("1010000010", 10);
    int bloco = toInt("01110010", 8);

    cout <<toBin(encriptacao(bloco, chave), 8) << endl;
    cout << decriptacao(encriptacao(bloco, chave), chave) << endl;
}