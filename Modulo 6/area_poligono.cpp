#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

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
    int num_points;
    cin>>num_points;
    for(int i=0;i<num_points;i++){ // Leemos los puntos
        double cx,cy;
        cin>>cx>>cy;
        P.push_back(punto(cx,cy)); // Agregamos el punto al poligono
    }
    double acum=0;
    int cp=P.size();
    for(int i=0;i<cp;i++){
        acum=acum+(P[i].x*P[(i+1)%cp].y)-(P[i].y*P[(i+1)%cp].x);
    }
    double area = 0.50*fabs(acum);
    cout<<area<<endl;
}