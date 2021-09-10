#include <iostream>
#include <vector>
#include <stack>
using namespace std;

typedef vector<int> vi;

int nodos,arcos;
vector<vi>G;
vi grado;

// Algoritmo de Hierholzder
vi recorrido_euleriano(int inicio){
    vi res,ind(nodos,0);
    stack<int> pila;
    pila.push(inicio);
    while(!pila.empty()){
        int nodo = pila.top();
        if(ind[nodo]<G[nodo].size()){ // Si los arcos de ese nodo son menores a cuantos arcos salen del nodo
            pila.push(G[nodo][ind[nodo]]);
            ind[nodo]++;
        }
        else{
            res.push_back(nodo);
            pila.pop();
        }
    }
    return res;
}

bool prueba_grados(){
    int cont=0;
    for(int i=0;i<nodos;i++){
        if(grado[i]%2==1) cont++;
    }
    return (cont==2 or cont==0);
}

int main(){
    cin>>nodos>>arcos;
    G.assign(nodos,vi());
    grado.assign(nodos,0);
    for(int i=0;i<arcos;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        grado[a]++;
        grado[b]++;
    }
    if(prueba_grados()){
        vi ans = recorrido_euleriano(2);
        for(auto x: ans){
            cout<<x;
        }
        cout<<endl;
    }
    else{
        cout<<"Su Grafo no tiene un recorrido euleriano"<<endl;
    }
    return 0;
}