#include <bits/stdc++.h>
using namespace std;

int N,K;
int memo[1010][1010];
vector<int> p,v;

int mochila(int id, int resto){
    if(id==N) return 0;
    if(resto<=0) return 0;
    if(memo[id][resto]!= -1) return memo[id][resto];
    if(p[id]>resto){
        return memo[id][resto]=mochila(id+1,resto);
    }
    else{
        int no_tomar = mochila(id+1,resto);
        int tomar = v[id]+mochila(id+1,resto-p[id]);
        return memo[id][resto] = max(no_tomar,tomar);
    }
}

int main(){
    cin>>N>>K;
    int peso,valor;
    memset(memo,-1,sizeof memo);
    for(int i=0;i<N;i++){
        cin>>peso>>valor;
        p.push_back(peso);
        v.push_back(valor);
    }
    cout<<mochila(0,K)<<endl;
    return 0;
}