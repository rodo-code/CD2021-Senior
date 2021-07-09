#include <iostream>

using namespace std;

void merge(int arr[],int l1,int r1,int l2,int r2){
    // cout<<"Merge "<<l1<<","<<r1<<","<<l2<<","<<r2<<endl;
    int t1 = r1-l1+1;
    int t2 = r2-l2+1;

    int L[t1];
    int R[t2];

    int j=0;
    for(int i=l1;i<=r1;i++){
        L[j]=arr[i];
        j++;
    }

    j=0;
    for(int i=l2;i<=r2;i++){
        R[j]=arr[i];
        j++;
    }
    /*
    cout<<"L= ";
    for(int i=0;i<t1;i++){
        cout<<L[i]<<" ";
    }
    cout<<endl;

    cout<<"R= ";
    for(int i=0;i<t2;i++){
        cout<<R[i]<<" ";
    }
    cout<<endl; */

    int p1=0;
    int p2=0;
    j=l1;
    while(p1<t1 and p2<t2){
        if(L[p1]<R[p2]){
            arr[j]=L[p1];
            p1++;
        }
        else{
            arr[j]=R[p2];
            p2++;
        }
        j++;
    }

    if(p1==t1){ // p1 se salio del rango del arreglo L
        for(int i=p2;i<t2;i++){
            arr[j]=R[i];
            j++;
        }
    }
    else{ // p2 se salio del rango del arreglo R
        for(int i=p1;i<t1;i++){
            arr[j]=L[i];
            j++;
        }
    }
    /*
    cout<<"arr= ";
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;*/
}

void sort(int arr[],int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    sort(arr,l,mid);
    sort(arr,mid+1,r);
    merge(arr,l,mid,mid+1,r);
}

int main(){
    int N=8;
    int arr[N] = {3,-1,7,4,1,0,9,5};
    sort(arr,0,N-1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}