#include <iostream>
#include <vector>
using namespace std;

#define NO_VISITADO -1
#define VISITADO 1
vector<int> visitado;
vector< vector<int> > G;
vector< vector<int> > GT;
vector<int> orden;

void dfs(int nodo){
    visitado[nodo] = VISITADO;
    for(int i=0;i<G[nodo].size();i++){
        int vecino = G[nodo][i];
        if(visitado[vecino] == NO_VISITADO){
            dfs(vecino);
        }
    } 
    orden.push_back(nodo);
}

void kosaraju(int nodo){
    visitado[nodo] = VISITADO;
    for(int i=0;i<GT[nodo].size();i++){
        int vecino = GT[nodo][i];
        if(visitado[vecino] == NO_VISITADO){
            kosaraju(vecino);
        }
    }
}

int main(){
    // Grafo Dirigido
    int nodos,arcos;
    int a,b;
    cin>>nodos>>arcos;
    G.assign(nodos,vector<int>());
    GT.assign(nodos,vector<int>());
    visitado.assign(nodos, NO_VISITADO);
    while(arcos--){
        cin>>a>>b;
        G[a].push_back(b); // Grafo Original
        GT[b].push_back(a); // Grafo transpuesto
    }

    // Topological
    for(int i=0;i<nodos;i++){
        if(visitado[i] == NO_VISITADO){
            dfs(i); // Hay que hacer el dfs con el Grafo Original
        }
    }

    // Reseteando el vector de visitados
    visitado.assign(nodos, NO_VISITADO);

    // Contamos los componentes fuertemente conexos
    int componentes = 0;
    for (int i=nodos-1;i>=0;i--){
        cout<<orden[i]<<" ";
        if(visitado[orden[i]] == NO_VISITADO){
            componentes++;
            kosaraju(orden[i]); // Hay que hacer el dfs con el Grafo Transpuesto
        }
    }
    cout<<endl;
    
    cout<<"El numero de componentes fuertemente conexas es "<<componentes<<endl;
    return 0;
}