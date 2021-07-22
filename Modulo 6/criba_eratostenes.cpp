#include <iostream>
#include <vector>
using namespace std;

vector<bool>primo;
vector<int> lista_primos;
void criba(int N){
    primo.assign(N+1,1);
    primo[0]=0;
    primo[1]=0;
    for(int i=2;i*i<=N;i++){
        if(primo[i]){// Si no esta tachado i
            //Tachamos los multiplos de i
            for(int j=i*i;j<=N;j+=i){
                primo[j]=0;
            }
        }
    }
    // Obtenemos la lista de primos
    for(int i=2;i<=N;i++){
        if(primo[i]) lista_primos.push_back(i);    
    }
}

int main(){
    int N=1000000000;
    int dist_max = -1;
    criba(N);
    cout<<"Hay "<<lista_primos.size()<<" primos hasta 1000000"<<endl;
    for(int i=0;i<lista_primos.size();i++){
        dist_max = max(dist_max, lista_primos[i+1]-lista_primos[i]);
    }
    cout<<"La distancia maxima entre dos primos hasta 1000000 es "<<dist_max<<endl;
    int x;
    while(cin>>x){
        if(primo[x]) cout<<x<<" ES PRIMO"<<endl;
        else cout<<x<<" NO ES PRIMO"<<endl;
    }
}