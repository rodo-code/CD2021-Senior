#include <iostream>

using namespace std;

int main(){
	int N;
	int maxi=-1;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
		maxi=max(maxi,arr[i]);
	}
	int cont=0;
	for(int i=0;i<N;i++){
		if(arr[i]!=maxi){
			cont++;
		}
	}
	cout<<cont<<endl;
	for(int i=0;i<N;i++){
		if(arr[i]!=maxi){
			cout<<arr[i]<<" ";
		}
	}
	cout<<endl;

	return 0;
}