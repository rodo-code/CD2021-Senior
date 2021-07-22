#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int>factor;

void criba(int N){
    factor.assign(N+1,0);
    iota(factor.begin(),factor.end(),0); // Llena el vector de 0, 1, 2, ..., N
    for(int i=2;i*i<=N;i++){
        if(factor[i]==i){// Si es primo
            //Marcamos los multiplos de i
            for(int j=i*i;j<=N;j+=i){
                if(factor[j]==j){ // No ha sido tachado aun
                    factor[j]=i;
                }
            }
        }
    }
}

void factores_primos(int x){
    while(x!=1){
        cout<<factor[x]<<" ";
        x = x/factor[x];
    }
}

int num_divisores(int x){
    map<int,int> m;
    while(x!=1){
        m[factor[x]]++; // Contar cuantos hay de cada factor
        x = x/factor[x];
    }
    // Recorrer el mapa 
    int res = 1;
    for(auto elem: m){
        int fact = elem.first;
        int exp = elem.second;
        res = res * (exp+1);
    }
    return res;
}

int main(){
    int x;
    int N=1000000;
    int dist_max = -1;
    criba(N);
    // Saca el numero con mas divisores
    int num_max_div=-1;
    int max_div=-1;
    for(int i=2;i<=N;i++){
        int aux=num_divisores(i);
        if(aux>max_div){
            num_max_div=i;
            max_div=aux;
        }
    }
    cout<<num_max_div<<endl;
    // Saca los factores primos y numero de divisores
    while(cin>>x){
        cout<<"Factores Primos de "<<x<<endl;
        factores_primos(x);
        cout<<endl;
        cout<<x<<" tiene "<<num_divisores(x)<<" divisores"<<endl;
    }
   
}