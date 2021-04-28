#include <iostream>
#include <vector>
using namespace std;

#define INF 1000000000
typedef pair<int,int> ii;

vector< vector<ii> > G; // Grafo en forma de vector de vectores de pares entero entero
vector<int> dist; // Vector de distancias que tendrá las distancias más cortas
int main(){
    // Leemos el grafo
    int cant_nodos,arcos;
    cin>>cant_nodos>>arcos;
    G.assign(cant_nodos,vector<ii>());
    dist.assign(cant_nodos,INF);
    for(int i=0;i<arcos;i++){
        int a,b,peso;
        cin>>a>>b>>peso;
        G[a].push_back(ii(b,peso));
        G[b].push_back(ii(a,peso)); // Comentar esta linea si se trabaja con grafos dirigidos
    }
    // ----- Fin de Leer el grafo -----
    int nodo_inicial = 0; // Escogemos el nodo inicial
    dist[nodo_inicial] = 0; // Caso base 
    for(int i=0;i<cant_nodos-1;i++){ // Hacemos N-1 ciclos, cant_nodos - 1
        for(int nodo=0;nodo<cant_nodos;nodo++){ // Recorremos los nodos
            if(dist[nodo]!=INF){ // Si he llegado al nodo antes
                for(int k=0;k<G[nodo].size();k++){ // Recorre la lista de adyacencia de cada nodo
                    int vecino = G[nodo][k].first;
                    int peso_arco = G[nodo][k].second;
                    /* DEBUG
                    if(dist[nodo]+peso_arco<dist[vecino]){
                        cout<<"Se tomo en cuenta el arco ("<<nodo<<","<<vecino<<")"<<endl;
                        cout<<"Se actualizara dist["<<vecino<<"]="<<dist[nodo]+peso_arco<<endl;
                        cout<<"dist["<<nodo<<"]="<<dist[nodo]<<endl;
                        cout<<"peso_arco = "<<peso_arco<<endl;
                    }*/ 
                    dist[vecino]=min(dist[vecino],dist[nodo]+peso_arco); // Actualizando la distancia menor
                }
            }
        }
    }
    // Imprime las distancias
    cout<<"DISTANCIAS"<<endl;
    for(int i=0;i<cant_nodos;i++){
        cout<<"Distancia a "<<i<<" es "<<dist[i]<<endl;
    }
    // Ciclo Negativo
    bool ciclo_negativo = false; //Variable que nos dira si hay o no ciclo negativo
    for(int nodo=0;nodo<cant_nodos;nodo++){ // Recorriendo los nodos
        if(dist[nodo]!=INF){ // Si se pudo llegar al nodo
            for(int k=0;k<G[nodo].size();k++){ // Recorriendo la lista
                int vecino = G[nodo][k].first;
                int peso_arco = G[nodo][k].second;
                if(dist[nodo]+peso_arco<dist[vecino]){ // Si se llega con una distancia menor hay un ciclo
                    ciclo_negativo=true;
                }
            }
        }
    }

    if(ciclo_negativo) cout<<"EXISTE CICLO NEGATIVO"<<endl;
    else cout<<"NO EXISTE CICLO NEGATIVO"<<endl;
    
    return 0;
}