#include <iostream>
#include <vector>

using namespace std;

#define EXPLORADO 2 // Color Verde
#define VISITADO 1 // Color Azul
#define NO_VISITADO 0 // Color Blanco

vector<int> dfs_etiqueta; // Vector que tendra las etiquetas
vector<int> dfs_padre; // Vector de padres
vector< vector<int> > G; // Grafo
void propiedadesArcos(int u) // DFS Modificado
{
    dfs_etiqueta[u] = EXPLORADO; // Marcamos como EXPLORADO
    for(int i=0;i<G[u].size();i++){ // Recorriendo la lista de adyacencia
        int vecino = G[u][i]; // vecino
        if(dfs_etiqueta[vecino]==NO_VISITADO){ // Arco de EXPLORADO a NO_VISITADO
            cout<<"El arco de "<<u<<" a "<<vecino<<" es un Tree Edge"<<endl;
            dfs_padre[vecino]=u;
            propiedadesArcos(vecino);
        }
        else if(dfs_etiqueta[vecino]==EXPLORADO){ // Arco de EXPLORADO a EXPLORADO 
            if(vecino==dfs_padre[u]){
                cout<<"Arco no dirigido ("<<u<<","<<vecino<<") - ("<<vecino<<","<<u<<")"<<endl;
            }
            else{
                cout<<"El arco de "<<u<<" a "<<vecino<<" es un Back Edge"<<endl;
            }
        }
        else if(dfs_etiqueta[vecino]==VISITADO){ // Arco de EXPLORADO a VISITADO
            cout<<"El arco de "<<u<<" a "<<vecino<<" es un Cross/Forward Edge"<<endl;
        }
    }

    dfs_etiqueta[u] = VISITADO; // Marcamos como 
}

int main()
{
    int nodos,arcos;
    cin>>nodos>>arcos; // Pedimos nodos y arcos
    G.assign(nodos+1,vector<int>()); // Creamos el grafo vacio
    // Inicializamos los vectores
    dfs_etiqueta.assign(nodos+1,NO_VISITADO);
    dfs_padre.assign(nodos+1,-1);
    while(arcos--){ // Pedimos los arcos
        int a,b;
        cin>>a>>b;
        G[a].push_back(b); // Estamos trabajando con grafos dirigidos
    }
    propiedadesArcos(1);
    return 0;
}