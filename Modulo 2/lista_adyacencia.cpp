#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > G;

int main(){
	int nodos,arcos,a,b;
	cin>>nodos>>arcos; // pedimos nodos y arcos
	G.assign(nodos,vector<int>()); // Creamos la lista de adyacencia
	while(arcos--){ // for(int i=0;i<arcos;i++)
		cin>>a>>b; // Leemos el arco
		G[a].push_back(b);
		G[b].push_back(a);
	}
	// NORMAL
	for(int i=0;i<G.size();i++){ // Recorremos todos los nodos
		cout<<"El nodo "<<i<<" esta conectado con ";
		for(int j=0;j<G[i].size();j++){
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	// C++ 11
	for(auto lista: G){
		for(auto adyacente: lista){
			cout<<adyacente<<" ";
		}
		cout<<endl;
	}
	return 0;
}