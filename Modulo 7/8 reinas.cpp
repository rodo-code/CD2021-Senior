#include <bits/stdc++.h>

using namespace std;

int fila[8], fobj, cobj;
int cont = 0;

bool puedo_poner(int f,int c){
    for(int i=0;i<c;i++){
        if(fila[i]==f or abs(fila[i]-f)==abs(i-c)){
            return false;
        }
    }
    return true;
}

void backtrack(int col){
    if(col==8 and fila[cobj]==fobj){
        // Solucion encontrada
        /*cout<<"Solucion Encontrada"<<endl;
        for(int i=0;i<8;i++){
            cout<<"Reina en la fila "<<fila[i]+1<<" columna "<<i+1<<endl;
        }
        return;*/
        cont++;
        return;
    }
    for(int fil=0;fil<8;fil++){ // Recorre todas las opciones
        if(col==cobj and fil!=fobj) continue; // No debe hacer nada porque estaria mal
        if(puedo_poner(fil,col)){
            fila[col]=fil;
            backtrack(col+1);
        }
    }
}

void backtrack_final(int col){
    if(col==8){
        //Solucion encontrada
        cout<<"Solucion Encontrada"<<endl;
        for(int i=0;i<8;i++){
            cout<<"Reina en la fila "<<fila[i]+1<<" columna "<<i+1<<endl;
        }
        cont++;
        return;
    }
    for(int fil=0;fil<8;fil++){ // Recorre todas las opciones
        if(puedo_poner(fil,col)){
            fila[col]=fil;
            backtrack_final(col+1);
        }
    }
}

int main(){
   /*int matriz[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            //cin>>fobj>>cobj;
            cont=0;
            fobj=i;
            cobj=j;
            memset(fila, 0, sizeof fila);
            backtrack(0);
            matriz[i][j]=cont;
            cout<<matriz[i][j]<< " ";
        }
        cout<<endl;
    }*/
    memset(fila, 0, sizeof fila);
    backtrack_final(0);
    cout<<cont<<endl;
    return 0;
}