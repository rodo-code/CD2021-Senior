// Fenwick Tree para RSQ
#include <iostream>
#include <vector>

using namespace std;

#define LSOne(x) ((x) & -(x))

int N; // Tamaño de la lista de numeros
vector<int> v; // Guardará los números de la lista original
vector<int> ft; // Fenwick Tree

void construir(){
	ft.assign(N+1,0);
	for(int i=1;i<=N;i++){
		ft[i] += v[i]; // Ya que ft[i] siempre tiene al menos a i
		if(i+LSOne(i)<=N){
			ft[i+LSOne(i)] += ft[i]; // anianimos tambien al padre de i
		}
	}
}

int rsq(int i,int j){
	if(i==0 or j==0) return 0; // neutro
	if(i==1){
		int sum=0;
		while(j>0){
			sum+=ft[j];
			j-=LSOne(j);
		}
		return sum;
	}
	return rsq(1,j)-rsq(1,i-1);
}

void actualizar(int pos,int valor){
	while(pos<=N){
		ft[pos]+=valor;
		pos+=LSOne(pos);
	}
}

int main(){
	// Pedimos la lista de números
	cin>>N;
	v.assign(N+1,0); // Empezaremos a pedir desde el indice 1
	for(int i=1;i<=N;i++){
		cin>>v[i];
	}
	construir();
	cout<<"ft"<<endl;
	for(int i=0;i<ft.size();i++){
		cout<<ft[i]<<" ";
	}
	cout<<endl;
	cout<<"Inicial"<<endl;
	for(int i=1;i<=N;i++){
		cout<<i<<"->"<<rsq(i,i)<<endl;
	}
	cout<<rsq(1,6)<<endl;
	cout<<rsq(3,9)<<endl;
	cout<<rsq(7,10)<<endl;
	actualizar(4,3);
	cout<<"Luego de hacer actualizar(4,3)"<<endl;
	for(int i=1;i<=N;i++){
		cout<<i<<"->"<<rsq(i,i)<<endl;
	}
	cout<<endl;
}