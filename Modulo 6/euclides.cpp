#include <iostream>
#include <algorithm> // Para usar __gcd()
using namespace std;

// ALGORITMO DE EUCLIDES 
long long gcd(long long a, long long b){
    if(b==0){
        //cout<<"Caso base"<<endl;
        return a;
    }
    //cout<<"Mandando gcd("<<b<<","<<a%b<<")"<<endl;
    return gcd(b,a%b);
}
// Minimo Comun Multiplo usando euclides
long long lcm(long long a, long long b){
    return (a*b)/gcd(a,b);
}

int main(){
    long long a,b;
    while(cin>>a>>b){
        cout<<"Maximo comun divisor "<<__gcd(a,b)<<endl;
        cout<<"Minimo comun multiplo "<<(a*b)/__gcd(a,b)<<endl;
        cout<<"Maximo comun divisor "<<gcd(a,b)<<endl;
        cout<<"Minimo comun multiplo "<<lcm(a,b)<<endl;
    }

    return 0;
}