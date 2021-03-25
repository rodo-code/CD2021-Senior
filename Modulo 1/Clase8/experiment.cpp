#include <bits/stdc++.h> 
#include <chrono> 

using namespace std;

int main(){
	ifstream entrada("names.txt");
	string nombre;
	set <string> conj;
	unordered_set <string> conj_des;

	while(entrada>>nombre){
		conj_des.insert(nombre);
	}

	clock_t start, end;
	start = clock(); 
	ios_base::sync_with_stdio(false); 
	// CODIGO 1
	// Leer de un archivo
	while(entrada>>nombre){
		conj_des.find(nombre);
	}
	end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC); 
    cout << "Tiempo de obtener conj 1 : " << fixed  
         << time_taken << setprecision(5); 
    cout << " sec " << endl; 
    /*
	 */
	// FIN CODIGO 1
	
}