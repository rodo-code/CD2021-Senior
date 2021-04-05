#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > G; //Grafo
vector<bool> visitado; // vector de visitados

void dfs(int nodo){
	visitado[nodo]=true; // Marcar como visitado el nodo
	for(auto vecino: G[nodo]){ // Para todos los vecinos del nodo
		if(visitado[vecino]==false){ // Preguntar si ese vecino NO esta visitado
			dfs(vecino); // Visitar vecino
		}
	}
}

int main(){
	int nodos, arcos, a, b;
	cin>>nodos>>arcos; // Pedir nodos y arcos
	G.assign(nodos,vector<int>()); // Creamos el grafo
	visitado.assign(nodos,false); // Asignando todas las casillas con falso
	while(arcos--){ // Pedimos los arcos
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0);

	for(auto elemento: visitado){
		cout<<elemento<<" ";
	}
	cout<<endl;
	return 0;
}