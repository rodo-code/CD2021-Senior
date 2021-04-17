#include <iostream>
#include <vector>

using namespace std;

#define NO_VISITADO -1

int contador_dfs=0;
int raiz_dfs;
int hijos_raiz;
vector<vector<int> > G;
vector<int> dfs_num;
vector<int> dfs_low;
vector<int> dfs_padre;
vector<bool> puntos_de_articulacion; // True si es que ese nodo es un punto de
// articulacion y False en caso de que no

void puntosArticulacionYPuentes(int nodo){
    dfs_num[nodo] = contador_dfs;
    dfs_low[nodo] = contador_dfs;
    contador_dfs++;
    for(int i=0;i<G[nodo].size();i++){
        int vecino = G[nodo][i];
        if(dfs_num[vecino] == NO_VISITADO){
            dfs_padre[vecino]=nodo;
            if(nodo == raiz_dfs) hijos_raiz++;
            puntosArticulacionYPuentes(vecino);
            
            if(dfs_low[vecino]>=dfs_num[nodo]){
                puntos_de_articulacion[nodo]=true;
            }
            if(dfs_low[vecino]>dfs_num[nodo]){
                cout<<"El arco ("<<nodo<<","<<vecino<<") es un puente"<<endl;
            }
            dfs_low[nodo] = min(dfs_low[nodo],dfs_low[vecino]);
            
        }
        else if(vecino != dfs_padre[nodo]){ // Si no es ciclo trivial
            dfs_low[nodo] = min(dfs_low[nodo],dfs_num[vecino]);
        }
    }
}

int main(){
    int nodos,arcos;
    cin>>nodos>>arcos;
    // Inicializando los vectores
    dfs_num.assign(nodos,NO_VISITADO);
    dfs_low.assign(nodos,0);
    dfs_padre.assign(nodos,-1);
    puntos_de_articulacion.assign(nodos,false);
    G.assign(nodos,vector<int>());
    while(arcos--){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<nodos;i++){
        if(dfs_num[i] == NO_VISITADO){
            contador_dfs = 0;
            raiz_dfs = i;
            hijos_raiz = 0;
            puntosArticulacionYPuentes(i);
            puntos_de_articulacion[i] = (hijos_raiz>1);
        }
    }

    for(int i=0;i<nodos;i++){
        if(puntos_de_articulacion[i]) 
            cout<<"El nodo "<<i<<" es un punto de articulacion"<<endl;
    }

    cout<<"dfs_num"<<endl;
    for(int i=0;i<nodos;i++){
        cout<<dfs_num[i]<<" ";
    }
    cout<<endl;

    cout<<"dfs_low"<<endl;
    for(int i=0;i<nodos;i++){
        cout<<dfs_low[i]<<" ";
    }
    cout<<endl;
    return 0;
}