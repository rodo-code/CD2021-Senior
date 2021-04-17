#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define NO_VISITADO -1

vector<int> dfs_num;
vector<int> dfs_low;
vector<int> en_la_pila;
vector< vector<int> > G;
stack<int> pila;
int componentes = 0;
int contadorDfs = 0;
void tarjan(int nodo){
    dfs_num[nodo] = contadorDfs; // Le pone el tiempo en el que se alcanzo ese nodo
    dfs_low[nodo] = contadorDfs;
    contadorDfs++;
    pila.push(nodo); // añadimos el nodo a la pila
    en_la_pila[nodo] = 1; // indicamos ese nodo esta en la pila
    
    for(int i=0;i<G[nodo].size();i++){ // Recorremos los vecinos
        int vecino = G[nodo][i];
        if(dfs_num[vecino] == NO_VISITADO){ // Si el vecino no esta numerado
            tarjan(vecino);
            dfs_low[nodo] = min(dfs_low[nodo],dfs_low[vecino]);
        }
        else if (dfs_num[vecino] < dfs_num[nodo]){
            if(en_la_pila[vecino]){
                dfs_low[nodo] = min(dfs_low[nodo],dfs_num[vecino]);
            }
        }
    } 

    if(dfs_low[nodo] == dfs_num[nodo]){
        componentes ++;
        cout<<"Componente Fuertemente Conexo "<<componentes<<": ";
        int v;
        do{
            v = pila.top();
            cout<<v<<" ";
            pila.pop();
            en_la_pila[v] = 0;
        }while(v!=nodo);
        cout<<endl;
    }
}

int main(){
    // Grafo Dirigido
    int nodos,arcos;
    int a,b;
    cin>>nodos>>arcos; // Pedimos la cantidad de nodos y arcos
    G.assign(nodos,vector<int>());
    dfs_num.assign(nodos, NO_VISITADO);
    dfs_low.assign(nodos,NO_VISITADO);
    en_la_pila.assign(nodos,0);
    while(arcos--){ // Leemos los arcos
        cin>>a>>b;
        G[a].push_back(b); // Lo ponemos en la lista de adyacencia
    }
    for(int i=0;i<nodos;i++){
        if(dfs_num[i] == NO_VISITADO){
            tarjan(i); // Lanzamos el Tarjan
        }
    }
    
    cout<<"El numero de componentes fuertemente conexas es "<<componentes<<endl;
    return 0;
}