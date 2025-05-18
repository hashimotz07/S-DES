/**
 * @file main.cpp
 * @brief Interface interativa principal para testes com o algoritmo S-DES
 * @note Esta versão fornece um menu para acessar testes com chave, bloco e mensagem
 * 
 * @see src/sdes.cpp para versão completa e estruturada para uso em produção
 * @debug Ativa logs dependendo das escolhas de saída feitas pelo usuário
 */
#include "input.hpp"

/**
 * @brief Função principal com menu interativo para testes com S-DES
 * 
 * Opções disponíveis:
 * - Gerar subchaves
 * - Cifrar/decifrar um bloco
 * - Cifrar/decifrar uma mensagem (ECB ou CBC)
 */
int main(){
    cout << "----------- S-DES ---------------\n\n";
    int opcao;
    while (true) {
        cout << "\n--------- MENU PRINCIPAL ---------\n";
        cout << "1 - Testar geração de subchaves\n";
        cout << "2 - Testar bloco individual\n";
        cout << "3 - Testar mensagem completa (ECB/CBC)\n";
        cout << "0 - Sair\n\nEscolha uma opção: ";
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: testarGeracaoDeChave(); break;
            case 2: testarBloco(); break;
            case 3: testarMensagem(); break;
            case 0: return 0;
            default: cout << "Opção inválida.\n";
        }
        cout << "\nPressione enter para continuar...\n";
        string enter;
        cin.ignore();
        getline(cin, enter);
    }
}