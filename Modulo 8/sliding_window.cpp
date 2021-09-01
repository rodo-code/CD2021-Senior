#include <iostream>
#include <vector>
using namespace std; 

int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    int K;
    cin>>K;
    int min_t=100000;
    int i=0,j=0;
    int sum=A[i];
    while(j<N and i<N){
        if(sum<K){
            j++;
            sum+=A[j];
        }
        else if(sum==K){
            int tam=j-i+1;
            min_t = min(min_t,tam);
            sum-=A[i];
            i++;
        }
        else {
            // suma > K
            sum-=A[i];
            i++;
        }
    }
    cout<<min_t<<endl;
    return 0;
}