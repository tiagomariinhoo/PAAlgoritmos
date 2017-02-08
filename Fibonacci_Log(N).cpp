#include <bits/stdc++.h>
#define INF -1000000001
#define DEBUG cout << "AQUI" << endl;
using namespace std;

int matriz[2][2] = {1,1,1,0};
int matriz_aux[2][2] = {1,1,1,0};

void fib (){

}

void multiplicarMatriz(){
	
	int matriz_aux2[2][2];

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			matriz_aux2[i][j] = matriz[i][j];

		}
	}

	matriz[0][0] = (matriz_aux2[0][0]*matriz_aux[0][0]) + (matriz_aux2[0][1]*matriz_aux[1][0]);
	matriz[0][1] = (matriz_aux2[0][0]*matriz_aux[0][1]) + (matriz_aux2[0][1]*matriz_aux[1][1]);

	matriz[1][0] = (matriz_aux2[1][0]*matriz_aux[0][0]) + (matriz_aux2[1][1]*matriz_aux[1][0]);
	matriz[1][1] = (matriz_aux2[1][0]*matriz_aux[0][1]) + (matriz_aux2[1][1]*matriz_aux[1][1]);

}


int main(){ //Fibonacci Log n , usando multiplicação de matriz
	int x;

		cin >> x;

			for(int i=0;i<x;i++){
				multiplicarMatriz();
			}

		
			cout << "Fib de " << x << " eh : " << matriz[0][1] << endl;

	return 0;
}