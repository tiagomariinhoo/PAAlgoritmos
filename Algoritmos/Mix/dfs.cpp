#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(1)
#define MAX 202000

int n,m;
int componente[MAX];
vector<int> lista [MAX];

void dfs(int x){
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

}



int main (){
	cin >> n >> m;

	for(int i=1;i<=n;i++) componente[i]=-1;
	for(int i=1;i<=m;i++){
		int a,b;
			cin >> a >> b;

			lista[a].push_back(b);
			lista[b].push_back(a);
	}

	int numero_componentes = 0;

	for(int i=1;i<=n;i++){
		if(componente[i]==-1){

			numero_componentes++;
			componente[i] = numero_componentes;
			dfs(i);
		}

	}

	return 0;
}
