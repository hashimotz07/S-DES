#include "encriptDecript.hpp"

int main(){
    int chave = 642;
    int bloco = 215;

    cout << encriptacao(bloco, chave) << endl;
    cout << decriptacao(encriptacao(bloco, chave), chave) << endl;
}