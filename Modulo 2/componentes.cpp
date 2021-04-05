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
	// Conteo de componentes
	int num_componentes = 0;
	for(int i=0;i<nodos;i++){
		if(visitado[i]==false){ // si no esta visitado
			dfs(i);
			num_componentes++;
		}
	}
	cout<<"El grafo tiene "<<num_componentes<<" componentes";
	return 0;
}