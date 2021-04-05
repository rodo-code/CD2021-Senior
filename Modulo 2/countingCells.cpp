#include <iostream>

using namespace std;

int cant_col,cant_fil;
char mapa[30][30];
int tam_mancha;

int cf[8] = {-1,-1,0,1,1,1,0,-1}; // Cambio fila
int cc[8] = {0,1,1,1,0,-1,-1,-1}; // Cambio columna

void flood_fill(int f,int c){
	mapa[f][c]='0';
	tam_mancha++;
	for(int i=0;i<8;i++){
		int nf = f+cf[i];
		int nc = c+cc[i];
		if(nf>=0 and nf<cant_fil and nc>=0 and nc<cant_col and mapa[nf][nc]=='1'){ // Es una conexion valida y ademas no esta visitado
			flood_fill(nf,nc);
		}
	}
}

int main(){
	int cp;
	string linea;
	cin>>cp;
	cin.ignore();
	getline(cin,linea);
	for(int i=1;i<=cp;i++){
		int tam_mancha_max=0;
		cant_fil=0;
		while(getline(cin,linea) and linea.size()!=0){
			cant_col=linea.size();
			for(int j=0;j<cant_col;j++){
				mapa[cant_fil][j]=linea[j];
			}
			cant_fil++;
		}
		for(int j=0;j<cant_fil;j++){
			for(int k=0;k<cant_col;k++){
				if(mapa[j][k]=='1'){// Hay una mancha ahi
					//cout<<j<<","<<k<<endl;
					tam_mancha=0;
					flood_fill(j,k);
					//cout<<tam_mancha<<endl;
					tam_mancha_max=max(tam_mancha_max,tam_mancha);
				}
			}
		}
		cout<<tam_mancha_max<<endl;
		if(i<cp){
			cout<<endl;
		}		
	}
	return 0;
}