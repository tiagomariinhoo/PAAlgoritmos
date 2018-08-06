#include <bits/stdc++.h>
using namespace std;
#define MAX 500
#define DEBUG if(0)

int n,valor[MAX], peso[MAX], tab[MAX][MAX];

int knapsack(int obj, int aguenta){
	cout << "Obj : "<< obj<< endl << "Aguenta : " << aguenta << endl;
	cout << "Peso obj : " << peso[obj] << " Valor : " << valor[obj] << endl;

	if(tab[obj][aguenta]>=0){
		cout << "Primeiro if : " << endl;
		cout << "tab obj aguenta : " << tab[obj][aguenta] << endl;
		return tab[obj][aguenta];
	}

	if(obj==n or !aguenta){
		cout << "Segundo if : " << endl;
		cout << "Tab obj aguenta = 0;" << endl;
		return tab[obj][aguenta]=0;
	}
	int nao_coloca=knapsack(obj+1,aguenta);

	if(peso[obj]<=aguenta){
		cout << "Terceiro if : " << endl;
		cout << "peso obj <=  aguenta" << peso[obj] << " / " << aguenta << endl;
		int coloca=valor[obj]+knapsack(obj+1, aguenta-peso[obj]);
		cout << "Coloca : " << coloca << " / " << "Nao coloca : " << nao_coloca << endl;
		return tab[obj][aguenta]=max(coloca, nao_coloca);
	}

	cout << "Nao entrou em if : " << endl;
	cout << "Tab obj aguenta : " << tab[obj][aguenta] << endl << "Nao coloca : " << nao_coloca <<endl;
	return tab[obj][aguenta]=nao_coloca;

} 


int main (){
  
  int total,maximo;
  
  for(int i=0;i<MAX;i++)
  	for(int j=0;j<MAX;j++)
  		tab[i][j]=-1;
  
  cin >> maximo >> n;

  	for(int i=0;i<n;i++){
  		cin >> peso[i] >> valor[i];
  	}

  	total = knapsack(0,maximo);
  	cout << "Total : " << total << endl;





	return 0;
}