#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N;
    int M;
    cin>>N>>M;
    vector<long long> prim;
    for(int i=0;i<M;i++){
        long long num;
        cin>>num;
        prim.push_back(num);
    }
    // Combinaciones
    // Principio de Inclusion/Exclusion
    
    // Este for genera todos los subconjuntos posibles de M elementos
    long long res = 0;
    for(int i=1;i<(1<<M);i++){
        // 1. Contar cuantos bits tiene prendido
        int c=0;
        // 2. OBtener el x 
        long long x=1;
        for(int j=0;j<M;j++){ // Recorre la representacion binaria;
            if(i&(1<<j)){
                // Bit prendido
                c++; // Contamos el bit prendido
                x=x*(prim[j]);
            }
        }
        if(c%2==0) // Restamos
            res = res - (N/x);
        else
            res = res + (N/x);
    }
    cout<<res<<endl;
    return 0;
}