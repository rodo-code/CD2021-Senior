#include <iostream>

using namespace std;
#define INF 1000000000

int main(){
    int nodos,arcos;
    cin>>nodos>>arcos;
    int matriz_adj[nodos][nodos];
    int padres[nodos][nodos];
    // Llenamos inicialmente la matriz
    for(int i=0;i<nodos;i++){
        for(int j=0;j<nodos;j++){
            // Si esta en la diagonal peso 0
            if(i==j) matriz_adj[i][j] = 0;
            else matriz_adj[i][j] = INF;
            padres[i][j]=i;
        }
    }
    // Pidiendo el grafo
    for(int i=0;i<arcos;i++){
        int a,b,peso;
        cin>>a>>b>>peso;
        matriz_adj[a][b]=peso;
        matriz_adj[b][a]=peso;
    }

    // Floyd Warshall
    for(int k=0;k<nodos;k++){
        for(int i=0;i<nodos;i++){
            for(int j=0;j<nodos;j++){
                if(matriz_adj[i][k]+matriz_adj[k][j] < matriz_adj[i][j]){
                    matriz_adj[i][j] = matriz_adj[i][k]+matriz_adj[k][j]; // Actualizamos
                    padres[i][j] = padres[k][j]; // Actualizamos
                }
                //matriz_adj[i][j] = min(matriz_adj[i][j],matriz_adj[i][k]+matriz_adj[k][j]);
            }
        }
        // Imprimimos la matriz
        /*cout<<"k = "<<k<<endl;
        for(int r=0;r<nodos;r++){
            for(int s=0;s<nodos;s++){
                cout<<matriz_adj[r][s]<<" ";
            }
            cout<<endl;
        }*/
    }

    // Camino de 1 a 3
    cout<<"CAMINO"<<endl;
        int nodo_inicial = 1;
        int nodo_actual = 3; // Nodo Final
        while(nodo_actual != nodo_inicial){
            cout<<nodo_actual<<" ";
            nodo_actual = padres[nodo_inicial][nodo_actual];
        }
        cout<<nodo_inicial<<endl;
}