#include <iostream>
#include <vector>
#include <sstream> // Para utilizar istringstream
using namespace std;

int main(){
    vector<string> v;
    string s = "Juan,Pedro,Maria,Pepe,Carlos,Ariel,Joaquin,Edwin,Rodolfo,Franco,Luis";
    string t;
    //Tecnica Extra
    istringstream in2(s);
    while(getline(in2,t,',')){
        cout<<t<<endl;
    }
    //Tecnica 1
    string aux="";
    for(int i=0;i<s.size();i++){
        if(s[i]!=',') aux=aux+s[i];
        else{ // Si llegamos a una coma
            v.push_back(aux);
            aux="";
        }
    }
    v.push_back(aux);
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    // Tecnica 2
    v.clear();
    for(int i=0;i<s.size();i++){
        if(s[i]==',') s[i]=' ';
    }
    istringstream in(s);
    while(in>>aux){
        v.push_back(aux);
    }
    for(auto x: v){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}