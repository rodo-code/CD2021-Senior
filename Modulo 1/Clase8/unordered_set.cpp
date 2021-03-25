#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
	unordered_set<int>conj_desord;
	conj_desord.insert(5);
	conj_desord.insert(100);
	conj_desord.insert(8);
	conj_desord.insert(7);

	for(auto element: conj_desord){
		cout<<element<<" ";
	}
	cout<<endl;
}