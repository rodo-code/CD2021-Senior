#include <iostream>

using namespace std;

int suma1(int k){
	k=k+1;
	return k;
}

int main(){
	int x=4;
	int nueva_x=suma1(x);
	cout<<"nueva_x = "<<nueva_x<<endl;
	cout<<"x = "<<x<<endl;
	return 0;
}