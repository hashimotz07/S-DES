/**
 * @file modes.hpp
 * @brief Versão debug das implementações dos modos ECB e CBC - Para documentação completa, consulte src/modes.hpp
 * @note Esta versão contém:
 * - Cabeçalhos de operação formatados
 * - Logs detalhados para cada bloco, quando `imprimir` está ativado
 * 
 * @see src/modes.hpp para documentação completa das funções
 */

#include "encrypt.hpp"

/**
 * @brief Imprime cabeçalho formatado para os modos ECB/CBC
 * @debug Exibe estrutura visual da operação por bloco, de acordo com o modo e tipo
 */
void imprimirCabecalho(vector<string>& mensagem, string tipo, string modo, string chave, string IV=""){
    cout << "\n======================= Modo " << modo << " ========================\n\n";
    cout << "Operação: " << tipo << "\n";
    if(tipo == "Encriptação") cout << "Plaintext: ";
    else cout << "Ciphertext: ";
    for(string bloco : mensagem) cout << bloco << " ";
    cout << endl;
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
            cout << "\n----------------------------------------------------------------------------\n";
            cout << "| Bloco # | Entrada  | Decifrado S-DES | XOR com IV/prev | Saída plaintext |\n";
            cout << "----------------------------------------------------------------------------\n";
        }
    }
}


/**
 * @brief Encriptação no modo ECB
 * @debug Mostra entrada/saída de cada bloco
 */
string ECB_encripta(vector<string>& plainText, int chave){
    bool imprimiLocal=imprimir; 
    imprimir=false;
    if(imprimiLocal) imprimirCabecalho(plainText, "Encriptação", "ECB", toBin(chave, 10));
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


/**
 * @brief Decriptação no modo ECB
 * @debug Mostra entrada/saída de cada bloco
 */
string ECB_decripta(vector<string>& cipherText, int chave){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho(cipherText, "Decriptação", "ECB", toBin(chave, 10));
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

/**
 * @brief Encriptação no modo CBC
 * @debug Mostra XOR com IV/anterior e resultado cifrado
 */
string CBC_encripta(vector<string>& plainText, int chave, int IV){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho(plainText, "Encriptação", "CBC", toBin(chave, 10), toBin(IV, 8));
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

/**
 * @brief Decriptação no modo CBC
 * @debug Mostra resultado do S-DES e XOR com IV/anterior
 */
string CBC_decripta(vector<string> cipherText, int chave, int IV){
    bool imprimiLocal = imprimir;
    imprimir = false;
    if(imprimiLocal) imprimirCabecalho(cipherText, "Decriptação", "CBC", toBin(chave, 10), toBin(IV, 8));
    int last, atual, bloco;
    string plainText="";
    last = IV;
    for(int i=0; i < (int)cipherText.size(); i++){
        atual = toInt(cipherText[i], 8);
        bloco = decriptacao(atual, chave);
        if(imprimiLocal) cout << "|   " << i+1 << "     | " << cipherText[i] << " |    " << toBin(bloco, 8) << "     |  ⊕ " << toBin(last, 8);
        bloco ^= last;
        last = atual;
        if(imprimiLocal) cout << "     |     " << toBin(bloco, 8) << "    |\n";
        plainText += toBin(bloco, 8) + " ";
    }
    if(imprimiLocal) cout << "-----------------------------------------------------------------\n";
    return plainText;
} 