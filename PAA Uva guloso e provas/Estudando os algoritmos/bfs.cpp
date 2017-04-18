#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(1)
#define MAX 202000

int n,m;
int componente[MAX];
vector<int> vizinhos [MAX];

/*void dfs(int x){
	cout << "Int x : " << x << endl;
	for(int i=0;i<(int)lista[x].size();i++){
		int v = lista[x][i];
		cout << "Lista x i ou v: " << lista[x][i] << endl;
			if(componente[v]==-1){

				componente[v] = componente[x];
				cout << "Componente v : " << componente[v] << endl;
				cout << "Componente x : " << componente[x] << endl;
				dfs(v);
			}
	}

}*/

void BFS(int x){
	cout << "Int x : " << x << endl;
	queue<int> fila;
	fila.push(x); // fila da nossa BFS
	
	componente[x] = x; // colocamos o valor adequado aqui
	
	int atual = 0; // atual posição que estamos na fila
	
	while(!fila.empty()){ // Enquanto a fila não for vazia
		cout << "Fila top : " << fila.front() << endl;
		// vamos trabalhar com o primeiro da fila
		int v = fila.front();
		fila.pop(); // para movermos o elemento da fila
		
		for(int i = 0;i < (int)vizinhos[v].size();i++){
			
			int u = vizinhos[v][i];
			
			if(componente[u] == -1){
				
				// se u ainda não tiver sido visitado, o acrescentamos a fila
				componente[u] = componente[v];
				fila.push(u);
			}
		}
	}
}



int main (){
	cin >> n >> m;

	for(int i=1;i<=n;i++) componente[i]=-1;
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

	return 0;
}
