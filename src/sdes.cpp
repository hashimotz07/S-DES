/**
 * @file sdes.cpp
 * @brief Ponto de entrada principal do sistema S-DES
 * @author Iasmim Freitas
 * @author Lucas Hashimoto
 * @date 2025-05
 */
#include "input.hpp"

/**
 * @brief Função principal que implementa o menu interativo
 * @return int Código de saída (0 para sucesso)
 * 
 * @details O menu oferece 3 operações principais:
 * 1. Teste de geração de subchaves
 * 2. Teste de bloco individual
 * 3. Teste de mensagem completa (ECB/CBC)
 * 
 * @note O sistema usa:
 * - Chaves de 10 bits
 * - Blocos de 8 bits
 * - IV de 8 bits para CBC
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