#include <iostream>
#include <cstdio> // para printf y scanf
using namespace std;

int main(){
	int n,k,num;
	int cont=0;
	//cin>>n>>k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){ // ciclo de n repeticiones
		//cin>>num;
		scanf("%d",&num);
		if(num%k==0){ // condicion de la divisibilidad
			cont++;
		}
	}
	printf("%d\n",cont);
	//cout<<cont<<endl;
	return 0;
}