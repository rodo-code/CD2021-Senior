#include <iostream>
#include <vector>

using namespace std;

vector< pair<int,int> > arbol;
string preorder,inorder;

int posicion(char letra,string cadena){
    for(int i=0;i<cadena.size();i++){
        if(cadena[i]==letra) return i;
    }
    return -1;
}

int crear_arbol(string pre, string in){
    if(pre.size()==0 or in.size()==0) return -1;

    int pos_raiz = posicion(pre[0],preorder);
    
    if(pre.size()==1 and in.size()==1){
        arbol[pos_raiz]=make_pair(-1,-1);
        return pos_raiz;
    }

    int pos_raiz_in = posicion(pre[0],in);
    string nuevo_pre_izq,nuevo_in_izq,nuevo_pre_der,nuevo_in_der;
    if(pos_raiz_in > -1){
        nuevo_pre_izq = pre.substr(1,pos_raiz_in);
        nuevo_in_izq = in.substr(0,pos_raiz_in);
        nuevo_pre_der = pre.substr(1+pos_raiz_in);
        nuevo_in_der = in.substr(pos_raiz_in+1);
    }
    /*else{
        cout<<"Caso Raro:"<<endl;
        cout<<"pre="<<pre<<endl;
        cout<<"in="<<in<<endl;
    }
    cout<<"Raiz "<<pre[0]<<endl;
    cout<<"nuevo_pre_izq="<<nuevo_pre_izq<<endl;
    cout<<"nuevo_in_izq="<<nuevo_in_izq<<endl;
    cout<<"nuevo_pre_der="<<nuevo_pre_der<<endl;
    cout<<"nuevo_in_der="<<nuevo_in_der<<endl;
    */
    //izquierda
    int izq = crear_arbol(nuevo_pre_izq, nuevo_in_izq);
    //derecha
    int der = crear_arbol(nuevo_pre_der,nuevo_in_der);
    arbol[pos_raiz]=make_pair(izq,der);
    return pos_raiz;
}

void postorder(int nodo){
    if(nodo==-1) return;
    int izq = arbol[nodo].first;
    int der = arbol[nodo].second;
    // Visitar Izquierda
    postorder(izq);
    // Visitar Derecha
    postorder(der);
    // Imprmir / Raiz
    cout<<preorder[nodo];
}

void preorder_imp(int nodo){
    if(nodo==-1) return;
    int izq = arbol[nodo].first;
    int der = arbol[nodo].second;
    // Imprmir / Raiz
    cout<<preorder[nodo];
    // Visitar Izquierda
    postorder(izq);
    // Visitar Derecha
    postorder(der);
}

void inorder_imp(int nodo){
    if(nodo==-1) return;
    int izq = arbol[nodo].first;
    int der = arbol[nodo].second;
    // Visitar Izquierda
    postorder(izq);
    // Imprmir / Raiz
    cout<<preorder[nodo];
    // Visitar Derecha
    postorder(der);
}

int main(){
    
    while(cin>>preorder>>inorder){
        arbol.assign(preorder.size(),make_pair(-1,-1));
        crear_arbol(preorder,inorder);
        cout<<"PREORDER: ";
        preorder_imp(0);
        cout<<endl;
        cout<<"INORDER: ";
        inorder_imp(0);
        cout<<endl;
        cout<<"POSTORDER: ";
        postorder(0);
        cout<<endl;
    }

}