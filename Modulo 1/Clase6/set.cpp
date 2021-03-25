#include <iostream>
#include <set> // Libreria para usar conjuntos
using namespace std;

int main(){
	set <int> conj; // conjunto que ordenara en orden creciente
	set <int, greater<int> > conj_dec; // conjunto que ordenara en orden decreciente

	conj.insert(4); // inserta el elemento 4
	conj.insert(7); // inserta el elemento 7
	conj.insert(1); // inserta el elemento 1
	conj.insert(10); // inserta el elemento 10

	cout<<conj.count(7)<<endl; // imprira 1 ya que el 7 aparece una vez en el set

	if(conj.find(3)!=conj.end()){ // .find() devuelve un iterador apuntando al elemento
		cout<<"3 esta en el conjunto"<<endl;
	}
	else{
		// si no encuentra el elemento .find() devuelve un iterador a .end()
		cout<<"3 no esta en el conjunto"<<endl;
	}

	cout<<*(conj.lower_bound(3))<<endl; // imprimira 4 ya que es el primer elemento no menor que 6
	cout<<*(conj.lower_bound(7))<<endl; // imprimira 7 ya que es el primer elemento no menor que 7
	cout<<*(conj.upper_bound(1))<<endl; // imprimira 4 ya que es el primer elemento mayor que 2
	cout<<*(conj.upper_bound(4))<<endl; // imprimira 7 ya que es el primer elemento mayor que 4	
	conj.erase(1); // elimina el elemento 1 del conjunto

	cout<<conj.size()<<endl; // imprimira 3 ya que es el tamanio del set

	if(conj.empty()){ // .empty() nos indica si el set esta o no vacio
		//True
		cout<<"El conjunto esta vacio"<<endl;
	}
	else{
		//False
		cout<<"El conjunto NO esta vacio"<<endl;
	}

	// Recorrido Tradicional
	set<int>::iterator it; // Creacion del iterador
	for(it=conj.begin();it!=conj.end();it++){
		cout<<*it<<" "; // Acceso al elemento dentro del iterador
	}
	cout<<endl;

	// RECORRIDO en C++ 11
	for(auto elemento: conj){
		cout<<elemento<<" ";
	}
	cout<<endl;
	
	conj.clear(); // elimina todo el contenido del conjunto
	return 0;
}