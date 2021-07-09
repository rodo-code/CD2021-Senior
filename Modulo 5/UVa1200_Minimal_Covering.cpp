#include <iostream>
#include <cstdio>// scanf y printf
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int cp;
    string linea;
    cin>>cp;
    while(cp--){
        vector< pair< int,int > > seg;
        vector< int > pos;
        int m,l,r;
        cin>>m;
        cout<<"m="<<m<<endl;
        while(cin>>l>>r and !(l==0 and r==0)){
            seg.push_back(make_pair(l,r));
        }
        sort(seg.begin(),seg.end());
        int pa=0;
        int i=0;
        int maxr=-1;
        int posmaxr=0;
        while(i<seg.size()){
            if(pa>=m) break; // Ver si ya cubrimos el rango
            if(seg[i].first<=pa and pa<=seg[i].second){// Vemos si esta en el  rango
                cout<<"Entre"<<endl;
                if(seg[i].second > maxr){ // Ver el mayor
                    maxr=seg[i].second;
                    posmaxr=i;
                }
                i++;
            }
            else{
                cout<<"Primero en no rango"<<endl;
                pa=maxr;
                pos.push_back(posmaxr); // Que rango he escogido
                maxr=-1;
                posmaxr=0;
            }
        }
        if(pa>=m){
            cout<<pos.size()<<endl;
            for(int i=0;i<pos.size();i++){
                cout<<seg[pos[i]].first<<" "<<seg[pos[i]].second<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}