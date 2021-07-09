#include <iostream>
#include <vector>
#include <algorithm> // Usar sort, lower_bound, binary_search
using namespace std;

int main(){
    vector<int>v{7,20,33,40,78,117,37,3};;

    for(auto elem: v){
        cout<<elem<<" ";
    }
    cout<<endl;
    // Paso 1 Ordenar
    sort(v.begin(),v.end());
    for(auto elem: v){
        cout<<elem<<" ";
    }
    cout<<endl;

    // binary_search
    if(binary_search(v.begin(),v.end(),21)){
        cout<<"21 esta en el vector"<<endl;
    }
    else{
        cout<<"21 NO esta en el vector"<<endl;
    }
    // lower_bound
    cout<<"LOWER_BOUND"<<endl;
    vector<int>::iterator it = lower_bound(v.begin(),v.end(),21);
    if(*it==21){
        cout<<"21 esta en el vector"<<endl;
        cout<<"21 esta en la posicion "<<(it-v.begin())<<endl; 
    }
    else{
        cout<<"21 NO esta en el vector"<<endl;
        cout<<"Lower bound apunto a la posicion "<<(it-v.begin())<<endl;
    }
    return 0;
}