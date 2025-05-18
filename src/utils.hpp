/**
 * @file Utils.hpp
 * @brief Utilitários para manipulação de bits, conversões e processamento de mensagens para o algoritmo S-DES
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @var bool imprimir
 * @brief Flag para controle de impressão passo a passo (true = ativa saída detalhada)
 */
bool imprimir=false;

/**
 * @var int encriptar
 * @brief Modo de operação (2 = encriptar, 1 = decriptar)
 */
int encriptar=2;

/**
 * @brief Converte um inteiro para sua representação binária em string
 * @param n Número inteiro a ser convertido
 * @param sz Tamanho (em bits) da saída desejada
 * @return string Representação binária com exatamente 'sz' caracteres ('0' ou '1')
 * @pre sz deve ser maior que 0 e suficiente para representar 'n'
 * @example 
 *   toBin(5, 4) retorna "0101"
 */
string toBin(int n, int sz){
    string bits = "";
    for(int i=sz-1; i >= 0; i--){
        bits += (char)(((n >> i) & 1) + '0');
    } 
    return bits;
}

/**
 * @brief Converte uma string binária para número inteiro
 * @param bits String contendo apenas '0's e '1's
 * @param sz Número de bits a serem considerados na conversão
 * @return int Valor inteiro correspondente
 * @pre bits deve conter apenas '0's e '1's 
 * @pre bits.length() >= sz
 * @example
 *   toInt("0101", 4) retorna 5
 */
int toInt(string bits, int sz){
    int num=0;
    for(int i=sz-1, j=0; i >= 0; i--, j++){
        if(bits[i] == '1') num |= (1 << j);
    } 
    return num;
}

/**
 * @brief Divide uma mensagem binária em blocos de 8 bits
 * @param mensagem String contendo a mensagem binária completa
 * @return vector<string> Vetor de strings onde cada elemento tem 8 caracteres binários
 * @return vector<string> Vetor vazio se o comprimento da mensagem não for múltiplo de 8
 * @pre mensagem deve conter apenas '0's e '1's
 * @post Cada elemento do vetor retornado terá tamanho exatamente 8
 * @example
 *   separaMensagem("0101010101010101") retorna ["01010101", "01010101"]
 */
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