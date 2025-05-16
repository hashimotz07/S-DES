#include "input.hpp"

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