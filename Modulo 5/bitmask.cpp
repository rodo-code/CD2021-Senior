#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[5] = {5,7,2,3,1};
    for(int n=0;n<(1<<5);n++){
        int cont = 0;
        //if(__builtin_popcount(n)==3){
        for(int pos=4;pos>=0;pos--){
            if(n&(1<<pos)){
                cout<<arr[4-pos]<<" ";
                cont++;
            } 
            // else cout<<0;
        //}
        cout<<" este conjunto tiene "<<cont<<" elementos"<<endl;
                    
        }
    }
    
    return 0;
}