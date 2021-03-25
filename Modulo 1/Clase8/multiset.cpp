#include <iostream>
#include <set>
using namespace std;

int main(){
	// multiset soporta repetidos
	multiset<int> multi; // Creamos el multise
	multi.insert(5);
	multi.insert(1);
	multi.insert(2);
	multi.insert(1);
	multi.insert(9);
	multi.insert(5);
	for(auto element: multi){
		cout<<element<<" ";
	}
	cout<<endl;
	return 0;	
}