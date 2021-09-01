#include "ricehub.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int besthub(int R, int L, int X[], long long B)
{
  // Acumuladas
  vector<long long> acum(R+1);
  acum[0]=0;
  for(int i=1;i<=R;i++){
    acum[i]=acum[i-1]+(long long)X[i-1];
  }
  for(int s=R;s>=1;s--){ // Recorre los tamaños
    for(int i=0;i<=R-s;i++){ // Generamos el rango
      int a = i;
      int b = i+s-1;
      int m = (a+b)/2;
      long long aux_a = (long long)(m-a);
      long long aux_b = (long long)(b-m);
      long long rm = (long long) X[m];
      long long sum = ((aux_a - aux_b) * rm) - (acum[m]-acum[a]) + (acum[b+1]-acum[m+1]);
      if(sum<=B){
        return s;
      }
    }

  }
  return 1;
}
