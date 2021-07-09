#include <iostream>
#include <cmath> // abs
using namespace std;

int main(){
    double l=0,r=2;
    double eps=0.00000001;
    double x,y;
    // x^2 + x - 4 = 0
    while(fabs(l-r)>eps){
        cout<<"l="<<l<<", r="<<r<<endl;
        x = (r+l)/2;
        y = x*x + x - 4;
        if(y<0) l=x;
        if(y>0) r=x;
        if(y==0){
            cout<<"La solucion exacta es "<<x<<endl;
            break;
        }
    }
    cout<<"La solucion aproximada es "<<x<<endl;
    return 0;
}