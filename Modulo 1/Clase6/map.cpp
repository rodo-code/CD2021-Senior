#include <iostream>
#include <map> // Libreria para usar mapas
using namespace std;

int main(){
	map <string,int> mapa; // Crea un mapa de llave tipo string y valor int
	mapa["enero"]=31; // inserta la llave enero con el valor 31
	mapa["febrero"]=28; // inserta la llave febrero con el valor 28
	mapa.insert(make_pair("junio",30)); // inserta la llave junio con el valor 30
	mapa.insert(make_pair("septiembre",30)); // inserta la llave septiembre con el valor 30

	cout<<mapa.count("enero")<<endl; // imprira 1 ya que la llave enero aparece una vez en el mppa

	if(mapa.find("mayo")!=mapa.end()){ // .find() devuelve un iterador apuntando a la llave indicada
		cout<<"mayo esta en el mapa"<<endl;
	}
	else{
		// si no encuentra la llave .find() devuelve un iterador a .end()
		cout<<"mayo no esta en el mapa"<<endl;
	}

	cout<<(mapa.lower_bound("mayo"))->first<<endl; // imprimira septiembre
	cout<<(mapa.lower_bound("septiembre"))->first<<endl; // imprimira septiembre
	cout<<(mapa.upper_bound("abril"))->first<<endl; // imprimira enero
	cout<<(mapa.upper_bound("febrero"))->first<<endl; // imprimira junio	
	
	mapa.erase("junio"); // elimina el elemento con llave "junio" del mapa

	cout<<mapa.size()<<endl; // imprimira 3 ya que es el tamanio del mapa

	if(mapa.empty()){ // .empty() nos indica si el mapa esta o no vacio
		//True
		cout<<"El mapa esta vacio"<<endl;
	}
	else{
		//False
		cout<<"El mapa NO esta vacio"<<endl;
	}

	// Recorrido Tradicional
	map<string,int>::iterator it; // Creacion del iterador
	for(it=mapa.begin();it!=mapa.end();it++){
		cout<<it->first<<" "<<it->second<<endl; // Acceso al elemento dentro del iterador
	}

	// RECORRIDO en C++ 11
	for(auto elemento: mapa){
		cout<<elemento.first<<" "<<elemento.second<<endl;
	}
	mapa.clear(); // elimina todo el contenido del mapa
	return 0;
}