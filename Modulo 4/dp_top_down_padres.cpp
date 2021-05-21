#include <bits/stdc++.h>
using namespace std;

#define MINF -1000000000

int M,C;
vector<vector<int> >lista;
int cont_recursion=0;
// Tabla de Memoizar
int memo[210][25];
int padres[210][25];
int shop(int money, int g){ // Comprar el item g con la contidad de dinero money
    int res=MINF;
    // Casos Base
    if(money<0) return MINF; // la ruta no genera una solucion valida
    if(memo[money][g] != -1) return memo[money][g];  // Ver si ya tenemos la respuesta
    if(g==C) return memo[money][g] = M-money;// Acabamos de comprar todo 
    // Recursion
    for(int i=0;i<lista[g].size();i++){
        int precio = lista[g][i];
        int posible_respuesta = shop(money-precio,g+1);
        if(posible_respuesta > res){ // Significa que encontre una nueva respuesto optima
            padres[money][g]=i; // Cual es la mejor decision a partir de este estado
            res = posible_respuesta; // Actualizamos la respuesta
        }
    }
    return memo[money][g] = res;
}

int main(){
    int cp,precio_modelo,K;
    cin>>cp;
    while(cp--){
        cont_recursion=0;
        // Reseteamos la tabla memo
        memset(memo,-1,sizeof memo);
        memset(padres,-1,sizeof padres);
        cin>>M>>C;
        lista.assign(C,vector<int>());
        for(int i=0;i<C;i++){
            cin>>K;
            for(int j=0;j<K;j++){
                cin>>precio_modelo;
                lista[i].push_back(precio_modelo);
            }
        }
        cout<<shop(M,0)<<endl;
        int id=0;
        int item=padres[M][id];
        while(item != -1){
            cout<<item<<" ";
            M = M - lista[id][item];
            id++;
            item=padres[M][id];  
        }
        cout<<endl;
    }
    
    return 0;
}