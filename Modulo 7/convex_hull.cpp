#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define eps 1e-7

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

// Convex Hull
vector<punto> CH(vector<punto> Pts){
    vector<punto> P(Pts);   
    int n = (int)P.size();
    if (n <= 3) {                                  // point/line/triangle
        if (!(P[0] == P[n-1])) P.push_back(P[0]);    // corner case
        return P;                                    // the CH is P itself
    }
    // Encontrar el pivote
    int pos_pivot = -1;
    double miny = 1000000000.00, maxx = -1000000000.00;
    for(int i=0;i<n;i++){
        if(P[i].y<miny){
            miny = P[i].y;
            maxx = P[i].x;
            pos_pivot = i;
        }
        else{
            if(P[i].y == miny){
                if(P[i].x > maxx){
                    miny = P[i].y;
                    maxx = P[i].x;
                    pos_pivot = i;
                }
            }
        }
    }
    swap(P[0],P[pos_pivot]);
    /*
    int P0 = min_element(P.begin(), P.end())-P.begin();
    swap(P[0], P[P0]);*/
    // Ordenar por Sentido antihorario
    sort(P.begin()+1, P.end(), [&](punto a, punto b) {
        return ccw(P[0], a, b); // P[0] es el pivote
    });
    cout<<"++++++++++++++"<<endl;
    for(int i=0;i<P.size();i++){
        cout<<P[i].x<<" "<<P[i].y<<endl;
    }
    // Scaneo
    vector<punto> S;        
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    int i = 2;                                     // then, we check the rest
    while (i < n) {                                // n > 3, O(n)
        int j = (int)S.size()-1;
        if (ccw(S[j-1], S[j], P[i])){           // CCW turn
            S.push_back(P[i]); // accept this punto       
        }            
        else                                         // CW turn
            S.pop_back();                              // pop until a CCW turn
        i++;
    }
    return S; 
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
    double cx,cy;
    vector<punto>poli;
    int num_points;
    // Pedimos el poligono
    cin>>num_points;
    for(int i=0;i<num_points;i++){ // Leemos los puntos
        cin>>cx>>cy;
        poli.push_back(punto(cx,cy)); // Agregamos el punto al poligono
    }
    
    vector<punto> convex_hull = CH_Andrew(poli);
    cout<<"********"<<endl;
    for(int i=0;i<convex_hull.size();i++){
        cout<<convex_hull[i].x<<" "<<convex_hull[i].y<<endl;
    } 

    return 0;
}