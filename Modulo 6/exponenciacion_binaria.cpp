#include <iostream>
#include <cstdio>
using namespace std;

int exponenciacion(int a,int b,int m){
    // Casos base
    if(b==0) return 1;
    if(b==1) return (a%m);
    int res_med = exponenciacion(a,b/2,m);
    int res_par = ((res_med%m)*(res_med%m))%m;
    if(b%2==0){ // Si es par
        return res_par;
    }
    else{ // Si es impar
        return ((res_par%m)*(a%m))%m;
    }
}

int main(){
    const int m=100;
    printf("%d\n",exponenciacion(53,15,m));
    return 0;
}