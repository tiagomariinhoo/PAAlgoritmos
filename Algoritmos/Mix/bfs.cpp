#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define MAX 100001

int n,m;
int componente[MAX];
vector<int> vizinhos [MAX];

void BFS(int x){

	cout << "Int x : " << x << endl;

	queue<int> fila;
	fila.push(x);

	componente[x] = x;
	cout << "componente x : " << componente[x] << endl;

	int atual=0;

	while(!fila.empty()){
		int v = fila.front();
		cout << "Fila front : " << fila.front() << endl;
		fila.pop();

		for(int i=0;i<vizinhos[v].size();i++){
			int u = vizinhos[v][i];
			cout << "Int u : " << u << endl;
			cout << "Componente u : " << componente[u] << endl;

			if(componente[u] == -1){
				cout << "Componente u : " << componente[u] <<  endl;
				cout << "Componente v : " << componente[v] << endl;
				componente[u] = componente[v];
				fila.push(u);
				cout << "Fila front no componente u -1 : " << fila.front() << endl;
			}
		}
	}
}

int main (){

	cin >> n >>m;

	for (int i=1;i<=n;i++) componente[i]=-1;

	for(int i=1;i<=m;i++){
		int a,b;
			cin >> a >> b;

			vizinhos[a].push_back(b);
			vizinhos[b].push_back(a);
	}

	int numero_componentes = 0;

	for(int i=1;i<=n;i++){
		if(componente[i]==-1){
			numero_componentes++;

			componente[i] = numero_componentes;
			BFS(i);
		}
	}


}