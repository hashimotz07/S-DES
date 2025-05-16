#include "encrypt.hpp"

string ECB_encripta(vector<string>& plainText, int chave){
    string cipherText="";
    for(string blocoS : plainText){
        int bloco = toInt(blocoS, 8);
        cipherText += toBin(encriptacao(bloco, chave), 8);
    }
    return cipherText;
}

string ECB_decripta(vector<string>& cipherText, int chave){
    string plainText="";
    for(string blocoS : cipherText){
        int bloco = toInt(blocoS, 8);
        plainText += toBin(decriptacao(bloco, chave), 8);
    }
    return plainText;
}

string CBC_encripta(vector<string>& plainText, int chave, int IV){
    string cipherText="";
    int last;
    for(string blocoS : plainText){
        last = toInt(blocoS, 8) ^ last;
        last = encriptacao(last, chave);
        cipherText += toBin(last, 8);
    }
    return cipherText;
} 

string CBC_decripta(vector<string> cipherText, int chave, int IV){
    cipherText.insert(cipherText.begin(), toBin(IV, 8));
    int next, atual;
    vector<int> plainReverso;
    int i = (int)cipherText.size()-1;
    atual = toInt(cipherText[i], 8);
    for(--i ; i >= 0; i--){
        next = toInt(cipherText[i], 8);
        atual = decriptacao(atual, chave) ^ next;
        atual = next;
    }
    string plainText="";
    for(i = (int)plainReverso.size()-1; i >= 0; i--){
        plainText += toBin(plainReverso[i], 8);
    }
    return plainText;
} 