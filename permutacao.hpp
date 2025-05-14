#include "dataLib.hpp"

/*permuta*/
int permuta(int n, vector<int> &v, int total_bits = 10){
    int resultado = 0;
    for(int i = 0; i < (int)v.size(); i++){
        resultado = resultado << 1;
        resultado |= (n >> (total_bits - v[i])) & 1;
    }
    return resultado;
}