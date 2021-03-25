#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<int>q_max; // Cola de Prioridad (Max-Heap)
	q_max.push(7); // añade 7 a la cola de prioridad
	q_max.push(14); // añade 14 a la cola de prioridad
	q_max.push(1); // añade 1 a la cola de prioridad
	cout<<q_max.top()<<endl; // Imprimira 14 pues es el elemento mas grande
	q_max.pop(); // Quita el elemento mas grande
	cout<<q_max.top()<<endl; // Imprimira 7 pues ahora es el elemento mas grande

	priority_queue <int, vector<int>, greater<int> > q_min; // Cola de Prioridad (Min-Heap)
	q_min.push(7);
	q_min.push(14);
	q_min.push(1);
	cout<<q_min.top()<<endl; // Imprimira 1 pues es el elemento mas pequeño

	cout<<q_min.size()<<endl; // Imprimira 3 pues q_min tiene 3 elementos

	if(q_min.empty()){ // .empty() nos dice si la cola esta vacia
		//True
		cout<<"La cola de prioridad esta vacia"<<endl;
	}
	else{
		//False
		cout<<"La cola de prioridad NO esta vacia"<<endl;
	}

	//RECORRIDO
	cout<<"La cola de prioridad contenia a:"<<endl;
	while(!q_min.empty()){
		cout<<q_min.top()<<" ";
		q_min.pop();
	}
	cout<<endl;
	return 0;
}