#include <iostream>

using namespace std;

bool es_primo(int N){
    if(N<=1) return false; //NO ES PRIMO
    for(int i=2;i*i<=N;i++){
        if(N%i==0) return false; // Encontramos un divisor
    }
    return true;
}

int main(){
    int N;
    while(cin>>N){
        if(es_primo(N)) cout<<N<<" ES PRIMO"<<endl;
        else cout<<N<<" NO ES PRIMO"<<endl;
    }

    return 0;
}