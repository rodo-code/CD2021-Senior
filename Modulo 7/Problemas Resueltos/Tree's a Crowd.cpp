#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct punto{
    double x,y,z;
    punto(){x=0.0; y=0.0; z=0.0;} // Constructor por defecto
    punto(double _x, double _y, double _z){ // Constructor personalizado
        x=_x;
        y=_y;
        z=_z;
    }
};

double dist(punto a, punto b){
    return hypot(hypot(a.x-b.x,a.y-b.y),a.z-b.z);
}

int main(){
    vector<punto> v;
    vector<int> res(10,0);
    double x,y,z;
    while(cin>>x>>y>>z and (x+y+z)!=0){// (x+y+z)!=0 solo funciona en positivos
        v.push_back(punto(x,y,z));
    }
    for(int i=0;i<v.size();i++){
        double min_dist=100000000;
        for(int j=0;j<v.size();j++){
            if(i!=j){
                double d = dist(v[i],v[j]);
                min_dist = min(d,min_dist);
            }
        }
        //cout<<min_dist<<endl;
        int clase = floor(min_dist);
        if(clase<10)
            res[clase]++;
    }
    for(int i=0;i<res.size();i++){
        printf("%4d",res[i]);
    }
    cout<<endl;
    return 0;
}