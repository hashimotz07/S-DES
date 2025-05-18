/**
 * @file input.hpp
 * @brief Menus interativos para teste do algoritmo S-DES
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 * 
 * @note Contém quatro modos de teste:
 * 1. Geração de chaves
 * 2. Operação em bloco único
 * 3. Operação em mensagem completa (ECB/CBC)
 * 4. Validação de entradas do usuário
 */


#include "modes.hpp"

/**
 * @brief Solicita ao usuário uma chave de 10 bits
 * @return int Chave convertida para inteiro
 * 
 * @details
 * - Oferece opção de usar chave padrão (1010000010)
 * - Valida o tamanho da entrada (exatamente 10 bits)
 * - Converte string binária para inteiro
 * 
 * @warning Não valida caracteres inválidos (apenas tamanho)
 */
int lerChave(){
    string chave10 = "1010000010"; // chave padrão
    cout << "Deseja usar a chave padrão (1010000010)? (s/n): ";
    char usarPadrao;
    cin >> usarPadrao;
    if (usarPadrao == 'n' || usarPadrao == 'N') {
        while(true){
            cout << "Digite a nova chave de 10 bits: ";
            cin >> chave10;
            if((int)chave10.size() == 10) break;
            cout << "Chave incompatível com os padrões. Tente novamente!\n\n";
        }
    }
    return toInt(chave10, 10);
}


/**
 * @brief Solicita ao usuário um bloco de 8 bits
 * @return int Bloco convertido para inteiro
 * 
 * @details
 * - Oferece bloco padrão (11010111)
 * - Valida tamanho exato de 8 bits
 * 
 * @see lerChave() para lógica similar
 */
int lerBloco(){
    string bloco = "11010111";
    cout << "Deseja usar o bloco padrão (11010111)? (s/n): ";
    char usarPadrao;
    cin >> usarPadrao;
    if (usarPadrao == 'n' || usarPadrao == 'N') {
        while(true){
            cout << "Digite um bloco de 8 bits: ";
            cin >> bloco;
            if((int)bloco.size() == 8) break;
            cout << "Bloco incompatível com os padrões. Tente novamente!\n\n";
        }
    }
    return toInt(bloco, 8);
}

/**
 * @brief Solicita mensagem com tamanho múltiplo de 8 bits
 * @return vector<string> Vetor de blocos de 8 bits
 * 
 * @details
 * - Aceita espaços entre blocos (ex: "11010111 01101100")
 * - Remove espaços e valida tamanho total
 * - Mensagem padrão: "11010111 01101100 10111010 11110000"
 * 
 * @warning A entrada deve ter comprimento total múltiplo de 8
 */
vector<string> lerMenssagem(){
    string mensagemS = "11010111 01101100 10111010 11110000";
    vector<string> mensagemV = separaMensagem(mensagemS);
    cout << "Deseja usar a mensagem padrão (" << mensagemS <<")? (s/n): ";
    char usarPadrao;
    cin >> usarPadrao;
    if (usarPadrao == 'n' || usarPadrao == 'N') {
        while(true){
            cout << "Digite uma mensagem com tamanho multiplo de 8 bits:\n -> ";
            cin.ignore();
            getline(cin, mensagemS);
            mensagemV = separaMensagem(mensagemS);
            if(!mensagemV.empty()) break;
            cout << "Mensagem incompatível com os padrões. Tente novamente!\n\n";
        }
    }
    return mensagemV;
}

/**
 * @brief Solicita Vetor de Inicialização (IV) para CBC
 * @return int IV de 8 bits convertido para inteiro
 * 
 * @details
 * - IV padrão: 01010101 (0x55)
 * - Valida tamanho exato de 8 bits
 */
int lerIV(){
    string IVs = "01010101";
    cout << "Deseja usar o vetor de inicialização(IV) padrão (01010101)? (s/n): ";
    char usarPadrao;
    cin >> usarPadrao;
    if (usarPadrao == 'n' || usarPadrao == 'N') {
        while(true){
            cout << "Digite um IV de 8 bits: ";
            cin >> IVs;
            if((int)IVs.size() == 8) break;
            cout << "IV incompatível com os padrões. Tente novamente!\n\n";
        }
    }
    return toInt(IVs, 8);
}

/**
 * @brief Teste completo de geração de subchaves
 * 
 * @details
 * 1. Solicita chave mestra
 * 2. Gera e exibe K1 e K2
 * 
 * @see gerarChaves() em permutation.hpp
 */
void testarGeracaoDeChave() {
    int chave = lerChave();
    int K1, K2;
    gerarChaves(chave, K1, K2);
    cout << "\n\n----------------- Resultado Final das Subchaves -----------------\n\n";
    cout << "K1:                              " << toBin(K1, 8) << endl;
    cout << "K2:                              " << toBin(K2, 8) << endl;
    cout << "\n================================================================\n";
}

/**
 * @brief Teste de encriptação/decriptação de bloco único
 * 
 * @details Fluxo:
 * 1. Solicita chave e bloco
 * 2. Escolhe operação (1-encriptar/2-decriptar)
 * 3. Exibe resultado formatado
 */
void testarBloco() {
    int chave = lerChave();
    int bloco = lerBloco();
    int modo;

    cout << "\n1 - Encriptar\n2 - Decriptar\nEscolha a operação: ";
    cin >> modo;

    int resultado;
    if (modo == 1){
        encriptar = 2;
        resultado = encriptacao(bloco, chave);
    }
    else{
        encriptar = 1;
        resultado = decriptacao(bloco, chave);
    }

    cout << "\n====================== Resultado Final =========================\n\n";
    cout << "  Cifra:               " << toBin(resultado, 8) << endl;
    cout << "\n===============================================================\n";
}

/**
 * @brief Teste completo de mensagem (ECB/CBC)
 * 
 * @details Fluxo:
 * 1. Solicita chave e mensagem
 * 2. Escolhe modo (1-ECB/2-CBC)
 * 3. Se CBC, solicita IV
 * 4. Escolhe operação (encriptar/decriptar)
 * 5. Exibe resultado formatado
 */
void testarMensagem() {
    int modoCifra, operacao, IV;

    int chave = lerChave();
    vector<string> mensagem = lerMenssagem();
    
    cout << "1 - ECB\n2 - CBC\nEscolha o modo de operação: ";
    cin >> modoCifra;

    if (modoCifra == 2) {
        IV = lerIV();
    }

    cout << "\n1 - Encriptar\n2 - Decriptar\nEscolha a operação: ";
    cin >> operacao;

    string resultado;
    if (modoCifra == 1) {
        if (operacao == 1)
            resultado = ECB_encripta(mensagem, chave);
        else
            resultado = ECB_decripta(mensagem, chave);
    } else {
        if (operacao == 1)
            resultado = CBC_encripta(mensagem, chave, IV);
        else
            resultado = CBC_decripta(mensagem, chave, IV);
    }

    cout << "\n====================== Resultado Final =========================\n\n";
    cout << "   => " << resultado << endl;
    cout << "\n===============================================================\n";
}