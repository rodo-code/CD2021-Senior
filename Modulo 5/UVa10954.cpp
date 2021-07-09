#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

int main(){
    int N,x;
    priority_queue<int, vector<int>, greater<int> > pq;
    while(scanf("%d",&N) and N!=0){
        for(int i=0;i<N;i++){
            scanf("%d",&x);
            pq.push(x);
        }
        int cost_total = 0;
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            cost_total+=(a+b);
            pq.push(a+b);
        }
        printf("%d\n",cost_total);
        pq.pop();
    }
    return 0;
}