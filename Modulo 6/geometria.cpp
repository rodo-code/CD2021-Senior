#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define eps 1e-9

struct punto{
    double x,y;
    // CONSTRUCTORES
    punto(){x=0.0; y=0.0;} // Constructor por defecto
    punto(double _x, double _y){ // Constructor personalizado
        x=_x;
        y=_y;
    }
    // SOBRECARGAS DE OPERADORES
    bool operator < (punto otro) const{
        if(x<otro.x) return true;
        if(x==otro.x)
            if(y<otro.y) return true;
        return false;
    }
    bool operator == (punto otro) const{
        if(fabs(x-otro.x)<=eps and fabs(y-otro.y)<=eps) return true;
        return false;
    }  
};

double distancia(punto a, punto b){
    return hypot(a.x-b.x,a.y-b.y);
}

int main(){
    punto a(2.1412345678910235,15.17);
    punto b(2.14,30.11);
    punto c(3.17,1.14);
    punto d(2.14,15.17);
    vector<punto> v;
    v.push_back(c);
    v.push_back(a);
    v.push_back(b);
    for(auto p: v){
        cout<<p.x<<","<<p.y<<" "<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(auto p: v){
        //cout<<p.x<<","<<p.y<<" "<<endl;
        printf("%.6f,%.6f\n",p.x,p.y);
    }
    cout<<endl;
    cout<<(a==d)<<endl;
    cout<<distancia(a,c)<<endl;
    return 0;
}
