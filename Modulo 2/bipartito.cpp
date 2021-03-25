#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector< vector<int> > G;
vector<int>color;

bool esBipartito(int nodo){
	queue<int>cola;
	cola.push(nodo);
	color[nodo]=0;
	while(!cola.empty()){
		nodo = cola.front();
		cola.pop();
		for(int i=0;i<G[nodo].size();i++){// Recoremos los vecinos de nodo
			int vecino=G[nodo][i];
			if(color[vecino]==-1){ // vecino no esta visitado
				cola.push(vecino);
				color[vecino]=1-color[nodo];
			}
			else{
				if(color[nodo]==color[vecino]){
					return false;
				}
			}
		}
	}
	return true;
}

int main(){
	int nodos,arcos;
	cin>>nodos>>arcos;
	G.assign(nodos,vector<int>());
	color.assign(nodos,-1);
	while(arcos--){
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout<<esBipartito(0)<<endl;
	return 0;
}