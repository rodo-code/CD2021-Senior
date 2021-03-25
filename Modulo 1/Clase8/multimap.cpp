#include <iostream>
#include <map>
using namespace std;

int main(){
	// Soporta llaves repetidas
	multimap<string,int> mapa_multi; // multimapa
	mapa_multi.insert(make_pair("Rodolfo",13));
	mapa_multi.insert(make_pair("Rodolfo",21));
	mapa_multi.insert(make_pair("Ariel",16));
	for(auto element: mapa_multi){
		cout<<element.first<<" => "<<element.second<<endl;
	}
	return 0;	
}