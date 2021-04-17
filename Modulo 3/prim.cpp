#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;

priority_queue<ii,vector<ii>,greater<ii> > pq; // Cola de prioridad que ordena de menor a mayor
vector< vector<ii> > G; // Lista de adyacencia del grafo
vector<bool> visitado; // Vector de visitados

void prim(int nodo){
    visitado[nodo] = true; // Marcamos el nodo como visitado
    for(int i=0;i<G[nodo].size();i++){ // Recorremos los arcos del nodo
        int vecino = G[nodo][i].first; // Obtenemos el vecino
        int peso = G[nodo][i].second; // El peso de la conexioin
        if(!visitado[vecino]){ // Si no esta visitado el vecino
            pq.push(ii(peso,vecino)); // Añadimos el arco a la cola de prioridad
        }
    }
}

int main(){
    int nodos,arcos; // nodos es el numero de nodos y arcos el numero de arcos
    cin>>nodos>>arcos; // Pedimos nodos y arcos
    visitado.assign(nodos,false); // Al inicio todos los nodos no estan visitados
    G.assign(nodos,vector<ii>()); // Creamos el grafo
    while(arcos--){ // Pedimos los arcos
        int a,b,peso;
        cin>>a>>b>>peso; // Leemos los arcos
        G[a].push_back(ii(b,peso)); // A la lista de adyacencia de a le colocamos (b,peso)
        G[b].push_back(ii(a,peso)); // A la lista de adyacencia de b le colocamos (a,peso)
    }
    prim(0); // Lanzamos el prim desde el nodo 0
    int costo_mst = 0; // costo del MST
    int arcos_tomados = 0; // Cantidad de arcos ya tomados en cuenta
    while(arcos_tomados<nodos-1 and !pq.empty()){ // Mientras no hayamos acabado el MST
        int nodo = pq.top().second; // El nodo al que se conecta
        int peso = pq.top().first; // El peso
        pq.pop(); // Quitmamos de la cola al primero
        if(!visitado[nodo]){ // Si no esta visitado el nodo
            arcos_tomados++; // Tomamos en cuenta el arco
            costo_mst += peso; // Sumamos el peso al costo del MST
            prim(nodo); // lanzamos un prim del nodo
        }
    }
    cout<<"Costo del MST "<<costo_mst<<endl; // Imprimimos el costo
    return 0;
}