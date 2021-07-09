#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> ii;

vector< vector<ii> >G;
vector<bool>visitado;
int inicio,final;
int nodos,arcos;

void dfs(int nodo,int k){
    visitado[nodo]=true;
    for(auto vecino: G[nodo]){
        int nodo_vecino = vecino.first;
        int peligrosidad = vecino.second;
        if(peligrosidad<=k and !visitado[nodo_vecino])
            dfs(nodo_vecino,k);
    }
}

bool P(int k){
    visitado.assign(nodos,false);
    dfs(inicio,k);
    return visitado[final];
}

int main(){
    int a,b,peligrosidad;
    int maxima_peligrosidad=-1;
    // Leemos el grafo
    cin>>nodos>>arcos;
    G.assign(nodos,vector<ii>());
    for(int i=0;i<arcos;i++){
        cin>>a>>b>>peligrosidad;
        maxima_peligrosidad = max(peligrosidad,maxima_peligrosidad);
        G[a].push_back(ii(b,peligrosidad));
        G[b].push_back(ii(a,peligrosidad));
    }
    cin>>inicio>>final;
    // BSTA
    int l=1,r=maxima_peligrosidad;
    while(r-l>1){
        int mid=(r+l)/2;
        if(P(mid)){ // P(mid)==true
            r=mid;
        }
        else{ // P(mid)==false
            l=mid;
        }
    }
    // Primero probamos el r
    //cout<<"l="<<l<<" r="<<r<<endl;
    if(P(l)) cout<<"La maxima peligrosidad es "<<l<<endl;
    else if(P(r)) cout<<"La maxima peligrosidad es "<<r<<endl;
    else cout<<"El problema no tiene solucion"<<endl;
    return 0;
}