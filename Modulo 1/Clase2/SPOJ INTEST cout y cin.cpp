#include <iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n,k,num;
	int cont=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){ // ciclo de n repeticiones
		cin>>num;
		if(num%k==0){ // condicion de la divisibilidad
			cont++;
		}
	}
	cout<<cont<<endl;
	return 0;
}