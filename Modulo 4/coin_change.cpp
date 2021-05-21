#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int V,k;
vector<int>moneda;
vector<int>memo;

int change(int p){
    if(p==0) return 0;
    if(memo[p]!=-1) return memo[p];
    //Proceso
    int res=INF;
    for(int i=0;i<k;i++){
        if(p>=moneda[i]){
            res = min(res,1+change(p-moneda[i]));
        }
    }
    return memo[p]=res;
}

int main(){
    cin>>V>>k;
    moneda.assign(k,0);
    memo.assign(V+1,-1);
    for(int i=0;i<k;i++){
        cin>>moneda[i];
    }

    cout<<change(V)<<endl;
    return 0;
}