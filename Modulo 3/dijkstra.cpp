#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000 // Creamos una constante llamada INF 
typedef pair<int,int> ii; // Abreviatura para pares

vector< vector<ii> > G; // Creando la estructura del Grafo
vector<int> dist; // Vector de distancias
priority_queue<ii, vector<ii>, greater<ii> > pq; // Cola de prioridad creciente

int main(){
    int nodos,arcos;
    cin>>nodos>>arcos;
    G.assign(nodos,vector<ii>()); // Creamos las listas de cada nodo
    dist.assign(nodos,INF); // Ponemos todas las distancia
    
    while(arcos--){ // Leemos el grafo
        int a,b,peso;
        cin>>a>>b>>peso;
        G[a].push_back(ii(b,peso));
        G[b].push_back(ii(a,peso));
    }
    // Comienza Dijkstra
    int nodo_inicio = 0; // Nodo inicial
    dist[nodo_inicio] = 0; // La distancia del nodo inicial al nodo inicial es 0
    pq.push(ii(0,nodo_inicio)); // Colocamos en la cola {0,nodo_inicio}

    while(!pq.empty()){ // Mientres la cola no este vacia
        int distancia = pq.top().first; // Obtenemos la distancia
        int nodo = pq.top().second; // Obtenemos el nodo
        pq.pop(); // Quitamos el dato de la cima de la cola
        if(distancia>dist[nodo]) continue; // Si la distancia es mayor a la distancia menor al nodo
        // Relajacion de los arcos 
        for(int i=0;i<G[nodo].size();i++){ // Recorremos la lista de adyacencia nodo
            int vecino = G[nodo][i].first; // Vecino
            int peso_arco = G[nodo][i].second; // Peso de la conexion entre nodo y vecino
            if(dist[nodo]+peso_arco < dist[vecino]){ // Encontramos un camino mas corto
                dist[vecino] = dist[nodo]+peso_arco; // Actualizamos dist[vecino]
                pq.push(ii(dist[vecino],vecino)); // Ponemos a la cola el nuevo "camino"
            }
        }
    }
    // Imprimimos las distancias
    cout<<"Distancias"<<endl;
    for(int i=0;i<nodos;i++){
        cout<<"Distancia del nodo "<<nodo_inicio<<" a "<<i<<" es de "<<dist[i]<<endl;
    }
    return 0;
}