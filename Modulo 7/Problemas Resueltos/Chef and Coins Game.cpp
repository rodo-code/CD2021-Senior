#include <iostream>
#include <vector>
using namespace std;

int N=10010;
vector<bool> res(N,true); // true-> chef false->misha
vector<bool> natural(N,false); 
vector<bool> primo(N,true);
bool is_prime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void criba(){
    primo[0]=false;
    primo[1]=false;
    natural[1]=true;
    for(int i=2;i*i<=N;i++){
        if(primo[i]){
            natural[i]=true;
            for(int j=i*i;j<N;j+=i){
                primo[j]=false;
            }
            int aux = i;
            while(aux<N){
                natural[aux]=true;
                aux*=i;
            }
        }
    }
}

int main(){
    /*criba();
    for(int i=1;i<=10000;i++){
        if(natural[i]){ // Puedo tomar i monedas
            res[i]=true; // Ganara el chef
        }
        else{
            //cout<<"Caso "<<i<<endl;
            bool gan = false;
            for(int j=1;j<i;j++){
                if(natural[j]){
                    //cout<<"Si quito "<<j<<endl;
                    int resto = i-j;
                    if(res[resto]==false){
                        gan = true;
                        break;                        
                    }
                }
            }
            res[i]=gan;
        }
    }
    for(int i=1;i<=10000;i++){
        if(res[i]==false){
            cout<<i<<" ";
        }
    }
    cout<<endl;*/
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        cout<<((N%6==0)? "Misha" : "Chef")<<endl;
    }
    return 0;
}