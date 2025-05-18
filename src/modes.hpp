/**
 * @file modes.hpp
 * @brief Implementação dos modos de operação ECB e CBC para o S-DES
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */

#include "encrypt.hpp"

/**
 * @brief Encripta plaintext usando o modo ECB (Electronic Codebook)
 * @param plainText Vetor de strings binárias (blocos de 8 bits)
 * @param chave Chave mestra de 10 bits (0-1023)
 * @return string Texto cifrado concatenado
 * 
 * @pre Cada string em plainText deve ter tamanho 8 e conter apenas '0's e '1's
 * @pre chave deve ser um valor de 10 bits válido
 * @post O resultado terá tamanho plainText.size() * 8
 * 
 * @note Características do ECB:
 * - Blocos idênticos produzem saídas idênticas
 * - Não usa vetor de inicialização (IV)
 * - Paralelizável
 */
string ECB_encripta(vector<string>& plainText, int chave){
    string cipherText="";
    for(string blocoS : plainText){
        int bloco = toInt(blocoS, 8);
        cipherText += toBin(encriptacao(bloco, chave), 8);
    }
    return cipherText;
}

/**
 * @brief Decripta texto cifrado usando modo ECB
 * @param cipherText Vetor de strings binárias (blocos cifrados de 8 bits)
 * @param chave Chave mestra de 10 bits usada na encriptação
 * @return string Texto plano reconstruído
 * 
 * @see ECB_encripta() para pré-condições
 */
string ECB_decripta(vector<string>& cipherText, int chave){
    string plainText="";
    for(string blocoS : cipherText){
        int bloco = toInt(blocoS, 8);
        plainText += toBin(decriptacao(bloco, chave), 8);
    }
    return plainText;
}

/**
 * @brief Encripta texto plano usando modo CBC (Cipher Block Chaining)
 * @param plainText Vetor de strings binárias (blocos de 8 bits)
 * @param chave Chave mestra de 10 bits (0-1023)
 * @param IV Vetor de inicialização (8 bits) para o primeiro bloco
 * @return string Texto cifrado concatenado
 * 
 * @pre IV deve ser valor de 8 bits (0-255)
 * @note Características do CBC:
 * - Blocos idênticos produzem saídas diferentes
 * - Propagação de erros entre blocos
 * - Requer IV único por encriptação
 */
string CBC_encripta(vector<string>& plainText, int chave, int IV){
    string cipherText="";
    int last = IV;
    for(string blocoS : plainText){
        last = toInt(blocoS, 8) ^ last;
        last = encriptacao(last, chave);
        cipherText += toBin(last, 8);
    }
    return cipherText;
} 


/**
 * @brief Decripta texto cifrado usando modo CBC
 * @param cipherText Vetor de strings binárias (blocos cifrados de 8 bits)
 * @param chave Chave mestra de 10 bits usada na encriptação
 * @param IV Mesmo vetor de inicialização usado na encriptação
 * @return string Texto plano reconstruído
 * 
 * @warning O IV deve ser o mesmo usado na encriptação
 * @note Processo:
 * 1. Salva o bloco atual na variavel atual
 * 2. Decripta o bloco atual
 * 3. Aplica XOR com bloco anterior cifrado (last)
 * 4. Subtitui last por atual
 */
string CBC_decripta(vector<string> cipherText, int chave, int IV){
    int last, atual, bloco;
    string plainText="";
    last = IV;
    for(int i=0; i < (int)cipherText.size(); i++){
        atual = toInt(cipherText[i], 8);
        bloco = decriptacao(atual, chave) ^ last;
        last = atual;
        plainText += toBin(bloco, 8) + " ";
    }
    return plainText;
} 