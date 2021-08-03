#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define pi acos(-1)

struct punto{ // En realidad representa un vector
    double x,y;
    // CONSTRUCTORES
    punto(){x=0.0; y=0.0;} // Constructor por defecto
    punto(double _x, double _y){ // Constructor personalizado
        x=_x;
        y=_y;
    }
};

int main(){
    // Un poligono es un conjunto de puntos
    vector<punto>P;
    int num_points, num_poli;
    while(cin>>num_poli and num_poli!=0){
        double r,t;
        double cx,cy;
        double cxi,cyi;
        double vol_total=0;
        while(num_poli--){
            P.clear();
            cin>>t;
            cin>>cxi>>cyi;
            P.push_back(punto(cxi,cyi));
            while(cin>>cx>>cy and (cx!=cxi or cy!=cyi)){ // Leemos los puntos
                P.push_back(punto(cx,cy)); // Agregamos el punto al poligono
            }
            double acum=0;
            int cp=P.size();
            for(int i=0;i<cp;i++){
                acum=acum+(P[i].x*P[(i+1)%cp].y)-(P[i].y*P[(i+1)%cp].x);
            }
            double area = 0.50*fabs(acum);
            double volum = area * t;
            vol_total += volum;
        }
        cin>>r>>t;
        double vol_tapa = t*(r*r*pi);
        int num_tapas = vol_total / vol_tapa;
        //cout<<"Vol Total "<<vol_total<<endl;
        //cout<<"Vol Tapa "<< vol_tapa<<endl;
        cout<<num_tapas<<endl;

        /*
        
        cout<<area<<endl;*/
    }
    
}