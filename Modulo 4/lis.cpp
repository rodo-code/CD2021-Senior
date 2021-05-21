#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

int N;
vector<int>A;
vector<int>memo;

int lis(int i){
    if(i==0) return 1;
    if(memo[i]!=-1) return memo[i];
    //Proceso
    int res=1;
    for(int j=0;j<i;j++){
        if(A[j]<A[i]){
            res = max(res, 1+lis(j));
        }
    }
    return memo[i]=res;
}

int main(){
    cin>>N;
    A.assign(N+1,0);
    A[N]=INF;
    memo.assign(N+1,-1);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    cout<<lis(N)-1<<endl;
    return 0;
}