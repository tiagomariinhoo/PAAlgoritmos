#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(1)
#define MAX 202000

int n,m;
int componente[MAX];
vector<int> lista [MAX];
int suspeitos=0;

void dfs(int x){
	for(int i=0;i<(int)lista[x].size();i++){
		int v = lista[x][i];
			if(componente[v]==-1){

				componente[v] = componente[x];
				dfs(v);
			}
	}

}

void init(){
	for(int i=0;i<30001;i++){
		componente[i]=-1;
		lista[i].clear();
		suspeitos=0;
	}
}

int main (){

	while(cin>>n>>m, n+m){

	init();


	for(int i=0;i<m;i++){
		int tam;
			cin >> tam;
				vector<int> grupo;
				for(int j=0;j<tam;j++){
					int element;
					cin >> element;
					grupo.push_back(element);
				}

				sort(grupo.begin(),grupo.end());

						for(int k=1;k<grupo.size();k++){
							lista[grupo[0]].push_back(grupo[k]);
							lista[grupo[k]].push_back(grupo[0]);
						}
	}

	for(int i=0;i<n;i++) componente[i]=-1;

	int numero_componentes = 0;

	componente[0]=1;
	dfs(0);
	for(int i=0;i<n;i++){
		if(componente[i]!=-1) {
			suspeitos++;
		}
	}


	cout << suspeitos << endl;
	}


	return 0;
}
