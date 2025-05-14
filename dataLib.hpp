#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

vector<int> p10 = {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
vector<int> p8 = {6, 3, 7, 4, 8, 5, 10, 9};
vector<int> p4 = {2, 4, 3, 1};
vector<int> ip = {2, 6, 3, 1, 4, 8, 5, 7};
vector<int> ipi = {4, 1, 3, 5, 7, 2, 8, 6};
vector<int> ep = {4, 1, 2, 3, 2, 3, 4, 1};
vector<vector<int>> s0 = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
vector<vector<int>> s1 = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};

// converte o numero inteiro para binario(string)
string toBin(int n){
    bitset<8> bit(n);
    return bit.to_string();
}

// converte o numero binario(string) para inteiro
int toInt(string bits){
    bitset<8> bit(bits);
    return bit.to_ulong();
}