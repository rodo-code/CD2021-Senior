
#include <bits/stdc++.h>
using namespace std;

#define eps 1e-7
const double pi = acos(-1);

struct punto{ // En realidad representa un vector
    double x,y;
    // CONSTRUCTORES
    punto(){x=0.0; y=0.0;} // Constructor por defecto
    punto(double _x, double _y){ // Constructor personalizado
        x=_x;
        y=_y;
    }
};

double modulo(punto p){
    return hypot(p.x,p.y);
}

double angulo(punto p,punto p1, punto p2){
    // Si es positivo o negativo
    double multipli;
    punto a(p1.x-p.x,p1.y-p.y);
    punto b(p2.x-p.x,p2.y-p.y);
    // Producto Cruz
    double cruz=(a.x*b.y-a.y*b.x);
    if(cruz<0) multipli=-1.00;
    else multipli=1.00;
    double ang = asin(fabs(cruz)/(modulo(a)*modulo(b)));
    return ang*multipli;
}

double distancia(punto a, punto b){
    return hypot(a.x-b.x,a.y-b.y);
}


bool dentroPoligono(punto p, vector<punto>poli){
    if(poli.size()<=2) return false;
    // Si esta en el borde
    int cp = poli.size();
    for(int i=0;i<poli.size();i++){
        if(fabs(distancia(p,poli[i])+distancia(p,poli[(i+1)%cp])-distancia(poli[i],poli[(i+1)%cp]))<=eps){
            //cout<<"BORDE"<<endl;
            return true; // Esta en el borde
        }
    }
    double sum=0.00;
    for(int i=0;i<poli.size();i++){
        sum+=(angulo(p,poli[i],poli[(i+1)%cp]));
    }
    //cout<<"SUMA "<<sum<<endl;
    if(fabs(sum)>pi){
        //cout<<"DENTRO"<<endl;
        return true;
    }
    return false;
}


int main(){
    double cx,cy;
    vector<punto>poli;
    int num_points;
    // Pedimos el poligono
    cin>>num_points;
    for(int i=0;i<num_points;i++){ // Leemos los puntos
        cin>>cx>>cy;
        poli.push_back(punto(cx,cy)); // Agregamos el punto al poligono
    }
    // Pedir el punto a testear
    cin>>cx>>cy;
    punto p(cx,cy);
    if(dentroPoligono(p,poli)) cout<<"T"<<endl;
    else cout<<"F"<<endl;
    return 0;
}