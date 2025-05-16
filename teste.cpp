#include "encriptDecript.hpp"

string ECB_encripta(string& plainText, string& chaveS){
    string cipherText="";
    int chave = toInt(chaveS, 10);
    for(int i=0; i < (int)plainText.size(); i += 8){
        int bloco = toInt(plainText.substr(i, 8), 8);
        cipherText += toBin(encriptacao(bloco, chave), 8);
    }
    return cipherText;
}

string ECB_decripta(string& cipherText, string& chaveS){
    string plainText="";
    int chave = toInt(chaveS, 10);
    for(int i=0; i < (int)cipherText.size(); i += 8){
        int bloco = toInt(cipherText.substr(i, 8), 8);
        cout << bloco << endl;
        plainText += toBin(decriptacao(bloco, chave), 8);
    }
    return plainText;
}

string CBC_encripta(string& plainText, string& chaveS, string& IV){
    string cipherText="";
    int chave = toInt(chaveS, 10), last = toInt(IV, 8);
    for(int i=0; i < (int)plainText.size(); i += 8){
        last = toInt(plainText.substr(i, 8), 8) ^ last;
        last = encriptacao(last, chave);
        cipherText += toBin(last, 8);
    }
    return cipherText;
} 

string CBC_decripta(string& cipherText, string& chaveS, string& IV){
    string plainText="", newcipher = IV + cipherText;
    int chave = toInt(chaveS, 10), last, atual, i;
    i = (int)newcipher.size()-8;
    vector<int> ans;
    atual = toInt(newcipher.substr(i, 8), 8);
    for(; i >= 8; i -= 8){
        last = toInt(newcipher.substr(i-8, 8), 8);
        atual = decriptacao(atual, chave) ^ last;
        ans.push_back(atual);
        atual = last;
    }
    for(i=(int)ans.size()-1; i >= 0; i--){
        plainText += toBin(ans[i], 8);
    }
    return plainText;
} 

int main(){
    int chave = toInt("1010000010", 10);
    int bloco = toInt("11010111", 8);

    string mensagem = "11010111011011001011101011110000";
    string chaveS = "1010000010";
    string IV = "01010101";

    string ans = ECB_encripta(mensagem, chaveS);
    cout << "encripta : " << ans << endl;
    ans = ECB_decripta(ans, chaveS);
    cout << "decriptação :  " << ans << endl;

    string bitt=  toBin(encriptacao(bloco, chave), 8);
    cout << "cipherText : " << bitt << endl;
    cout << toBin(decriptacao(encriptacao(bloco, chave), chave), 8) << endl;
}