#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define eps 1e-7
#define INF 1e9

typedef pair<double,double> dd;

struct punto{
    double x,y;
    punto(){x=0.0; y=0.0;} // Constructor por defecto
    punto(double _x, double _y){ // Constructor personalizado
        x=_x;
        y=_y;
    }
    // SOBRECARGAS DE OPERADORES
    bool operator < (punto otro) const{
        if(x<otro.x) return true;
        if(fabs(x-otro.x)<eps)
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
    vector<punto>v;
    int num_puntos;
    double cx,cy;
    // lECTURA DE LOS PUNTOS
    cin>>num_puntos;
    for(int i=0;i<num_puntos;i++){
        cin>>cx>>cy;
        v.push_back(punto(cx,cy));
    }
    // Tecnica Sweep Line
    // Paso 1 ordenar
    sort(v.begin(),v.end());
    double min_distancia = INF; // min_distancia es h
    set<dd> candidatos;
    int left = 0;
    for(int i=0;i<num_puntos;i++){ // O(n)
        while(left<i and v[i].x - v[left].x > min_distancia){ // O(k)
            candidatos.erase(dd(v[i].y,v[i].x)); // Quitando candidatos fuera del rango x
            left++; 
        }
        auto it1 = candidatos.lower_bound(dd(v[i].y-min_distancia,v[i].x)); // O(logn)
        auto it2 = candidatos.upper_bound(dd(v[i].y+min_distancia,v[i].x)); // O(logn)
        for(auto it=it1;it!=it2;it++){ // O(q)
            punto aux(it->second,it->first);
            min_distancia = min(min_distancia,distancia(aux,v[i]));
        }

        candidatos.insert(dd(v[i].y,v[i].x));
    }
    cout<<"Distancia minima = "<<min_distancia;
    return 0;
}