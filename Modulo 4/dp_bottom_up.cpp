// Este algoritmo es un ejemplo de un programa que usa Programacion Dinamica en la forma Bottom Up
#include <bits/stdc++.h>
using namespace std;

#define MINF -1000000000

int M,C;
vector<vector<int> >lista;
int cont_recursion=0;

int main(){
    int cp,precio_modelo,K;
    cin>>cp;
    while(cp--){
        cont_recursion=0;
        cin>>M>>C;
        // Creamos la tabla del dp
        int dp[C][M+1];
        memset(dp,0,sizeof dp); // Llenamos de 0s
        lista.assign(C,vector<int>());
        for(int i=0;i<C;i++){
            cin>>K;
            for(int j=0;j<K;j++){
                cin>>precio_modelo;
                lista[i].push_back(precio_modelo);
            }
        }
        // Hacemos el DP
        // Casos base
        for(int i=0;i<lista[0].size();i++){ // Recorremos la lista de opciones del item 0
            int sobra = M-lista[0][i];
            if(sobra>=0) dp[0][sobra] = 1;
        }

        for(int i=0;i<C-1;i++){ // Recorrer las filas (items)
            for(int j=0;j<=M;j++){ // Recorriendo el dinero que me sobra
                if(dp[i][j]==1){ // Significa que hay una forma de comprar el item i y quedarse con el dinero j
                    for(int k=0;k<lista[i+1].size();k++){ // Recorremos la lista de opciones del item i+1
                        int precio = lista[i+1][k];
                        int sobra = j - precio;
                        if(sobra>=0){
                            dp[i+1][sobra]=1;
                        }
                    }
                }
            }
        }
        bool res=false;
        for(int i=0;i<=M;i++){ // Recorremos la ultima fila
            if(dp[C-1][i]==1){
                res=true;
                cout<<M-i<<endl;
                break;
            }
        }
        if(!res){
            cout<<"no solution"<<endl;
        }
    }
    
    return 0;
}