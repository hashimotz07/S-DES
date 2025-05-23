/**
 * @file input.hpp
 * @brief Entrada interativa para testes de encriptação S-DES com logs - - Para documentação completa, consulte src/input.hpp
 * @note Esta versão recebe entradas com valores padrão e leitura manual
 * @debug Ativa logs de geração de chaves, blocos e mensagens se `imprimir` estiver ativo
 * 
 * @see src/input.hpp para documentação completa das funções
 */

#include "modes.hpp"

/**
 * @brief Lê uma chave de 10 bits do usuário ou usa padrão
 * @return Chave convertida para inteiro
 * @debug Mostra mensagens de validação interativa
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
 * @brief Lê um bloco de 8 bits do usuário ou usa padrão
 * @return Bloco convertido para inteiro
 * @debug Mostra mensagens de validação interativa
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
 * @brief Lê uma mensagem (múltiplos de 8 bits) do usuário ou usa padrão
 * @return Vetor com blocos de 8 bits
 * @debug Mostra mensagens de validação interativa
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
 * @brief Lê o vetor de inicialização (IV) de 8 bits ou usa padrão
 * @return IV convertido para inteiro
 * @debug Mostra mensagens de validação interativa
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
 * @brief Testa geração de subchaves K1 e K2 a partir de uma chave
 * @debug Ativa logs de geração e permutação
 */
void testarGeracaoDeChave() {
    int chave = lerChave();
    int K1, K2;
    imprimir = true;
    gerarChaves(chave, K1, K2);
}

/**
 * @brief Testa a cifragem ou decifragem de um único bloco
 * @debug Permite escolha entre execução passo a passo ou direta
 */
void testarBloco() {
    int chave = lerChave();
    int bloco = lerBloco();
    int modo, mostrarPasso;

    cout << "\n1 - Encriptar\n2 - Decriptar\nEscolha a operação: ";
    cin >> modo;
    cout << "\n1 - Passo a passo\n2 - Apenas resposta\nEscolha a forma de saída: ";
    cin >> mostrarPasso;
    imprimir = mostrarPasso&1;

    int resultado;
    if (modo == 1)
        resultado = encriptacao(bloco, chave);
    else
        resultado = decriptacao(bloco, chave);

    cout << "\n====================== Resultado Final =========================\n\n";
    cout << "  Cifra:               " << toBin(resultado, 8) << endl;
    cout << "\n===============================================================\n";
}

/**
 * @brief Testa a cifragem/decifragem completa de uma mensagem
 * @debug Suporta modos ECB e CBC com logs detalhados por bloco
 */
void testarMensagem() {
    int modoCifra, operacao, mostrarPasso, IV;

    int chave = lerChave();
    vector<string> mensagem = lerMenssagem();
    
    cout << "1 - ECB\n2 - CBC\nEscolha o modo de operação: ";
    cin >> modoCifra;

    if (modoCifra == 2) {
        IV = lerIV();
    }

    cout << "\n1 - Encriptar\n2 - Decriptar\nEscolha a operação: ";
    cin >> operacao;
    cout << "\n1 - Passo a passo\n2 - Apenas resposta\nEscolha a forma de saída: ";
    cin >> mostrarPasso;
    imprimir = mostrarPasso&1;

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