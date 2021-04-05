#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

vector< vector<int> >G;
vector<bool> visitado;
vector<int> padre;
vector<int> distancia;

void bfs(int nodo){
	queue<int> cola; // Creamos la cola
	cola.push(nodo); // Ponemos el nodo inicial a la cola
	padre[nodo]=nodo; 
	distancia[nodo]=0;
	visitado[nodo] = true; // Marcamos como visitado a nodo
	while(!cola.empty()){ // Mientras la cola no este vacia
		nodo = cola.front(); // Obtenemos el elemento al frente de la cola
		cola.pop(); // Lo sacamos
		for(int i=0;i<G[nodo].size();i++){ // Recorremos los vecinos de nodo
			int vecino = G[nodo][i];
			if(visitado[vecino]==false){// Si vecino no esta visitado
				cola.push(vecino); // Ponemos en la cola al vecino
				visitado[vecino]=true; // Marcamos como visitado al vecino
				padre[vecino] = nodo;
				distancia[vecino] = distancia[nodo] + 1;
			}
		}
	}
}

int main(){
	int nodos,arcos,a,b;
	cin>>nodos>>arcos;
	G.assign(nodos,vector<int>());
	visitado.assign(nodos,false);
	padre.assign(nodos,-1);
	distancia.assign(nodos,-1);
	while(arcos--){
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bfs(2); // Mando el BFS
	// Ruta
	int x = 5;
	deque<int>ruta;
	ruta.push_front(x);
	while(padre[x]!=x){
		x = padre[x];
		ruta.push_front(x);
	}

	// Imprimimos la ruta
	for(int i=0;i<ruta.size();i++){
		cout<<ruta[i]<<" ";
	}
	cout<<endl;
	return 0;
}