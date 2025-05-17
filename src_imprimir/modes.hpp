#include "encrypt.hpp"

void imprimirCabecalho(string tipo, string modo, string chave, string IV=""){
    cout << "\n======================= Modo " << modo << " ========================\n\n";
    cout << "Operação: " << tipo << "\n";
    cout << "Chave usada: " << chave << endl;
    if(modo == "ECB"){
            cout << "\n---------------------------------------------------------\n";
        if(tipo == "Encriptação") cout << "| Bloco # | Entrada (plaintext) |    Saída (cifrado)    |\n";
        else cout << "| Bloco # |  Entrada (cifrado)  |   Saída (plaintext)   |\n";
        cout << "---------------------------------------------------------\n";
    }
    else{
        cout << "IV inicial:  " << IV << endl;
        if(tipo == "Encriptação"){ 
            cout << "\n---------------------------------------------------------------------\n";
            cout << "| Bloco # |  Entrada XOR Prev   | Entrada pós XOR  | Saída (8 bits) |\n";
            cout << "---------------------------------------------------------------------\n";
        }
        else{ 
            cout << "\n-----------------------------------------------------------------\n";
            cout << "| Bloco # | Decifrado S-DES | XOR com IV/prev | Saída plaintext |\n";
            cout << "-----------------------------------------------------------------\n";
        }
    }
}

string ECB_encripta(vector<string>& plainText, int chave){
    bool imprimiLocal=imprimir; 
    imprimir=false;
    if(imprimiLocal) imprimirCabecalho("Encriptação", "ECB", toBin(chave, 10));
    string cipherText="";
    int i=1;
    for(string blocoS : plainText){
        int bloco = toInt(blocoS, 8);
        if(imprimiLocal) cout << "|   " << i++ << "     |      " << blocoS << "       |       ";
        bloco = encriptacao(bloco, chave);
        if(imprimiLocal) cout << toBin(bloco, 8) << "        |\n";
        cipherText += toBin(bloco, 8) + " ";

    }
    if(imprimiLocal) cout << "---------------------------------------------------------\n";
    return cipherText;
}

string ECB_decripta(vector<string>& cipherText, int chave){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho("Decriptação", "ECB", toBin(chave, 10));
    string plainText="";
    int i=1;
    for(string blocoS : cipherText){
        int bloco = toInt(blocoS, 8);
        if(imprimiLocal) cout << "|   " << i++ << "     |      " << blocoS << "       |       ";
        bloco = decriptacao(bloco, chave);
        if(imprimiLocal) cout << toBin(bloco, 8) << "        |\n";
        plainText += toBin(bloco, 8) + " ";
    }
    if(imprimiLocal) cout << "---------------------------------------------------------\n";
    return plainText;
}

string CBC_encripta(vector<string>& plainText, int chave, int IV){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho("Encriptação", "CBC", toBin(chave, 10), toBin(IV, 8));
    string cipherText="";
    int last=IV, i=1;
    for(string blocoS : plainText){
        if(imprimiLocal) cout << "|   " << i++ << "     | " << blocoS << " ⊕ " << toBin(last, 8) << " |    ";
        last = toInt(blocoS, 8) ^ last;
        if(imprimiLocal) cout << toBin(last, 8) << "      |    ";
        last = encriptacao(last, chave);
        if(imprimiLocal) cout << toBin(last, 8) << "    |\n";
        cipherText += toBin(last, 8) + " ";
    }
    if(imprimiLocal) cout << "---------------------------------------------------------------------\n";
    return cipherText;
} 

string CBC_decripta(vector<string> cipherText, int chave, int IV){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho("Decriptação", "CBC", toBin(chave, 10), toBin(IV, 8));
    cipherText.insert(cipherText.begin(), toBin(IV, 8));
    int last, atual, bloco;
    string plainText="";
    last = toInt(cipherText[0], 8);
    for(int i=1; i < (int)cipherText.size(); i++){
        if(imprimiLocal) cout << "|   " << i << "     |    " << cipherText[i] << "     |  ⊕ " << toBin(last, 8);
        atual = toInt(cipherText[i], 8);
        bloco = decriptacao(atual, chave) ^ last;
        atual = last;
        if(imprimiLocal) cout << "     |     " << toBin(bloco, 8) << "    |\n";
        plainText += toBin(bloco, 8) + " ";
    }
    if(imprimiLocal) cout << "-----------------------------------------------------------------\n";
    return plainText;
} 