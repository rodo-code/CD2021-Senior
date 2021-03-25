#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
	unordered_map<string,int>map_desord;
	map_desord["Junio"]=30;
	map_desord["Julio"]=31;
	map_desord["Noviembre"]=30;
	map_desord["Febrero"]=28;
	map_desord["Diciembre"]=31;
	
	for(auto element: map_desord){
		cout<<element.first<<" => "<<element.second<<endl;
	}
}