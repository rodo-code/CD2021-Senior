// 42 puntos Subtask 1 y 2
#include "ricehub.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int besthub(int R, int L, int X[], long long B)
{
  for(int s=R;s>=1;s--){ // Recorre los tamaños
    for(int i=0;i<=R-s;i++){ // Generamos el rango
      int a = i;
      int b = i+s-1;
      int m = (a+b)/2;
      long long sum = 0LL;
      for(int j=i;j<i+s;j++){ // Recorremos el rango
        long long dif = abs(X[j]-X[m]);
        sum+=dif;
      }
      if(sum<=B){
        return s;
      }
    }

  }
  return 1;
}
