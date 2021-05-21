#include <iostream>

using namespace std;

int main(){
    int N; 
    cin>>N;
    int matriz[N][N];

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>matriz[i][j];
            if(i>0) matriz[i][j]+=matriz[i-1][j];
            if(j>0) matriz[i][j]+=matriz[i][j-1];
            if(i>0 and j>0) matriz[i][j]-=matriz[i-1][j-1];
        }
    }
    int res=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=i;k<N;k++){
                for(int l=j;l<N;l++){
                    // Sumar el rango
                    int sum = matriz[k][l];
                    if(i>0) sum-=matriz[i-1][l];
                    if(j>0) sum-=matriz[k][j-1];
                    if(i>0 and j>0) sum+=matriz[i-1][j-1];

                    res = max(res,sum);
                }
            }
        }
    }

    cout<<res<<endl;
    return 0;
}

