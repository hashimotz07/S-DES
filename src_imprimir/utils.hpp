/**
 * @file utils.hpp
 * @brief Versão com logs de debug - Para documentação completa, consulte src/utils.hpp
 * @note Esta versão contém implementações idênticas às origens, mas com:
 * - Flags de controle de impressão (imprimir, encriptar)
 * - Logs detalhados do processo interno
 * 
 * @see src/utils.hpp para documentação completa das funções
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @var imprimir
 * @brief Ativa/desativa logs detalhados (false=off, true=on)
 */
bool imprimir=false;


/**
 * @var encriptar
 * @brief Controla modo de operação (1=decriptação, 2=encriptação)
 */
int encriptar=2;

/// converte o numero inteiro para binario(string); 
/// Para documentação completa, ver src/utils.hpp
string toBin(int n, int sz){
    string bits = "";
    for(int i=sz-1; i >= 0; i--){
        bits += (char)(((n >> i) & 1) + '0');
    } 
    return bits;
}

/// converte o numero binario(string) para inteiro; 
/// Para documentação completa, ver src/utils.hpp
int toInt(string bits, int sz){
    int num=0;
    for(int i=sz-1, j=0; i >= 0; i--, j++){
        if(bits[i] == '1') num |= (1 << j);
    } 
    return num;
}

/// separa os blocos de uma mensagem em um vetor; 
/// retorna uma lista vazia se a mensagem não tiver tamanho multiplo de 8
vector<string> separaMensagem(string& mensagem){
    vector<string> newMensagem;
    string bloco="";
    for(char c : mensagem){
        if(c == '0' || c == '1') bloco += c;
        if((int)bloco.size() == 8){
            newMensagem.push_back(bloco);
            bloco = "";
        }
    }
    if((int)bloco.size()) return {};
    return newMensagem;
}