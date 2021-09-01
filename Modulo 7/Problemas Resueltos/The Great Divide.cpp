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

bool ccw(punto a, punto b, punto c){
    punto u(b.x-a.x,b.y-a.y);
    punto v(c.x-a.x,c.y-a.y);
    double cruz = (u.x*v.y) - (v.x*u.y);
    return (cruz>0.00);
}

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
    for(int i=0;i<poli.size()-1;i++){
        if(fabs(distancia(p,poli[i])+distancia(p,poli[i+1])-distancia(poli[i],poli[i+1]))<=eps){
            //cout<<"BORDE"<<endl;
            return true; // Esta en el borde
        }
    }
    double sum=0.00;
    for(int i=0;i<poli.size()-1;i++){
        sum+=(angulo(p,poli[i],poli[i+1]));
    }
    //cout<<"SUMA "<<sum<<endl;
    if(fabs(sum)>pi){
        //cout<<"DENTRO"<<endl;
        return true;
    }
    return false;
}

vector<punto> CH_Andrew(vector<punto> &Pts) {    // overall O(n log n)
  int n = Pts.size(), k = 0;
  vector<punto> H(2*n);
  sort(Pts.begin(), Pts.end());                  // sort the puntos by x/y
  for (int i = 0; i < n; i++) {                  // build lower hull
    while ((k >= 2) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k] = Pts[i];
    k++;
  }
  for (int i = n-2, t = k+1; i >= 0; i--) {       // build upper hull
    while ((k >= t) && !ccw(H[k-2], H[k-1], Pts[i])) --k;
    H[k] = Pts[i];
    k++;
  }
  H.resize(k);
  return H;
}

int main(){
    int M,C;
    while(cin>>M>>C and M+C!=0){
        vector<punto> pm;
        vector<punto> pc;
        for(int i=0;i<M;i++){
            double x,y;
            cin>>x>>y;
            pm.push_back(punto(x,y));
        }
        for(int i=0;i<C;i++){
            double x,y;
            cin>>x>>y;
            pc.push_back(punto(x,y));
        }

        vector<punto> chm = CH_Andrew(pm);
        vector<punto> chc = CH_Andrew(pc);
        bool res = true;
        // Si algun punto del Convex Hull de Majestix esta en el CH de Cleverdix
        for(int i=0;i<chm.size() and res;i++){
            if(dentroPoligono(chm[i],chc)){
                res=false;
            }
        }
        // Si algun punto del Convex Hull de Cleverdix esta en el CH de Majestix
        for(int i=0;i<chc.size() and res;i++){
            if(dentroPoligono(chc[i],chm)){
                res=false;
            }
        }
        if(res) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}