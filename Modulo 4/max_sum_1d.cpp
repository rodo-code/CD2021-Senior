#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> A;
    int N; 
    cin>>N;
    A.assign(N,0);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    // Kadane
    int sum=0;
    int res=0;
    for(int i=0;i<N;i++){
        sum = sum + A[i];
        if(sum<0) sum=0;
        res = max(res,sum);
    }
    cout<<res<<endl;
    return 0;
}