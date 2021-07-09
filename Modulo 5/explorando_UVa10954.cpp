#include <iostream>
#include <algorithm> // Para usar next_permutation
#include <vector>
using namespace std;

vector<int> v = {1,2,3,4,5,6};

int cost(){
    int cost = v[0],cost_total = 0;
    for(int i=0;i<v.size()-1;i++){
        cost = cost+v[i+1];
        cost_total += cost;
    }
    return cost_total;
}

int main(){
    int min_cost = 1e9;
    do{
        min_cost=min(min_cost,cost());
    }while(next_permutation(v.begin(),v.end()));
    printf("El costo minimo es %d\n",min_cost);
    return 0;
}