#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int nodos,arcos;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> lista_arcos;

vector<int>rep, rank;
int numero_conjuntos;

void init(int N){
	rep.assign(N,0);
	rank.assign(N,0);
	for(int i=0;i<N;i++){
		rep[i]=i; // Cada elemento es su propio representante al inicio
	}
    numero_conjuntos = N;
}

int buscar(int x){
	if(rep[x]==x){
		return rep[x]=x;
	}
	else{
		return rep[x]=buscar(rep[x]);
	}
}

bool mismoConjunto(int x,int y){
	if(buscar(x)==buscar(y)){
		return true;
	}
	else{
		return false;
	}
}

void unir(int x,int y){
	if(mismoConjunto(x,y)==false){//si no estan en el mismo conjunto
        numero_conjuntos--; // reducimos el numero de conjuntos disjuntos
		x=buscar(x);
		y=buscar(y);
		if(rank[x]>rank[y]){//x es mas grande que y
			rep[y]=x;//y se une a x
		}
		if(rank[x]<rank[y]){//y es mas grande que x
			rep[x]=y;//x se une a y
		}
		if(rank[x]==rank[y]){// son iguales
			rep[x]=y;//x se une a y
			rank[y]++;//y cambia su rank
		}
	}
}

int main(){
    int nodos,arcos;
    cin>>nodos>>arcos; // Pedimos nodos y arcos
    for(int i=0;i<arcos;i++){ // Pedimos los arcos del grafo
        int a,b,peso; 
        cin>>a>>b>>peso; // Leemos el arco
        lista_arcos.push_back(iii(peso,ii(a,b))); // Añadimos el arco
    }
    sort(lista_arcos.begin(),lista_arcos.end()); // Ordennamos en orden creciente
    //COMIENZO DE KRUSKAL
    int costo_mst = 0;
    int arcos_tomados = 0;
    init(nodos);
    for(int i=0;i<lista_arcos.size();i++){
        iii elemento = lista_arcos[i];
        int peso = elemento.first;
        int a = elemento.second.first;
        int b = elemento.second.second;
        if(!mismoConjunto(a,b)){
            costo_mst+=peso;
            unir(a,b);
            cout<<"El arco de "<<a<<" a "<<b<<" es un arco del MST"<<endl;
            arcos_tomados++;
        }
        if(numero_conjuntos==1) break;
        if(arcos_tomados == nodos-1) break;
    }
    cout<<"Costo del MST "<<costo_mst<<endl;

    return 0;
}