/*
	Pontes Conectadas Grafos
	Família de Troia OBI
	2013

	Achando grafos separados, cada numero_componente é um grafo diferente
*/

#include <bits/stdc++.h>
using namespace std;

#define DEBUG if(0)
#define MAX 110
#define MAXN 120
#define MIN -2000000
#define INF 0x3f3f3f3f
#define s(n) scanf("%d", &n)
#define ss(a,b) scanf("%d %d",&a,&b)
#define pb push_back
#define mp make_pair
#define sz(a) int(a.size())
#define lli long long int
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int, ii > iii;
#define F first
#define S second
//g++ a.cpp -o a.exe && a.exe < in
int n,m;
int componente[MAXN];
vi lista[MAXN];
vi ponte;

void dfs(int x){
	cout << "X dfs : " << x << endl;

	for(int i = 0; i < (int)lista[x].size();i++ ){
		int v = lista[x][i];
		cout << "V : " << v << endl;

		if(componente[v] == -1){ //Checagem de que foi visitado
			cout << "Componente v : " << componente[v] << endl << "Componente x : " << componente[x] << endl;
			componente[v] = componente[x];
			dfs(v);
		}
		
	}
	ponte.pb(x);
}

int main (){
	cin >> n >> m;

	for(int i = 1; i <= n; i++) componente[i] = -1; //Inicializa as componentes

	for(int i = 1; i <= m ;i++){
		int a,b;
		ss(a,b);

		lista[a].pb(b);
		lista[b].pb(a);
	}

	int numero_componentes = 0;

	for(int i = 1; i <= n ;i++){
		
		if(componente[i] == -1){
			cout << "Componente i : " << i << endl;
			numero_componentes++;
			componente[i] = numero_componentes;

			dfs(i);
		}
	
	}

	cout << "---- Componentes : -----" << endl;
	for(int i=1 ; i <= n ; i++){
		cout << componente[i] << endl;
	}
	cout << "------------- Ponte : -----" << endl;
	for(int i=0;i<ponte.size();i++){
		cout << ponte[i] << endl;
	}
	cout << "--------------" << endl;


	cout << numero_componentes << endl;
 
	return 0;
}